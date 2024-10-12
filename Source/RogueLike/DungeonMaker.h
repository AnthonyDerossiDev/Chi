// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DungeonMapWidget.h"
#include "GameFramework/Actor.h"
#include "DungeonTypes.h"
#include "DungeonMaker.generated.h"

UCLASS()
class ROGUELIKE_API ADungeonMaker : public AActor
{
	GENERATED_BODY()
	
public:

	// Constructor
	ADungeonMaker();

protected:
	
	virtual void BeginPlay() override;
	void GenerateDungeonMap();
	void AddWidgetMap();
	void SetEntrance();
	void SetExit();
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 NumberOfRows = 5;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 NumberOfColumns = 5;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
	TSubclassOf<UDungeonMapWidget> DungeonMapWidgetClass;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 MaxConnectionsPerRoom = 3;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 NumberOfRooms = 8;

	TArray<TArray<E_RoomType>> DungeonMap;

private:
	class UDungeonMapWidget* DungeonMapWidget;


};
