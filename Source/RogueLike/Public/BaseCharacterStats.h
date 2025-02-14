// Parent class that serves to store and return the stats of characters, such as enemies and player-controlled characters.
// The class that manages enemy stats will inherit from this one, as well as the class that manages the stats of player-controlled characters.
// This is because there are several common stats, but not all of them.
// Every stat shown in this class is shared among different characters, whether they are enemies or player-controlled characters.
#pragma once

#include "CoreMinimal.h"
#include "BaseCharacterStats.generated.h"

USTRUCT(BlueprintType)
struct FFloatPair
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Value;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float LevelIncrement;
};


USTRUCT(BlueprintType)
struct FSharedCharacterStats : public FTableRowBase
{
	GENERATED_BODY();

	// Base Health: The base health points of a character. These are not the current or maximum health, but the number upon which modifications are made.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
    FFloatPair BaseHealth;

    // Max Health: The maximum health a character can have, cannot be healed above this value.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
    FFloatPair MaxHealth;

    // Current Health: Represents the character's current health. If it reaches zero, the character dies.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
    FFloatPair CurrentHealth;

    // Temporary Health: A temporary health value independent of the current health that can exceed the maximum health. Always lost or reduced before current health.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
    FFloatPair TemporaryHealth;

    // Movement Speed: Statistic that controls how fast a character moves.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
    FFloatPair MovementSpeed;

    // Attack: Value measured against the opponent's defense to calculate the final damage.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    FFloatPair Attack;

    // Attack Speed: Statistic that indicates how fast a character attacks. 1 means one attack per second.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    FFloatPair AttackSpeed;

    // Projectile Speed: Statistic indicating how fast a projectile moves. Measured in units per second.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    FFloatPair ProjectileSpeed;

    // Defense: Value that mitigates the final damage by opposing the attack.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    FFloatPair Defense;

    // Critical Chance: Probability that an attack will be a critical hit.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    FFloatPair CriticalChance;

    // Critical Damage: Multiplier to the base damage used for calculating the final damage on a critical hit.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    FFloatPair CriticalDamage;

    // Ranged Range: Maximum distance a projectile fired from a ranged weapon travels.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    FFloatPair RangedRange;

    // Spread: The maximum angle at which a projectile can deviate when fired.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    FFloatPair Spread;

    // Accuracy: The probability that a projectile will miss or deviate from its intended path.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    FFloatPair Accuracy;

    // Character Size: Scale of the character in the game, affecting the size of the collider and making it easier or harder to hit.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Miscellaneous")
    FFloatPair CharacterSize;

    // AOE (Area of Effect Diameter): Size of the area affected by an area attack.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    FFloatPair AOE;

    // Delay: The time it takes for an ability to start its effect after being cast. Can also define the interval between different effects in the same ability.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    FFloatPair Delay;

    // Lifesteal: Percentage of damage dealt converted into healing for the player.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    FFloatPair Lifesteal;

    // Invulnerable Frames: Number of frames in an animation during which the character is immune to all damage.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    FFloatPair InvulnerableFrames;

    // True Damage: Damage dealt to the enemy's base health, ignoring their resistance or defense.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    FFloatPair TrueDamage;

    // Damage Over Time (DOT): A multiplier applied to the attack to calculate continuous damage over time.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    FFloatPair DOTMultiplier;

    // DOT Duration: Duration for how long Damage Over Time lasts before it stops affecting the enemy.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    FFloatPair DOTDuration;

    // DOT Tick: Interval in seconds between each damage tick of Damage Over Time.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    FFloatPair DOTTick;

    // Cooldown: Time required for an ability or action to become available again.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    FFloatPair Cooldown;

    // Healing Amount: Value representing the amount of health restored with an instant healing action.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Healing")
    FFloatPair HealingAmount;

    // HOT (Healing Over Time): Amount of health healed per tick when the character is under a healing-over-time effect.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Healing")
    FFloatPair HOTAmount;

    // HOT Tick: Interval in seconds between each healing tick of HOT (Healing Over Time).
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Healing")
    FFloatPair HOTTick;

    // HOT Duration: Duration of how long the HOT lasts before it stops healing the character.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Healing")
    FFloatPair HOTDuration;

    // Stun Chance: Probability that an enemy will be stunned upon being attacked.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    FFloatPair StunChance;

    // Stun Duration: The duration of the stun effect during which the enemy cannot perform actions.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    FFloatPair StunDuration;

    // Knockback Chance: Probability that an attack will knock back an enemy.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    FFloatPair KnockbackChance;

    // Knockback Distance: The distance an enemy is pushed back when hit by an attack.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    FFloatPair KnockbackDistance;

    // On Hit Effect Chance: Probability that an effect will trigger when the player hits the enemy.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    FFloatPair OnHitEffectChance;

    // On Taking Damage (OTD) Effect Chance: Probability that an effect will trigger when the player takes damage from the enemy.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    FFloatPair OnTakingDamageEffectChance;
};

UCLASS()
class ROGUELIKE_API UBaseCharacterStats : public UObject
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadWrite)
	FSharedCharacterStats CharacterStats;
};
