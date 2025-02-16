// /** * Copyright (c) 2025 BrokenQuill Studios. All rights reserved. * * This game and its associated assets (including code, graphics, sounds, and other media)  * are the intellectual property of BrokenQuill Studios. All rights to the content are  * reserved by BrokenQuill Studios. * * This game was developed using the Unreal Engine, which is a product of Epic Games, Inc. * Unreal Engine is a trademark or registered trademark of Epic Games, Inc. in the United States  * and elsewhere. * * This software and all its components are provided "as is" without warranty of any kind,  * either express or implied, including but not limited to the warranties of merchantability,  * fitness for a particular purpose, or noninfringement. In no event shall BrokenQuill Studios  * or its contributors be liable for any damages arising from the use of this software. * * For inquiries, support, or licensing, please contact BrokenQuill Studios at: * https://www.brokenquillstudio.com */

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "CharactersStats.h"
#include "GameData.generated.h"

/**
 * 
 */
UCLASS()
class ROGUELIKE_API UGameData : public USaveGame
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	TMap<FString, FPlayableStats> CharactersStats;
	
};
