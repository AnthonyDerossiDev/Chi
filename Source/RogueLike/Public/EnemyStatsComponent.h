// // // Copyright (c) 2025 BrokenQuill Studios. All rights reserved. // // This game and its associated assets (including code, graphics, sounds, and other media)  // are the intellectual property of BrokenQuill Studios. All rights to the content are  // reserved by BrokenQuill Studios. // // This game was developed using the Unreal Engine, which is a product of Epic Games, Inc.  // Unreal Engine is a trademark or registered trademark of Epic Games, Inc. in the United States  // and elsewhere. // // This software and all its components are provided "as is" without warranty of any kind,  // either express or implied, including but not limited to the warranties of merchantability,  // fitness for a particular purpose, or noninfringement.  // // In no event shall BrokenQuill Studios or its contributors be liable for any damages  // arising from the use of this software. // // For inquiries, support, or licensing, please contact BrokenQuill Studios at:  // https://www.brokenquillstudio.com  //

#pragma once

#include "CoreMinimal.h"
#include "EnemyStatsData.h"
#include "Components/ActorComponent.h"
#include "EnemyStatsComponent.generated.h"

UENUM(BlueprintType)
enum class EEnemy : uint8
{
	TentacleHead
};


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ROGUELIKE_API UEnemyStatsComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UEnemyStatsComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Stats configuration")
	EEnemy EnemyName;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Stats configuration")
	UEnemyStatsData* EnemyStatsData;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Stats configuration")
	TMap<EEnemyStatType, FEnemyStat> CurrentEnemyStatsMap;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Stats configuration")
	int CurrentEnemyLevel;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	float GetCurrentStat(EEnemyStatType Stat);

	UFUNCTION(BlueprintCallable)
	void AlterStatDirectly(EEnemyStatType Stat, float OverrideValue);

	UFUNCTION(BlueprintCallable)
	float GetCurrentStatWithSkill(EEnemyStatType Stat, float SkillVariable);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health Stats")
	float MaxHealth = 100.f;  

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health Stats")
	float CurrentHealth = 100.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health Stats")
	float TemporaryHealth = 0.f;
		
};
