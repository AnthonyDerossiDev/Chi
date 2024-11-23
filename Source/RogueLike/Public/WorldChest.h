// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WorldChest.generated.h"

UENUM(BlueprintType)
enum class EItemRarity : uint8
{
	White,
	Green,
	Blue,
	Purple
};

UCLASS()
class ROGUELIKE_API AWorldChest : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWorldChest();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<float> BaseChances = {70.0, 20.0, 8.0, 2.0}; // Porcentaje inicial
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	EItemRarity GetItemBasedOnLuck(float Luck);

};
