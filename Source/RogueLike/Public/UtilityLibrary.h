// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "UtilityLibrary.generated.h"

/**
 * 
 */
UCLASS()
class ROGUELIKE_API UUtilityLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
 /** Checks if the game is running in the editor */
    UFUNCTION(BlueprintPure, Category = "Utility")
    static bool IsRunningInEditor();

	UFUNCTION(BlueprintCallable, Category = "Utility")
	bool IsPositionReachable(FVector Position);

};
