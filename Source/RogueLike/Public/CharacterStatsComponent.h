// 
// Copyright (c) 2025 BrokenQuill Studios. All rights reserved. 
// 
// This game and its associated assets (including code, graphics, sounds, and other media)  
// are the intellectual property of BrokenQuill Studios. All rights to the content are  
// reserved by BrokenQuill Studios. 
// 
// This game was developed using the Unreal Engine, which is a product of Epic Games, Inc.  
// Unreal Engine is a trademark or registered trademark of Epic Games, Inc. in the United States  
// and elsewhere. 
// 
// This software and all its components are provided "as is" without warranty of any kind,  
// either express or implied, including but not limited to the warranties of merchantability,  
// fitness for a particular purpose, or noninfringement.  
// 
// In no event shall BrokenQuill Studios or its contributors be liable for any damages  
// arising from the use of this software. 
// 
// For inquiries, support, or licensing, please contact BrokenQuill Studios at:  
// https://www.brokenquillstudio.com  
//

#pragma once

#include "CoreMinimal.h"
#include "CharacterStatsData.h"
#include "Components/ActorComponent.h"
#include "CharacterStatsComponent.generated.h"

UENUM(BlueprintType)
enum class ECharacter : uint8
{
	Chii
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ROGUELIKE_API UCharacterStatsComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCharacterStatsComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Stats configuration")
	ECharacter CharacterName;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Stats configuration")
	UCharacterStatsData* CharacterBaseStatsData;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Stats configuration")
	TMap<ECharacterStatType, FStat> CurrentPlayerStatsMap;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Data")
	int CurrentPlayerLevel;
	

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;

	UFUNCTION(BlueprintCallable)
	void AddStatData(ECharacterStatType Stat, float AdditiveDelta, float MultiplicativeDelta, float DivisorDelta);

	UFUNCTION(BlueprintCallable)
	float GetCurrentStat(ECharacterStatType Stat);

	UFUNCTION(BlueprintCallable)
	float GetCurrentStatWithSkill(ECharacterStatType Stat, float SkillVariable);

	// Devuelve el stat del jugador teniendo en cuenta los objetos que lo modifiquen
	UFUNCTION(BlueprintCallable)
	float GetFinalStat(ECharacterStatType Stat);

	// Devuelve el stat del jugador teniendo en cuenta los objetos que lo modifiquen y además usa una variación dependiendo de la habilidad
	UFUNCTION(BlueprintCallable)
	float GetFinalStatWithSkill(ECharacterStatType Stat, float SkillVariable);
};
