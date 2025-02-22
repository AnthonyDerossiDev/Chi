// // // Copyright (c) 2025 BrokenQuill Studios. All rights reserved. // // This game and its associated assets (including code, graphics, sounds, and other media)  // are the intellectual property of BrokenQuill Studios. All rights to the content are  // reserved by BrokenQuill Studios. // // This game was developed using the Unreal Engine, which is a product of Epic Games, Inc.  // Unreal Engine is a trademark or registered trademark of Epic Games, Inc. in the United States  // and elsewhere. // // This software and all its components are provided "as is" without warranty of any kind,  // either express or implied, including but not limited to the warranties of merchantability,  // fitness for a particular purpose, or noninfringement.  // // In no event shall BrokenQuill Studios or its contributors be liable for any damages  // arising from the use of this software. // // For inquiries, support, or licensing, please contact BrokenQuill Studios at:  // https://www.brokenquillstudio.com  //

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "CharacterStatsData.generated.h"

UENUM(BlueprintType)
enum class ECharacterStatType : uint8
{
    // Health Stats
    BaseHealth           UMETA(DisplayName = "Base Health"),
    MaxHealth            UMETA(DisplayName = "Max Health"),
    CurrentHealth        UMETA(DisplayName = "Current Health"),
    TemporaryHealth      UMETA(DisplayName = "Temporary Health"),

    // Movement Stats
    MovementSpeed        UMETA(DisplayName = "Movement Speed"),

    // Combat Stats
    Attack               UMETA(DisplayName = "Attack"),
    AttackSpeed          UMETA(DisplayName = "Attack Speed"),
    ProjectileSpeed      UMETA(DisplayName = "Projectile Speed"),
    Defense              UMETA(DisplayName = "Defense"),
    CriticalChance       UMETA(DisplayName = "Critical Chance"),
    CriticalDamage       UMETA(DisplayName = "Critical Damage"),
    RangedRange          UMETA(DisplayName = "Ranged Range"),
    Spread               UMETA(DisplayName = "Spread"),
    Accuracy             UMETA(DisplayName = "Accuracy"),

    // Miscellaneous Combat Stats
    AOESize              UMETA(DisplayName = "AOE Size"),
    AOEDamage            UMETA(DisplayName = "AOE Damage"),
    Delay                UMETA(DisplayName = "Delay"),
    Lifesteal            UMETA(DisplayName = "Lifesteal"),
    InvulnerableFrames   UMETA(DisplayName = "Invulnerable Frames"),
    TrueDamage           UMETA(DisplayName = "True Damage"),
    DOTMultiplier        UMETA(DisplayName = "DOT Multiplier"),
    DOTDuration          UMETA(DisplayName = "DOT Duration"),
    DOTTick              UMETA(DisplayName = "DOT Tick"),
    Cooldown             UMETA(DisplayName = "Cooldown"),

    // Healing Stats
    HealingAmount        UMETA(DisplayName = "Healing Amount"),
    HOTAmount            UMETA(DisplayName = "HOT Amount"),
    HOTTick              UMETA(DisplayName = "HOT Tick"),
    HOTDuration          UMETA(DisplayName = "HOT Duration"),

    // Combat Effects
    StunChance           UMETA(DisplayName = "Stun Chance"),
    StunDuration         UMETA(DisplayName = "Stun Duration"),
    KnockbackChance      UMETA(DisplayName = "Knockback Chance"),
    KnockbackDistance    UMETA(DisplayName = "Knockback Distance"),
    OnHitEffectChance    UMETA(DisplayName = "On Hit Effect Chance"),
    OnTakingDamageEffectChance UMETA(DisplayName = "On Taking Damage Effect Chance"),

    // Miscellaneous
    CharacterSize        UMETA(DisplayName = "Character Size"),
    Luck                 UMETA(DisplayName = "Luck"),
    Penetration          UMETA(DisplayName = "Penetration"),
    Rebound              UMETA(DisplayName = "Rebound"),
    OutOfCombatRegeneration UMETA(DisplayName = "Out of Combat Regeneration"),
    OutOfCombatDelay     UMETA(DisplayName = "Out of Combat Delay")
};

USTRUCT(BlueprintType)
struct FStat
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Value;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float LevelIncrement;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float CurrentAdditiveValues;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float CurrentMultiplicativeValues;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float CurrentDivisorValues;
};

USTRUCT(BlueprintType)
struct FCharacterStats : public FTableRowBase
{
	GENERATED_BODY();

	// Base Health: The base health points of a character. These are not the current or maximum health, but the number upon which modifications are made.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
    FStat BaseHealth;

    // Max Health: The maximum health a character can have, cannot be healed above this value.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
    FStat MaxHealth;

    // Current Health: Represents the character's current health. If it reaches zero, the character dies.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
    FStat CurrentHealth;

    // Temporary Health: A temporary health value independent of the current health that can exceed the maximum health. Always lost or reduced before current health.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
    FStat TemporaryHealth;

    // Movement Speed: Statistic that controls how fast a character moves.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
    FStat MovementSpeed;

    // Attack: Value measured against the opponent's defense to calculate the final damage.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    FStat Attack;

    // Attack Speed: Statistic that indicates how fast a character attacks. 1 means one attack per second.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    FStat AttackSpeed;

    // Projectile Speed: Statistic indicating how fast a projectile moves. Measured in units per second.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    FStat ProjectileSpeed;

    // Defense: Value that mitigates the final damage by opposing the attack.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    FStat Defense;

    // Critical Chance: Probability that an attack will be a critical hit.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    FStat CriticalChance;

    // Critical Damage: Multiplier to the base damage used for calculating the final damage on a critical hit.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    FStat CriticalDamage;

    // Ranged Range: Maximum distance a projectile fired from a ranged weapon travels.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    FStat RangedRange;

    // Spread: The maximum angle at which a projectile can deviate when fired.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    FStat Spread;

    // Accuracy: The probability that a projectile will miss or deviate from its intended path.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    FStat Accuracy;

    // Character Size: Scale of the character in the game, affecting the size of the collider and making it easier or harder to hit.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Miscellaneous")
    FStat CharacterSize;

    // AOE (Area of Effect Size): Size of the area affected by an area attack.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    FStat AOESize;
    // AOE (Area of Effect Damage): Damage dealt inside damage area.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    FStat AOEDamage;

    // Delay: The time it takes for an ability to start its effect after being cast. Can also define the interval between different effects in the same ability.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    FStat Delay;

    // Lifesteal: Percentage of damage dealt converted into healing for the player.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    FStat Lifesteal;

    // Invulnerable Frames: Number of frames in an animation during which the character is immune to all damage.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    FStat InvulnerableFrames;

    // True Damage: Damage dealt to the enemy's base health, ignoring their resistance or defense.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    FStat TrueDamage;

    // Damage Over Time (DOT): A multiplier applied to the attack to calculate continuous damage over time.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    FStat DOTMultiplier;

    // DOT Duration: Duration for how long Damage Over Time lasts before it stops affecting the enemy.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    FStat DOTDuration;

    // DOT Tick: Interval in seconds between each damage tick of Damage Over Time.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    FStat DOTTick;

    // Cooldown: Time required for an ability or action to become available again.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    FStat Cooldown;

    // Healing Amount: Value representing the amount of health restored with an instant healing action.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Healing")
    FStat HealingAmount;

    // HOT (Healing Over Time): Amount of health healed per tick when the character is under a healing-over-time effect.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Healing")
    FStat HOTAmount;

    // HOT Tick: Interval in seconds between each healing tick of HOT (Healing Over Time).
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Healing")
    FStat HOTTick;

    // HOT Duration: Duration of how long the HOT lasts before it stops healing the character.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Healing")
    FStat HOTDuration;

    // Stun Chance: Probability that an enemy will be stunned upon being attacked.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    FStat StunChance;

    // Stun Duration: The duration of the stun effect during which the enemy cannot perform actions.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    FStat StunDuration;

    // Knockback Chance: Probability that an attack will knock back an enemy.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    FStat KnockbackChance;

    // Knockback Distance: The distance an enemy is pushed back when hit by an attack.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    FStat KnockbackDistance;

    // On Hit Effect Chance: Probability that an effect will trigger when the player hits the enemy.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    FStat OnHitEffectChance;

    // On Taking Damage (OTD) Effect Chance: Probability that an effect will trigger when the player takes damage from the enemy.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    FStat OnTakingDamageEffectChance;

	// Luck: A value that modifies other stats. The way it modifies depends on the object. For the character, it modifies critical chance and can affect money, item rarity, or special room appearance chances.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Miscellaneous")
	FStat Luck;

	// Penetration: The value indicating how many enemies a projectile hits before disappearing.
	// 1 means it disappears after hitting the first enemy.
	// 2 means it passes through the first enemy, applies its effect, and then continues to another enemy.
	// Higher values allow for more enemies to be hit.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
	FStat Penetration;
	
	// Rebound: Indicates if a projectile redirects to another enemy after hitting the first one. 
	// 0 means it disappears after hitting one enemy.
	// 1 means it redirects to the closest enemy after hitting one.
	// 2 means it can redirect up to two times.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
	FStat Rebound;

	// Out of Combat Regeneration: Health that regenerates after a defined time period (Out of Combat Delay) without taking damage.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Healing")
	FStat OutOfCombatRegeneration;
	
	// Out of Combat Delay: Time in seconds to wait before triggering out-of-combat health regeneration.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Healing")
	FStat OutOfCombatDelay;
};

UCLASS(BlueprintType)
class ROGUELIKE_API UCharacterStatsData : public UDataAsset
{
	GENERATED_BODY()

public:
	UCharacterStatsData();

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	TMap<ECharacterStatType, FStat> PlayerStatsBaseMap;

	
};
