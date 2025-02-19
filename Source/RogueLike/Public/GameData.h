// /** * Copyright (c) 2025 BrokenQuill Studios. All rights reserved. * * This game and its associated assets (including code, graphics, sounds, and other media)  * are the intellectual property of BrokenQuill Studios. All rights to the content are  * reserved by BrokenQuill Studios. * * This game was developed using the Unreal Engine, which is a product of Epic Games, Inc. * Unreal Engine is a trademark or registered trademark of Epic Games, Inc. in the United States  * and elsewhere. * * This software and all its components are provided "as is" without warranty of any kind,  * either express or implied, including but not limited to the warranties of merchantability,  * fitness for a particular purpose, or noninfringement. In no event shall BrokenQuill Studios  * or its contributors be liable for any damages arising from the use of this software. * * For inquiries, support, or licensing, please contact BrokenQuill Studios at: * https://www.brokenquillstudio.com */

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "GameData.generated.h"

// Estructura que almacena el valor y el factor de aumento del stat
USTRUCT(BlueprintType)
struct FStatData
{
	GENERATED_BODY()

	// Valor del stat
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	float StatValue;

	// Factor de incremento del stat por nivel
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	float LevelIncreaseFactor;

	FStatData()
		: StatValue(0.0f), LevelIncreaseFactor(1.0f) {}

	FStatData(float InStatValue, float InLevelIncreaseFactor)
		: StatValue(InStatValue), LevelIncreaseFactor(InLevelIncreaseFactor) {}
};

USTRUCT(BlueprintType)
struct FPlayerData
{
	GENERATED_BODY()

	// TMap para almacenar las estadísticas de cada stat, incluyendo el factor de incremento por nivel
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	TMap<ECharacterStatType, FStatData> StatValues;

	// Función para modificar un stat específico
	void SetStat(ECharacterStatType StatType, float Value)
	{
		if (StatValues.Contains(StatType))
		{
			StatValues[StatType].StatValue = Value;
		}
		else
		{
			// Si no existe, creamos el stat con el factor de incremento por defecto (1.0f)
			StatValues.Add(StatType, FStatData(Value, 1.0f));  // Default LevelIncreaseFactor
		}
	}

	// Función para obtener el valor de un stat específico
	float GetStat(ECharacterStatType StatType)
	{
		if (StatValues.Contains(StatType))
		{
			return StatValues[StatType].StatValue;
		}
		return 0.0f;  // Valor por defecto si no se encuentra el stat
	}

	float GetIncrementPerLevel(ECharacterStatType StatType)
	{
		if(StatValues.Contains(StatType))
		{
			return StatValues[StatType].LevelIncreaseFactor;
		}
		return 0.0f;
	}

	// Función para aumentar el stat según el factor de nivel
	void IncreaseStatForLevel(ECharacterStatType StatType)
	{
		if (StatValues.Contains(StatType))
		{
			StatValues[StatType].StatValue *= StatValues[StatType].LevelIncreaseFactor;
		}
	}
};

UCLASS()
class ROGUELIKE_API UGameData : public USaveGame
{
	GENERATED_BODY()

private:
	float AdditiveValues = 0.0f;
	float MultiplicativeValues = 0.0f;
	float DivisorValues = 0.0f;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	TMap<FString, FPlayerData> CharactersStats;

	UFUNCTION(BlueprintCallable)
	void ModifyCharacterStat(const FString& CharacterName, ECharacterStatType StatType, float Modifier);
	UFUNCTION(BlueprintCallable)
	void InitializePlayerStats(FPlayerData& PlayerData);

	/// @brief Retrieves the current value of a specified character stat. This value does not include additive, multiplicative, or divisor modifications provided by items.
	/// @param CharacterName The name of the character whose stat is being queried.
	/// @param StatType The specific stat to retrieve (e.g., Health, Attack Power).
	/// @param CharacterLevel (Optional) The level of the character. Defaults to 1.
	/// @param SkillVariable (Optional) A multiplier value based on the skill used. Defaults to 1.0f.
	/// @return The base value of the requested stat.
	UFUNCTION(BlueprintCallable)
	float GetCurrentStat(const FString& CharacterName, ECharacterStatType StatType, int CharacterLevel = 1, float SkillVariable = 1.0f);

	/// @brief Retrieves the current value of a specified character stat. This value does not include additive, multiplicative, or divisor modifications provided by items.
	/// @param CharacterName The name of the character whose stat is being queried.
	/// @param StatType The specific stat to retrieve (e.g., Health, Attack Power).
	/// @param CharacterLevel (Optional) The level of the character. Defaults to 1.
	/// @param SkillVariable (Optional) A multiplier value based on the skill used. Defaults to 1.0f.
	/// @return The base value of the requested stat.
	UFUNCTION(BlueprintCallable)
	float GetFinalStat(const FString& CharacterName, ECharacterStatType StatType, int CharacterLevel = 1, float SkillVariable = 1.0f);
	

	

	
};
