// // // Copyright (c) 2025 BrokenQuill Studios. All rights reserved. // // This game and its associated assets (including code, graphics, sounds, and other media)  // are the intellectual property of BrokenQuill Studios. All rights to the content are  // reserved by BrokenQuill Studios. // // This game was developed using the Unreal Engine, which is a product of Epic Games, Inc.  // Unreal Engine is a trademark or registered trademark of Epic Games, Inc. in the United States  // and elsewhere. // // This software and all its components are provided "as is" without warranty of any kind,  // either express or implied, including but not limited to the warranties of merchantability,  // fitness for a particular purpose, or noninfringement.  // // In no event shall BrokenQuill Studios or its contributors be liable for any damages  // arising from the use of this software. // // For inquiries, support, or licensing, please contact BrokenQuill Studios at:  // https://www.brokenquillstudio.com  //

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "EnemyStatsData.generated.h"

UENUM(BlueprintType)
enum class EEnemyStatType : uint8
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

    // Combat Effects
    StunChance           UMETA(DisplayName = "Stun Chance"),
    StunDuration         UMETA(DisplayName = "Stun Duration"),
    KnockbackChance      UMETA(DisplayName = "Knockback Chance"),
    KnockbackDistance    UMETA(DisplayName = "Knockback Distance"),
    OnHitEffectChance    UMETA(DisplayName = "On Hit Effect Chance"),
    OnTakingDamageEffectChance UMETA(DisplayName = "On Taking Damage Effect Chance"),

    // Miscellaneous
    CharacterSize	UMETA(DisplayName = "Character Size"),
	ReactionInterval	UMETA(DisplayName = "Reaction Interval"),

};

USTRUCT(BlueprintType)
struct FEnemyStat
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float BaseValue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Value;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float LevelIncrement;
};

USTRUCT(BlueprintType)
struct FEnemyStats : public FTableRowBase
{
	GENERATED_BODY();

	// Base Health: The base health points of a character. These are not the current or maximum health, but the number upon which modifications are made.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
    FEnemyStat BaseHealth;

    // Max Health: The maximum health a character can have, cannot be healed above this value.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
    FEnemyStat MaxHealth;

    // Current Health: Represents the character's current health. If it reaches zero, the character dies.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
    FEnemyStat CurrentHealth;

    // Temporary Health: A temporary health value independent of the current health that can exceed the maximum health. Always lost or reduced before current health.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
    FEnemyStat TemporaryHealth;

    // Movement Speed: Statistic that controls how fast a character moves.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
    FEnemyStat MovementSpeed;

    // Attack: Value measured against the opponent's defense to calculate the final damage.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    FEnemyStat Attack;

    // Attack Speed: Statistic that indicates how fast a character attacks. 1 means one attack per second.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    FEnemyStat AttackSpeed;

    // Projectile Speed: Statistic indicating how fast a projectile moves. Measured in units per second.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    FEnemyStat ProjectileSpeed;

    // Defense: Value that mitigates the final damage by opposing the attack.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    FEnemyStat Defense;

    // Critical Chance: Probability that an attack will be a critical hit.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    FEnemyStat CriticalChance;

    // Critical Damage: Multiplier to the base damage used for calculating the final damage on a critical hit.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    FEnemyStat CriticalDamage;

    // Ranged Range: Maximum distance a projectile fired from a ranged weapon travels.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    FEnemyStat RangedRange;

    // Spread: The maximum angle at which a projectile can deviate when fired.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    FEnemyStat Spread;

    // Accuracy: The probability that a projectile will miss or deviate from its intended path.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    FEnemyStat Accuracy;

    // Character Size: Scale of the character in the game, affecting the size of the collider and making it easier or harder to hit.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Miscellaneous")
    FEnemyStat CharacterSize;

    // AOE (Area of Effect Size): Size of the area affected by an area attack.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    FEnemyStat AOESize;
    // AOE (Area of Effect Damage): Damage dealt inside damage area.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    FEnemyStat AOEDamage;

    // Delay: The time it takes for an ability to start its effect after being cast. Can also define the interval between different effects in the same ability.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    FEnemyStat Delay;

    // Lifesteal: Percentage of damage dealt converted into healing for the player.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    FEnemyStat Lifesteal;

    // Invulnerable Frames: Number of frames in an animation during which the character is immune to all damage.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    FEnemyStat InvulnerableFrames;

    // True Damage: Damage dealt to the enemy's base health, ignoring their resistance or defense.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    FEnemyStat TrueDamage;

    // Damage Over Time (DOT): A multiplier applied to the attack to calculate continuous damage over time.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    FEnemyStat DOTMultiplier;

    // DOT Duration: Duration for how long Damage Over Time lasts before it stops affecting the enemy.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    FEnemyStat DOTDuration;

    // DOT Tick: Interval in seconds between each damage tick of Damage Over Time.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    FEnemyStat DOTTick;

    // Cooldown: Time required for an ability or action to become available again.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    FEnemyStat Cooldown;

    // Healing Amount: Value representing the amount of health restored with an instant healing action.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Healing")
    FEnemyStat HealingAmount;

    // HOT (Healing Over Time): Amount of health healed per tick when the character is under a healing-over-time effect.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Healing")
    FEnemyStat HOTAmount;

    // HOT Tick: Interval in seconds between each healing tick of HOT (Healing Over Time).
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Healing")
    FEnemyStat HOTTick;

    // HOT Duration: Duration of how long the HOT lasts before it stops healing the character.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Healing")
    FEnemyStat HOTDuration;

    // Stun Chance: Probability that an enemy will be stunned upon being attacked.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    FEnemyStat StunChance;

    // Stun Duration: The duration of the stun effect during which the enemy cannot perform actions.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    FEnemyStat StunDuration;

    // Knockback Chance: Probability that an attack will knock back an enemy.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    FEnemyStat KnockbackChance;

    // Knockback Distance: The distance an enemy is pushed back when hit by an attack.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    FEnemyStat KnockbackDistance;

    // On Hit Effect Chance: Probability that an effect will trigger when the player hits the enemy.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    FEnemyStat OnHitEffectChance;

    // On Taking Damage (OTD) Effect Chance: Probability that an effect will trigger when the player takes damage from the enemy.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    FEnemyStat OnTakingDamageEffectChance;
	
};

UCLASS()
class ROGUELIKE_API UEnemyStatsData : public UDataAsset
{
	GENERATED_BODY()

	UEnemyStatsData();
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	TMap<EEnemyStatType, FEnemyStat> EnemyStatsBaseMap;
	
};
