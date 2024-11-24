// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "StatsManager.generated.h"

UENUM(BlueprintType)
enum class EStatModifierType : uint8
{
	Addition,
	Multiplication,
	Division
};
// Declaración del enum class para los tipos de estadísticas
UENUM(BlueprintType)
enum class EPlayerStatType : uint8
{
    // Health-related stats
    TemporaryHealth,       // Extra health that is used before current health and can exceed maximum health.
    BaseHealth,            // Base health of the character; used as a foundation for calculations.
    MaxHealth,             // Maximum health of the character; healing cannot exceed this value.
    CurrentHealth,         // Current health value of the character; reaching 0 results in death.

    // Movement and attack speed
    MovementSpeed,         // Determines how fast the character moves.
    AttackSpeed,           // Indicates how fast melee weapons are used.
    ProjectileSpeed,       // Indicates how fast ranged projectiles travel.

    // Damage and combat stats
    BaseDamage,            // Base damage value used to calculate final damage dealt.
    AttackValue,           // Used against the opponent's defense to calculate final damage.
    DefenseValue,          // Reduces damage taken by countering the attack value.

    // Critical and luck
    CriticalChance,        // Probability that an attack will be critical.
    CriticalDamage,        // Amount of base damage used for calculating critical hits.
    Luck,                  // Affects other stats (e.g., critical chance, loot rarity, special room spawn).

    // Ranges and accuracy
    MeleeRange,            // Range of melee attacks to determine hit area.
    RangedRange,           // Maximum distance a projectile can travel.
    Spread,                // Maximum deviation angle for projectile shots.
    Accuracy,              // Probability of a projectile deviating.

    // Size and area-related stats
    CharacterSize,         // Scale of the character, affects collider size.
    AreaOfEffectSize,      // Size of the area affected by AoE attacks.
    AreaOfEffectDamage,    // Base damage used for AoE attacks.

    // Projectile-specific stats
    ProjectileCount,       // Number of projectiles fired per shot.
    MaxAmmo,               // Maximum ammo capacity before reloading.
    ReloadTime,            // Time taken to reload when ammo is depleted.
    AmmoConsumption,       // Ammo consumed per shot.
    Penetration,           // Number of enemies a projectile can hit before disappearing.
    LifeSteal,             // Percentage of damage dealt converted into health for the player.

    // Invulnerability and mechanics
    InvulnerableFrames,    // Frames during which the character is immune to damage.
    Bouncing,              // Number of times a projectile can redirect to another enemy after hitting.

    // Damage types and effects
    TrueDamage,            // Damage that ignores resistances and defenses.
    DamageOverTime,        // Fixed damage applied over a specific duration.
    CoolDown,              // Time required for a skill or action to be used again.

    // Healing-related stats
    HealingAmount,			// Amount of health restored.
    HealingTick,			// The interval in seconds at which health is restored over time.// The interval in seconds at which health is restored over time.

    // Damage and resistance types
    DamageType,            // Type of damage dealt (blunt, piercing, fire, etc.).
    ResistanceType,        // Reduction to a specific damage type (blunt, fire, etc.).

    // Stun and knockback
    StunChance,            // Probability of stunning an enemy on hit.
    StunDuration,          // Duration of enemy stun.
    KnockBackChance,       // Probability of pushing an enemy back on hit.
    KnockBackDistance,      // Distance the enemy is pushed back when knocked back.
	
	// Misc
	ExtraBossDamage,
	AvoidAttacksProbability

};

// Declaración de la estructura de estadísticas del jugador
USTRUCT(BlueprintType)
struct FPlayerStatStruct
{
	GENERATED_BODY()

	// Valor actual de la estadística
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stat")
	float Value;

	// Valor que se suma a la estadística por cada stack.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stat")
	float StackValue;

	// Valor que tiene la estadística de forma predeterminada
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stat")
	float BaseValue;

	// Valor máximo para el stat
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stat")
	float MaxValue;

	// Valor por el cual se multiplica la estadística al subir de nivel
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stat")
	float LevelIncreaseMultiplier;

	// Valores aditivos actuales
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stat")
	float AdditiveValues;

	// Valores multiplicativos actuales
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stat")
	float MultiplicativeValues;

	// Valores divisores actuales
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stat")
	float DivisorValues;

};

// Clase que gestiona las estadísticas del jugador
UCLASS(Blueprintable)
class ROGUELIKE_API UStatsManager : public UObject
{
	GENERATED_BODY()

	UStatsManager();

public:
	
	// Mapa para almacenar las estadísticas, utilizando el enum class como clave
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	TMap<EPlayerStatType, FPlayerStatStruct> StatsMap;

	// Nivel actual del jugador
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	int Level = 1;

	// Experiencia actual del jugador, cada vez que llega a 100, se sube un nivel y esta variable vuelve a 0
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	int CurrentLevelExperience = 0;

	// Monedas del jugador, en nuestro caso órganos.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	int CoinsBalance = 0;

	// Función para actualizar el valor de una estadística
	UFUNCTION(BlueprintCallable, Category = "Stats")
	void UpdateStatValue(EPlayerStatType StatType,EStatModifierType StatModifier, float Delta);

	// Función para obtener la estructura de una estadística específica
	UFUNCTION(BlueprintCallable, Category = "Stats")
	FPlayerStatStruct GetStat(EPlayerStatType StatType) const;

	UFUNCTION(BlueprintCallable, Category = "Stats")
	float GetStatValueByFormula(EPlayerStatType StatType) const;

	UFUNCTION(BlueprintCallable, Category = "Stats")
	void SetValuesOnBegin();

	UFUNCTION(BlueprintCallable, Category = "Stats")
	void AddExperience(float Delta);

	UFUNCTION(BlueprintCallable, Category = "Stats")
	void AddBalance(float Delta);

	void SetDefaultValues();
};
