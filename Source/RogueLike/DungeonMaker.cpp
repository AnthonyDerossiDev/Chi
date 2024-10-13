#include "DungeonMaker.h"
#include "Math/UnrealMathUtility.h"
#include "Engine/World.h"
#include "Runtime/Core/Tests/Containers/TestUtils.h"

// Constructor
ADungeonMaker::ADungeonMaker()
{
    PrimaryActorTick.bCanEverTick = false;

    // Inicializar la matriz de mazmorras
    DungeonMap.SetNum(NumberOfRows);
    for (int32 i = 0; i < NumberOfRows; ++i)
    {
        DungeonMap[i].SetNum(NumberOfColumns);
    }
}

void ADungeonMaker::BeginPlay()
{
    Super::BeginPlay();
    GenerateDungeonMap();
    AddWidgetMap();
}

void ADungeonMaker::GenerateDungeonMap()
{
    // Se definen todas las salas como vacías
    for (int i = 0; i <  NumberOfRows; ++i)
    {
        for (int j = 0; j < NumberOfColumns; ++j)
        {
            DungeonMap[i][j] = E_RoomType::EMPTY;
        }
    }

    // Se define la entrada y la salida
    SetEntrance();
    SetExit();
    DrawConnectionRooms();
}

void ADungeonMaker::AddWidgetMap()
{
    if(!DungeonMapWidgetClass)
    {
        UE_LOG(LogTemp, Warning, TEXT("Clase de widget no definida"));
        return;
    }
    DungeonMapWidget = Cast<UDungeonMapWidget>(CreateWidget(GetWorld(), DungeonMapWidgetClass));
    if(!DungeonMapWidget)
    {
        UE_LOG(LogTemp, Warning, TEXT("Widget no creado"));
        return;
    }
    DungeonMapWidget->AddToViewport();
    DungeonMapWidget->UpdateMap(DungeonMap);
}

void ADungeonMaker::SetEntrance()
{
    TArray<FVector2D> PossibleLocations
    {
        FVector2D(0, 0),                                    // Esquina superior izquierda
        FVector2D(0, NumberOfColumns - 1),                  // Esquina superior derecha
        FVector2D(NumberOfRows-1, 0),                       // Esquina inferior izquierda
        FVector2D(NumberOfRows - 1, NumberOfColumns - 1),   // Esquina inferior derecha
        
        FVector2D(NumberOfRows/2, 0),                   // Parte izquierda central
        FVector2D(NumberOfRows/2, NumberOfColumns-1),   // Parte derecha central
        FVector2D(0, NumberOfColumns/2),                // Parte superior central
        FVector2D(NumberOfRows-1, NumberOfColumns/2),   // Parte inferior central
    };
    int32 RandomInt = FMath::RandRange(0, PossibleLocations.Num()-1);
    FVector2D NextLocation = PossibleLocations[RandomInt];
    DungeonMap[NextLocation.X][NextLocation.Y] = ENTRY;

    EntrancePosition = NextLocation;
}

void ADungeonMaker::SetExit()
{
    TArray<FVector2D> PossibleLocations
    {
        FVector2D(0, 0),                                    // Esquina superior izquierda
        FVector2D(0, NumberOfColumns - 1),                  // Esquina superior derecha
        FVector2D(NumberOfRows-1, 0),                       // Esquina inferior izquierda
        FVector2D(NumberOfRows - 1, NumberOfColumns - 1),   // Esquina inferior derecha
        
        FVector2D(NumberOfRows/2, 0),                   // Parte izquierda central
        FVector2D(NumberOfRows/2, NumberOfColumns-1),   // Parte derecha central
        FVector2D(0, NumberOfColumns/2),                // Parte superior central
        FVector2D(NumberOfRows-1, NumberOfColumns/2),   // Parte inferior central
    };
    
    FVector2D NextLocation;
    bool bHasFoundLocation = false;
    while (bHasFoundLocation == false)
    {
        const int32 RandomInt = FMath::RandRange(0, PossibleLocations.Num()-1);
        NextLocation = PossibleLocations[RandomInt];
        const int32 DistanceToEntrance = GetManhattanDistance(EntrancePosition, NextLocation);
        
        if(NextLocation != EntrancePosition)
        {
            bHasFoundLocation = true;
        }
    }
    
    // Si el código llega hasta aquí, es porque la posición de salida no coincide con la de entrada y además
    // las posiciones no coinciden.
    DungeonMap[NextLocation.X][NextLocation.Y] = EXIT;
    ExitPosition = NextLocation;
}

void ADungeonMaker::DrawConnectionRooms()
{
    // Posiciones de inicio y meta
    FVector2D CurrentLocation = EntrancePosition;
    FVector2D ExitLocation = ExitPosition;

    // Direcciones posibles: derecha (1, 0), izquierda (-1, 0), arriba (0, 1), abajo (0, -1)
    TArray<FVector2D> Directions = {
        FVector2D(1, 0),   // Derecha
        FVector2D(-1, 0),  // Izquierda
        FVector2D(0, 1),   // Arriba
        FVector2D(0, -1)   // Abajo
    };

    int32 CurrentAmountOfRooms = 1;  // Ya cuenta la entrada
    DungeonMap[CurrentLocation.X][CurrentLocation.Y] = ENTRY;  // Marca la entrada

    // Ciclo hasta que generes el número de salas deseadas o llegues a la salida
    while (CurrentAmountOfRooms < NumberOfRooms && CurrentLocation != ExitLocation)
    {
        // Baraja direcciones para dar más variabilidad en el movimiento
        Test::Shuffle(Directions);

        bool bFoundNextLocation = false;

        for (const FVector2D& Direction : Directions)
        {
            FVector2D NextLocation = CurrentLocation + Direction;

            // Verificar que la nueva posición esté dentro de los límites y sea válida
            if (IsLocationInBounds(NextLocation) && !IsLocationOccupied(NextLocation))
            {
                CurrentLocation = NextLocation;  // Avanza a la nueva posición
                DungeonMap[CurrentLocation.X][CurrentLocation.Y] = COMBAT;  // Marca la sala como COMBAT
                CurrentAmountOfRooms++;
                bFoundNextLocation = true;
                break;  // Sal del bucle de direcciones
            }
        }

        // Si no se encuentra una dirección válida, significa que estamos atrapados
        if (!bFoundNextLocation)
        {
            UE_LOG(LogTemp, Warning, TEXT("No valid move found!"));
            break;
        }
    }

    // Finalmente, marca la salida
    DungeonMap[ExitLocation.X][ExitLocation.Y] = EXIT;
}

bool ADungeonMaker::IsLocationOccupied(const FVector2D& Location)
{
    // Verifica que la ubicación esté dentro de los límites antes de proceder
    if (!IsLocationInBounds(Location))
    {
        return true;  // Si está fuera de los límites, la consideramos ocupada
    }

    // Comprueba si la posición en DungeonMap está ocupada (diferente de EMPTY)
    // Aquí asumimos que EMPTY representa una celda vacía
    return DungeonMap[Location.X][Location.Y] != EMPTY;
}


bool ADungeonMaker::IsLocationInBounds(FVector2D Location)
{
    // Comprobar si la coordenada X está dentro de los límites
    bool bXInBounds = Location.X >= 0 && Location.X < NumberOfColumns;

    // Comprobar si la coordenada Y está dentro de los límites
    bool bYInBounds = Location.Y >= 0 && Location.Y < NumberOfRows;

    // Si ambas coordenadas están en los límites, el vector está en la matriz
    return bXInBounds && bYInBounds;
}

int32 ADungeonMaker::GetManhattanDistance(const FVector2D& A, const FVector2D& B)
{
    const int32 X2 = B.X;
    const int32 Y2 = B.Y;
    const int32 X1 = A.X;
    const int32 Y1 = A.Y;

    int32 Distance = (X2-X1) + (Y2-Y1);
    return Distance;
}


