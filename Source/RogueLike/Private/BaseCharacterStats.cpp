// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseCharacterStats.h"

UBaseCharacterStats::UBaseCharacterStats()
{
	// Asignación de valores predeterminados a las estadísticas de CharacterStats

    CharacterStats.BaseHealth = 100.0f;
    CharacterStats.MaxHealth = 100.0f;
    CharacterStats.CurrentHealth = CharacterStats.MaxHealth;  // Inicialmente, la salud actual es igual a la salud máxima
    CharacterStats.TemporaryHealth = 0.0f;

    // Movement stats
    CharacterStats.MovementSpeed = 600.0f;  // Valor típico para un personaje en movimiento

    // Combat stats
    CharacterStats.Attack = 20.0f;
    CharacterStats.AttackSpeed = 1.0f;  // Un ataque por segundo
    CharacterStats.ProjectileSpeed = 1000.0f;  // Velocidad de proyectiles
    CharacterStats.Defense = 10.0f;
    CharacterStats.CriticalChance = 0.1f;  // 10% de probabilidad de crítico
    CharacterStats.CriticalDamage = 1.5f;  // 50% más de daño en un crítico
    CharacterStats.MeleeRange = 100.0f;  // Rango de ataque cuerpo a cuerpo
    CharacterStats.RangedRange = 500.0f;  // Rango de ataque a distancia
    CharacterStats.Spread = 5.0f;  // Ángulo máximo de dispersión de proyectiles
    CharacterStats.Accuracy = 0.9f;  // 90% de precisión
    CharacterStats.AOE = 200.0f;  // Área de efecto de un ataque
    CharacterStats.Delay = 0.0f;  // Sin retraso inicial
    CharacterStats.Lifesteal = 0.05f;  // 5% de vida robada
    CharacterStats.InvulnerableFrames = 0.2f;  // 0.2 segundos de invulnerabilidad
    CharacterStats.TrueDamage = 0.0f;  // No hay daño verdadero por defecto
    CharacterStats.DOTMultiplier = 1.0f;  // No hay multiplicador DOT por defecto
    CharacterStats.DOTDuration = 3.0f;  // 3 segundos de daño por tiempo
    CharacterStats.DOTTick = 1.0f;  // Daño cada segundo
    CharacterStats.Cooldown = 1.0f;  // Un segundo de recarga
    CharacterStats.HealingAmount = 20.0f;  // 20 de curación instantánea
    CharacterStats.HOTAmount = 5.0f;  // 5 de curación por segundo (Healing Over Time)
    CharacterStats.HOTTick = 1.0f;  // Curación cada segundo
    CharacterStats.HOTDuration = 5.0f;  // 5 segundos de curación en el tiempo
    CharacterStats.StunChance = 0.1f;  // 10% de probabilidad de aturdir
    CharacterStats.StunDuration = 2.0f;  // 2 segundos de aturdimiento
    CharacterStats.KnockbackChance = 0.2f;  // 20% de probabilidad de derrape
    CharacterStats.KnockbackDistance = 200.0f;  // Distancia de derrape
    CharacterStats.OnHitEffectChance = 0.15f;  // 15% de probabilidad de efectos al golpear
    CharacterStats.OnTakingDamageEffectChance = 0.1f;  // 10% de probabilidad de efectos al recibir daño
}
