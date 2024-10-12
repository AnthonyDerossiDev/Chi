// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DungeonMapWidget.h"
#include "GameFramework/Actor.h"
#include "DungeonTypes.h"
#include "Kismet/KismetMathLibrary.h" // Para generar valores aleatorios
#include "DungeonMaker.generated.h"

UCLASS()
class ROGUELIKE_API ADungeonMaker : public AActor
{
	GENERATED_BODY()
	
public:
	// Definir el tamaño de la matriz
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 NumberOfRows = 5;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 NumberOfColumns = 5;

	// Declarar la matriz
	TArray<TArray<E_RoomType>> DungeonMap;

	// Constructor
	ADungeonMaker();

protected:
	// Función que inicializa la estructura de la mazmorra
	virtual void BeginPlay() override;

	// Método para establecer el tipo de sala en una posición específica
	void SetRoomType(int32 RowIndex, int32 ColIndex, E_RoomType RoomType);
	void GenerateDungeonMap();
	FIntPoint FindFurthestPointFromEntry(int32 EntryRow, int32 EntryCol);
	FIntPoint FindFurthestPoint(int32 EntryRow, int32 EntryCol, const TArray<FIntPoint>& Positions);
	void GeneratePath(int32 StartRow, int32 StartCol, int32 EndRow, int32 EndCol, TArray<FIntPoint>& RoomPositions);
	void AddRandomCombatRooms();
	void PrintDungeonMap();
	bool CanPlaceConnection(int32 Row, int32 Col);
	void PlaceExit(const FIntPoint& EntryPos);
	bool IsWithinBounds(int32 Row, int32 Col) const;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
	TSubclassOf<UDungeonMapWidget> DungeonMapWidgetClass; // Clase del widget

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 MaxConnectionsPerRoom = 3;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 NumberOfRooms = 8;


};
