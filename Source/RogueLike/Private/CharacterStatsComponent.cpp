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


#include "CharacterStatsComponent.h"

// Sets default values for this component's properties
UCharacterStatsComponent::UCharacterStatsComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UCharacterStatsComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UCharacterStatsComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

#if WITH_EDITOR
void UCharacterStatsComponent::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	if (PropertyChangedEvent.Property && PropertyChangedEvent.Property->GetFName() == GET_MEMBER_NAME_CHECKED(UCharacterStatsComponent, CharacterBaseStatsData))
	{
		if (CharacterBaseStatsData != nullptr)
		{
			CurrentPlayerStatsMap = CharacterBaseStatsData->PlayerStatsBaseMap;
			
		}
	}
}
#endif

void UCharacterStatsComponent::AddStatData(ECharacterStatType Stat, float AdditiveDelta, float MultiplicativeDelta, float DivisorDelta)
{
	if (CurrentPlayerStatsMap.Contains(Stat))
	{
		// Mostrar antes de modificar los valores
		FString StatName = UEnum::GetValueAsString(Stat);
		FString LogMessage = FString::Printf(TEXT("Modificando stat: %s"), *StatName);

		// Imprimir cambios detallados
		LogMessage += FString::Printf(TEXT("\n- AdditiveDelta: %f -> %f"), CurrentPlayerStatsMap[Stat].CurrentAdditiveValues, CurrentPlayerStatsMap[Stat].CurrentAdditiveValues + AdditiveDelta);
		LogMessage += FString::Printf(TEXT("\n- MultiplicativeDelta: %f -> %f"), CurrentPlayerStatsMap[Stat].CurrentMultiplicativeValues, CurrentPlayerStatsMap[Stat].CurrentMultiplicativeValues + MultiplicativeDelta);
		LogMessage += FString::Printf(TEXT("\n- DivisorDelta: %f -> %f"), CurrentPlayerStatsMap[Stat].CurrentDivisorValues, CurrentPlayerStatsMap[Stat].CurrentDivisorValues + DivisorDelta);

		// Actualizar valores
		CurrentPlayerStatsMap[Stat].CurrentAdditiveValues += AdditiveDelta;
		CurrentPlayerStatsMap[Stat].CurrentMultiplicativeValues += MultiplicativeDelta;
		CurrentPlayerStatsMap[Stat].CurrentDivisorValues += DivisorDelta;

		// Imprimir el mensaje detallado en la pantalla
		GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Green, LogMessage);
	}
	else
	{
		FString StatName = UEnum::GetValueAsString(Stat);
		FString ErrorMessage = FString::Printf(TEXT("Error: No se pudo encontrar el stat solicitado: %s"), *StatName);

		// Imprimir error en pantalla
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, ErrorMessage);
	}
}


