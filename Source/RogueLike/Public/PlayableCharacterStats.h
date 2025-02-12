
/**
 * @brief This struct stores and manages the stats related to controllable characters.
 *
 * This class is designed to hold all the relevant statistics for playable characters, 
 * including attributes such as health, stamina, attack power, and any other relevant data.
 * These stats will be used to define and modify the performance of characters that the 
 * player can control.
 */
#pragma once

#include "CoreMinimal.h"
#include "BaseCharacterStats.h"
#include "PlayableCharacterStats.generated.h"

USTRUCT(BlueprintType)
struct FPlayableStats
{
	GENERATED_BODY()
	// Luck: A value that modifies other stats. The way it modifies depends on the object. For the character, it modifies critical chance and can affect money, item rarity, or special room appearance chances.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Miscellaneous")
	float Luck;

	// Penetration: The value indicating how many enemies a projectile hits before disappearing.
	// 1 means it disappears after hitting the first enemy.
	// 2 means it passes through the first enemy, applies its effect, and then continues to another enemy.
	// Higher values allow for more enemies to be hit.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
	int32 Penetration;
	
	// Rebound: Indicates if a projectile redirects to another enemy after hitting the first one. 
	// 0 means it disappears after hitting one enemy.
	// 1 means it redirects to the closest enemy after hitting one.
	// 2 means it can redirect up to two times.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
	int32 Rebound;

	// Out of Combat Regeneration: Health that regenerates after a defined time period (Out of Combat Delay) without taking damage.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Healing")
	float OutOfCombatRegeneration;
	
	// Out of Combat Delay: Time in seconds to wait before triggering out-of-combat health regeneration.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Healing")
	float OutOfCombatDelay;
};

UCLASS()
class ROGUELIKE_API UPlayableCharacterStats : public UBaseCharacterStats
{
	GENERATED_BODY()
	UPlayableCharacterStats();
	
public:
	UPROPERTY(BlueprintReadWrite)
	FPlayableStats PlayerStats;
};
