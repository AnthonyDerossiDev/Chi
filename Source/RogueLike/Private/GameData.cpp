// /** * Copyright (c) 2025 BrokenQuill Studios. All rights reserved. * * This game and its associated assets (including code, graphics, sounds, and other media)  * are the intellectual property of BrokenQuill Studios. All rights to the content are  * reserved by BrokenQuill Studios. * * This game was developed using the Unreal Engine, which is a product of Epic Games, Inc. * Unreal Engine is a trademark or registered trademark of Epic Games, Inc. in the United States  * and elsewhere. * * This software and all its components are provided "as is" without warranty of any kind,  * either express or implied, including but not limited to the warranties of merchantability,  * fitness for a particular purpose, or noninfringement. In no event shall BrokenQuill Studios  * or its contributors be liable for any damages arising from the use of this software. * * For inquiries, support, or licensing, please contact BrokenQuill Studios at: * https://www.brokenquillstudio.com */


#include "GameData.h"

void UGameData::ModifyCharacterStat(const FString& CharacterName, ECharacterStatType StatType, float Modifier)
{
	// Verificamos si el personaje existe en el mapa
	if (CharactersStats.Contains(CharacterName))
	{
		// Obtener las estadísticas del personaje
		FPlayerData& Data = CharactersStats[CharacterName];
        
		// Obtener el valor actual del stat
		float CurrentValue = Data.GetStat(StatType);
        
		// Modificar el stat con el modificador
		Data.SetStat(StatType, CurrentValue + Modifier);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Character %s not found!"), *CharacterName);
	}
}

void UGameData::InitializePlayerStats(FPlayerData& PlayerData)
{
}
