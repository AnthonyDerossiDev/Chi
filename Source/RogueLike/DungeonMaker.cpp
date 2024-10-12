#include "DungeonMaker.h"
#include "Math/UnrealMathUtility.h"
#include "Engine/World.h"

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
}

void ADungeonMaker::SetExit()
{
}



