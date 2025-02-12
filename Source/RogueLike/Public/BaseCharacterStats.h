// Parent class that serves to store and return the stats of characters, such as enemies and player-controlled characters.
// The class that manages enemy stats will inherit from this one, as well as the class that manages the stats of player-controlled characters.
// This is because there are several common stats, but not all of them.
// Every stat shown in this class is shared among different characters, whether they are enemies or player-controlled characters.

#pragma once

#include "CoreMinimal.h"

USTRUCT(BlueprintType)
struct FCharacterStats
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

    // Luck: A value that modifies other stats. The way it modifies depends on the object. For the character, it modifies critical chance and can affect money, item rarity, or special room appearance chances.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Miscellaneous")
    float Luck;

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

    // Penetration: The value indicating how many enemies a projectile hits before disappearing.
    // 1 means it disappears after hitting the first enemy.
    // 2 means it passes through the first enemy, applies its effect, and then continues to another enemy.
    // Higher values allow for more enemies to be hit.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    int32 Penetration;

    // Lifesteal: Percentage of damage dealt converted into healing for the player.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    float Lifesteal;

    // Invulnerable Frames: Number of frames in an animation during which the character is immune to all damage.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    float InvulnerableFrames;

    // Rebound: Indicates if a projectile redirects to another enemy after hitting the first one. 
    // 0 means it disappears after hitting one enemy.
    // 1 means it redirects to the closest enemy after hitting one.
    // 2 means it can redirect up to two times.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    int32 Rebound;

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

    // Out of Combat Regeneration: Health that regenerates after a defined time period (Out of Combat Delay) without taking damage.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Healing")
    float OutOfCombatRegeneration;

    // Out of Combat Delay: Time in seconds to wait before triggering out-of-combat health regeneration.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Healing")
    float OutOfCombatDelay;

    // Madness: The amount of madness added to the game when this entity is killed by the player.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Miscellaneous")
    float Madness;

    // Knowledge: The amount of knowledge added to the game when this entity is killed by the player.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Miscellaneous")
    float Knowledge;

    // Reaction Interval: Time window (in seconds) within which an enemy decides which ability to use.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    float ReactionInterval;

    // On Hit Effect Chance: Probability that an effect will trigger when the player hits the enemy.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    float OnHitEffectChance;

    // On Taking Damage (OTD) Effect Chance: Probability that an effect will trigger when the player takes damage from the enemy.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    float OnTakingDamageEffectChance;

	FCharacterStats():
	BaseHealth(0),
	MaxHealth(0),
	CurrentHealth(0),
	TemporaryHealth(0),
	MovementSpeed(0),
	Attack(0),
	AttackSpeed(0),
	ProjectileSpeed(0),
	Defense(0),
	CriticalChance(0),
    CriticalDamage(0),
	Luck(0),
	MeleeRange(0),
	RangedRange(0),
	Spread(0),
	Accuracy(0),
	CharacterSize(0), AOE(0),
	Delay(0),
	Penetration(0),
	Lifesteal(0),
	InvulnerableFrames(0),
	Rebound(0), TrueDamage(0),
	DOTMultiplier(0),
	DOTDuration(0),
	DOTTick(0),
	Cooldown(0),
	HealingAmount(0),
	HOTAmount(0),
	HOTTick(0),
	HOTDuration(0),
	StunChance(0),
	StunDuration(0),
	KnockbackChance(0),
	KnockbackDistance(0),
	OutOfCombatRegeneration(0),
	OutOfCombatDelay(0),
	Madness(0), Knowledge(0),
	ReactionInterval(0),
	OnHitEffectChance(0),
	OnTakingDamageEffectChance(0)                   
	{
	}
};


class ROGUELIKE_API BaseCharacterStats
{
public:
	BaseCharacterStats();
	~BaseCharacterStats();
};
