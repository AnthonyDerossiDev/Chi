// // // Copyright (c) 2025 BrokenQuill Studios. All rights reserved. // // This game and its associated assets (including code, graphics, sounds, and other media)  // are the intellectual property of BrokenQuill Studios. All rights to the content are  // reserved by BrokenQuill Studios. // // This game was developed using the Unreal Engine, which is a product of Epic Games, Inc.  // Unreal Engine is a trademark or registered trademark of Epic Games, Inc. in the United States  // and elsewhere. // // This software and all its components are provided "as is" without warranty of any kind,  // either express or implied, including but not limited to the warranties of merchantability,  // fitness for a particular purpose, or noninfringement.  // // In no event shall BrokenQuill Studios or its contributors be liable for any damages  // arising from the use of this software. // // For inquiries, support, or licensing, please contact BrokenQuill Studios at:  // https://www.brokenquillstudio.com  //


#include "EnemyStatsComponent.h"

// Sets default values for this component's properties
UEnemyStatsComponent::UEnemyStatsComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UEnemyStatsComponent::BeginPlay()
{
	Super::BeginPlay();

	float MaxHealth = GetCurrentStat(EEnemyStatType::MaxHealth);
	AlterStatDirectly(EEnemyStatType::CurrentHealth, MaxHealth);
	
}


// Called every frame
void UEnemyStatsComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

#if WITH_EDITOR
void UEnemyStatsComponent::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	if (PropertyChangedEvent.Property && PropertyChangedEvent.Property->GetFName() == GET_MEMBER_NAME_CHECKED(UEnemyStatsComponent, EnemyStatsData))
	{
		if (EnemyStatsData != nullptr)
		{
			CurrentEnemyStatsMap = EnemyStatsData->EnemyStatsBaseMap;
			
		}
	}
}
#endif 

float UEnemyStatsComponent::GetCurrentStat(EEnemyStatType Stat)
{
	float EnemyCurrentStat = 0.0f;
	CurrentEnemyLevel = CurrentEnemyLevel <= 0 ? 1 : CurrentEnemyLevel;
	if(CurrentEnemyStatsMap.Contains(Stat))
	{
		float BaseStat = CurrentEnemyStatsMap[Stat].BaseValue;
		float StatIncrementByLevel = CurrentEnemyStatsMap[Stat].LevelIncrement;
		EnemyCurrentStat = (BaseStat + (StatIncrementByLevel*(CurrentEnemyLevel - 1)));
	}
	else
	{
		FString StatName = UEnum::GetValueAsString(Stat);
		FString ErrorMessage = FString::Printf(TEXT("Error: No se pudo encontrar el stat solicitado: %s"), *StatName);

		// Imprimir error en pantalla
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, ErrorMessage);
	}
	return EnemyCurrentStat;
}

void UEnemyStatsComponent::AlterStatDirectly(EEnemyStatType Stat, float OverrideValue)
{
	if(CurrentEnemyStatsMap.Contains(Stat))
	{
		CurrentEnemyStatsMap[Stat].Value = OverrideValue;
	}
	else
	{
		FString StatName = UEnum::GetValueAsString(Stat);
		FString ErrorMessage = FString::Printf(TEXT("Error: No se pudo encontrar el stat solicitado: %s"), *StatName);

		// Imprimir error en pantalla
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, ErrorMessage);
	}
}

float UEnemyStatsComponent::GetCurrentStatWithSkill(EEnemyStatType Stat, float SkillVariable)
{
	float EnemyCurrentStatWithSkill = 0.0f;
	CurrentEnemyLevel = CurrentEnemyLevel <= 0 ? 1 : CurrentEnemyLevel;
	if(CurrentEnemyStatsMap.Contains(Stat))
	{
		float BaseStat = CurrentEnemyStatsMap[Stat].BaseValue;
		float StatIncrementByLevel = CurrentEnemyStatsMap[Stat].LevelIncrement;
		EnemyCurrentStatWithSkill = (BaseStat + (StatIncrementByLevel*(CurrentEnemyLevel - 1))) * SkillVariable;
	}
	else
	{
		FString StatName = UEnum::GetValueAsString(Stat);
		FString ErrorMessage = FString::Printf(TEXT("Error: No se pudo encontrar el stat solicitado: %s"), *StatName);

		// Imprimir error en pantalla
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, ErrorMessage);
	}
	return EnemyCurrentStatWithSkill;
}

