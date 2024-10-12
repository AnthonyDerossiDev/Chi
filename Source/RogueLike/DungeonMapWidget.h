// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DungeonTypes.h"
#include "Blueprint/UserWidget.h"
#include "Components/CanvasPanel.h"
#include "Components/GridPanel.h"
#include "Components/Image.h"
#include "DungeonMapWidget.generated.h"

/**
 * 
 */
UCLASS()
class ROGUELIKE_API UDungeonMapWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	void UpdateMap(const TArray<TArray<E_RoomType>>& DungeonMap);

protected:
	virtual void NativeConstruct() override;
	
	UFUNCTION(BlueprintImplementableEvent)
	void AddRoom(FVector2D RoomPosition, E_RoomType RoomType);

	UFUNCTION(BlueprintCallable)
	UImage* GenerateImage();
};
