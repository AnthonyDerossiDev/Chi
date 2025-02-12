// Parent class that serves to store and return the stats of characters, such as enemies and player-controlled characters.
// The class that manages enemy stats will inherit from this one, as well as the class that manages the stats of player-controlled characters.
// This is because there are several common stats, but not all of them.
// Every stat shown in this class is shared among different characters, whether they are enemies or player-controlled characters.
#pragma once

#include "CoreMinimal.h"
#include "BaseCharacterStats.generated.h"


USTRUCT(BlueprintType)
struct FSharedCharacterStats
{
	GENERATED_BODY();

	// Base Health: The base health points of a character. These are not the current or maximum health, but the number upon which modifications are made.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
    float BaseHealth;

    // Max Health: The maximum health a character can have, cannot be healed above this value.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
    float MaxHealth;

    // Current Health: Represents the character's current health. If it reaches zero, the character dies.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
    float CurrentHealth;

    // Temporary Health: A temporary health value independent of the current health that can exceed the maximum health. Always lost or reduced before current health.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
    float TemporaryHealth;

    // Movement Speed: Statistic that controls how fast a character moves.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
    float MovementSpeed;

    // Attack: Value measured against the opponent's defense to calculate the final damage.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    float Attack;

    // Attack Speed: Statistic that indicates how fast a character attacks. 1 means one attack per second.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    float AttackSpeed;

    // Projectile Speed: Statistic indicating how fast a projectile moves. Measured in units per second.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    float ProjectileSpeed;

    // Defense: Value that mitigates the final damage by opposing the attack.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    float Defense;

    // Critical Chance: Probability that an attack will be a critical hit.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    float CriticalChance;

    // Critical Damage: Multiplier to the base damage used for calculating the final damage on a critical hit.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    float CriticalDamage;

    // Melee Range: The distance at which a melee attack hits entities.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    float MeleeRange;

    // Ranged Range: Maximum distance a projectile fired from a ranged weapon travels.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    float RangedRange;

    // Spread: The maximum angle at which a projectile can deviate when fired.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    float Spread;

    // Accuracy: The probability that a projectile will miss or deviate from its intended path.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    float Accuracy;

    // Character Size: Scale of the character in the game, affecting the size of the collider and making it easier or harder to hit.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Miscellaneous")
    float CharacterSize;

    // AOE (Area of Effect Diameter): Size of the area affected by an area attack.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    float AOE;

    // Delay: The time it takes for an ability to start its effect after being cast. Can also define the interval between different effects in the same ability.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    float Delay;

    // Lifesteal: Percentage of damage dealt converted into healing for the player.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    float Lifesteal;

    // Invulnerable Frames: Number of frames in an animation during which the character is immune to all damage.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    float InvulnerableFrames;

    // True Damage: Damage dealt to the enemy's base health, ignoring their resistance or defense.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    float TrueDamage;

    // Damage Over Time (DOT): A multiplier applied to the attack to calculate continuous damage over time.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    float DOTMultiplier;

    // DOT Duration: Duration for how long Damage Over Time lasts before it stops affecting the enemy.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    float DOTDuration;

    // DOT Tick: Interval in seconds between each damage tick of Damage Over Time.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    float DOTTick;

    // Cooldown: Time required for an ability or action to become available again.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    float Cooldown;

    // Healing Amount: Value representing the amount of health restored with an instant healing action.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Healing")
    float HealingAmount;

    // HOT (Healing Over Time): Amount of health healed per tick when the character is under a healing-over-time effect.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Healing")
    float HOTAmount;

    // HOT Tick: Interval in seconds between each healing tick of HOT (Healing Over Time).
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Healing")
    float HOTTick;

    // HOT Duration: Duration of how long the HOT lasts before it stops healing the character.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Healing")
    float HOTDuration;

    // Stun Chance: Probability that an enemy will be stunned upon being attacked.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    float StunChance;

    // Stun Duration: The duration of the stun effect during which the enemy cannot perform actions.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    float StunDuration;

    // Knockback Chance: Probability that an attack will knock back an enemy.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    float KnockbackChance;

    // Knockback Distance: The distance an enemy is pushed back when hit by an attack.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    float KnockbackDistance;

    // On Hit Effect Chance: Probability that an effect will trigger when the player hits the enemy.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    float OnHitEffectChance;

    // On Taking Damage (OTD) Effect Chance: Probability that an effect will trigger when the player takes damage from the enemy.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    float OnTakingDamageEffectChance;
	
};

UCLASS()
class ROGUELIKE_API UBaseCharacterStats : public UObject
{
	GENERATED_BODY()
protected:
	UBaseCharacterStats();
public:
	UPROPERTY(BlueprintReadWrite)
	FSharedCharacterStats CharacterStats;
};
