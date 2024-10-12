#include "DungeonMaker.h"
#include "Blueprint/UserWidget.h"
#include "Engine/Engine.h"
#include "Kismet/KismetMathLibrary.h" // Para generación aleatoria

// Constructor
ADungeonMaker::ADungeonMaker()
{
    // Inicializar la matriz
    DungeonMap.SetNum(NumberOfRows);
    for (int32 i = 0; i < NumberOfRows; ++i)
    {
        DungeonMap[i].SetNum(NumberOfColumns);
        for (int32 j = 0; j < NumberOfColumns; ++j)
        {
            DungeonMap[i][j] = E_RoomType::EMPTY; // Inicializar como vacío
        }
    }
}

void ADungeonMaker::BeginPlay()
{
    Super::BeginPlay();

    GenerateDungeonMap();
    PrintDungeonMap();

    // Instanciar el widget
    if (DungeonMapWidgetClass)
    {
        if (UDungeonMapWidget* DungeonMapWidget = CreateWidget<UDungeonMapWidget>(GetWorld(), DungeonMapWidgetClass))
        {
            DungeonMapWidget->AddToViewport();

            // Pasar la matriz de mazmorras al widget
            DungeonMapWidget->UpdateMap(DungeonMap);
        }
    }
}

void ADungeonMaker::GenerateDungeonMap()
{
    // Inicializar DungeonMap
    DungeonMap.SetNum(NumberOfRows); // Establece el tamaño de las filas

    for (int32 i = 0; i < NumberOfRows; ++i)
    {
        DungeonMap[i].SetNum(NumberOfColumns); // Establece el tamaño de las columnas para cada fila
    }

    // Inicializar la matriz con EMPTY
    for (int32 i = 0; i < NumberOfRows; ++i)
    {
        for (int32 j = 0; j < NumberOfColumns; ++j)
        {
            DungeonMap[i][j] = E_RoomType::EMPTY;
        }
    }

    // Posibles posiciones de la entrada
    TArray<FIntPoint> PossibleEntries = {
        FIntPoint(0, 2),   // Columna 0; Fila 2
        FIntPoint(2, 0),   // Columna 2; Fila 0
        FIntPoint(4, 2),   // Columna 4; Fila 2
        FIntPoint(2, 4)    // Columna 2; Fila 4
    };

    // Elegir aleatoriamente la posición de la entrada
    FIntPoint EntryPos = PossibleEntries[FMath::RandRange(0, PossibleEntries.Num() - 1)];
    DungeonMap[EntryPos.Y][EntryPos.X] = E_RoomType::ENTRY;

    // Definir posiciones de salas
    TArray<FIntPoint> OpenSet;
    OpenSet.Add(EntryPos);

    int32 CombatRoomCount = 0; // Contador para las salas de combate

    // Generar las salas de forma procedural
    while (CombatRoomCount < NumberOfRooms && OpenSet.Num() > 0)
    {
        // Elegir una sala existente de la lista
        FIntPoint CurrentPos = OpenSet[FMath::RandRange(0, OpenSet.Num() - 1)];
        OpenSet.Remove(CurrentPos);

        // Direcciones para generar nuevas salas (ya aplicando el shuffle modificado)
        TArray<FIntPoint> Directions = { FIntPoint(0, 1), FIntPoint(0, -1), FIntPoint(1, 0), FIntPoint(-1, 0) };
        const int32 NumShuffles = Directions.Num() - 1;
        for (int32 j = 0; j < NumShuffles; ++j)
        {
            int32 SwapIdx = FMath::RandRange(j, NumShuffles);
            Directions.Swap(j, SwapIdx);
        }

        // Tratar de colocar una nueva sala adyacente
        for (const FIntPoint& Direction : Directions)
        {
            int32 NewRow = CurrentPos.Y + Direction.Y;
            int32 NewCol = CurrentPos.X + Direction.X;

            if (IsWithinBounds(NewRow, NewCol) && DungeonMap[NewRow][NewCol] == E_RoomType::EMPTY)
            {
                // Solo colocar la sala si puede tener conexiones válidas
                if (CanPlaceConnection(NewRow, NewCol))
                {
                    DungeonMap[NewRow][NewCol] = E_RoomType::COMBAT;
                    OpenSet.Add(FIntPoint(NewCol, NewRow)); // Añadir la nueva sala al OpenSet
                    CombatRoomCount++; // Incrementar el contador de salas de combate
                    break; // Salir del loop para evitar demasiadas conexiones
                }
            }
        }
    }

    // Colocar la salida en la posición más lejana a la entrada
    PlaceExit(EntryPos);
}

bool ADungeonMaker::CanPlaceConnection(int32 Row, int32 Col)
{
    int32 Connections = 0;

    // Definir las direcciones posibles
    TArray<FIntPoint> Directions = {
        FIntPoint(0, 1),   // Derecha
        FIntPoint(0, -1),  // Izquierda
        FIntPoint(1, 0),   // Abajo
        FIntPoint(-1, 0)   // Arriba
    };

    // Revisar cuántas conexiones tiene la sala actual
    for (const FIntPoint& Direction : Directions)
    {
        int32 NewRow = Row + Direction.Y;
        int32 NewCol = Col + Direction.X;

        if (IsWithinBounds(NewRow, NewCol) && DungeonMap[NewRow][NewCol] != E_RoomType::EMPTY)
        {
            ++Connections;
        }
    }

    // Solo permitir si las conexiones actuales son menores al límite
    return Connections < MaxConnectionsPerRoom;
}

void ADungeonMaker::PlaceExit(const FIntPoint& EntryPos)
{
    FIntPoint FarthestPos;
    int32 MaxDistance = -1;

    // Buscar la posición más lejana de la entrada que esté conectada
    for (int32 i = 0; i < NumberOfRows; ++i)
    {
        for (int32 j = 0; j < NumberOfColumns; ++j)
        {
            if (DungeonMap[i][j] == E_RoomType::COMBAT)
            {
                int32 Distance = FMath::Abs(i - EntryPos.Y) + FMath::Abs(j - EntryPos.X);
                if (Distance > MaxDistance)
                {
                    MaxDistance = Distance;
                    FarthestPos = FIntPoint(j, i);
                }
            }
        }
    }

    // Colocar la salida en la posición más lejana
    DungeonMap[FarthestPos.Y][FarthestPos.X] = E_RoomType::EXIT;
}


FIntPoint ADungeonMaker::FindFurthestPointFromEntry(int32 EntryRow, int32 EntryCol)
{
    FIntPoint FurthestPoint;
    int32 MaxDistance = -1;

    for (int32 Row = 0; Row < NumberOfRows; ++Row)
    {
        for (int32 Col = 0; Col < NumberOfColumns; ++Col)
        {
            // Omitir la posición de la entrada
            if (Row == EntryRow && Col == EntryCol)
                continue;

            // Omitir las posiciones de entrada para que la salida no coincida
            if ((Col == 0 && Row == 2) || (Col == 2 && Row == 0) || (Col == 4 && Row == 2) || (Col == 2 && Row == 4))
                continue;

            // Calcular la distancia de Manhattan
            int32 Distance = FMath::Abs(Row - EntryRow) + FMath::Abs(Col - EntryCol);
            if (Distance > MaxDistance)
            {
                MaxDistance = Distance;
                FurthestPoint = FIntPoint(Col, Row);
            }
        }
    }

    return FurthestPoint;
}

void ADungeonMaker::GeneratePath(int32 StartRow, int32 StartCol, int32 EndRow, int32 EndCol, TArray<FIntPoint>& RoomPositions)
{
    int32 CurrentRow = StartRow;
    int32 CurrentCol = StartCol;

    while (CurrentRow != EndRow || CurrentCol != EndCol)
    {
        if (CurrentRow != EndRow)
        {
            CurrentRow += (EndRow > CurrentRow) ? 1 : -1;
        }
        else if (CurrentCol != EndCol)
        {
            CurrentCol += (EndCol > CurrentCol) ? 1 : -1;
        }

        if (DungeonMap[CurrentRow][CurrentCol] == E_RoomType::EMPTY)
        {
            DungeonMap[CurrentRow][CurrentCol] = E_RoomType::COMBAT;
            RoomPositions.Add(FIntPoint(CurrentCol, CurrentRow));
        }
    }
}

void ADungeonMaker::PrintDungeonMap()
{
    // for (int32 i = 0; i < NumberOfRows; ++i)
    // {
    //     FString RowString;
    //     for (int32 j = 0; j < NumberOfColumns; ++j)
    //     {
    //         RowString += FString::Printf(TEXT("%d "), (uint8)DungeonMap[i][j]);
    //     }
    //     UE_LOG(LogTemp, Log, TEXT("Fila %d: %s"), i, *RowString);
    // }
}
bool ADungeonMaker::IsWithinBounds(int32 Row, int32 Col) const
{
    return Row >= 0 && Row < NumberOfRows && Col >= 0 && Col < NumberOfColumns;
}


