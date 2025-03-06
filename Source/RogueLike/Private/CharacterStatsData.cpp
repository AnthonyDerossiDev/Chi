// // // Copyright (c) 2025 BrokenQuill Studios. All rights reserved. // // This game and its associated assets (including code, graphics, sounds, and other media)  // are the intellectual property of BrokenQuill Studios. All rights to the content are  // reserved by BrokenQuill Studios. // // This game was developed using the Unreal Engine, which is a product of Epic Games, Inc.  // Unreal Engine is a trademark or registered trademark of Epic Games, Inc. in the United States  // and elsewhere. // // This software and all its components are provided "as is" without warranty of any kind,  // either express or implied, including but not limited to the warranties of merchantability,  // fitness for a particular purpose, or noninfringement.  // // In no event shall BrokenQuill Studios or its contributors be liable for any damages  // arising from the use of this software. // // For inquiries, support, or licensing, please contact BrokenQuill Studios at:  // https://www.brokenquillstudio.com  //


#include "CharacterStatsData.h"

UCharacterStatsData::UCharacterStatsData()
{
	// Inicialización del TMap con el nuevo nombre
    TMap<ECharacterStatType, FStat> DefaultStats;

	// Crear e inicializar FStat para cada tipo de estadística
	DefaultStats.Add(ECharacterStatType::BaseHealth, FStat{100.f, 100.f, 1.2f, 0.0f, 1.0f, 1.0f});
	DefaultStats.Add(ECharacterStatType::MaxHealth, FStat{100.f, 100.f, 1.2f, 0.0f, 1.0f, 1.0f});
	DefaultStats.Add(ECharacterStatType::CurrentHealth, FStat{100.f, 100.f, 1.2f, 0.0f, 1.0f, 1.0f});
	DefaultStats.Add(ECharacterStatType::TemporaryHealth, FStat{0.f, 0.f, 1.2f, 0.0f, 1.0f, 1.0f});
	DefaultStats.Add(ECharacterStatType::MovementSpeed, FStat{600.f, 600.f, 1.2f, 0.0f, 1.0f, 1.0f});
	DefaultStats.Add(ECharacterStatType::Attack, FStat{10.f, 10.f, 1.2f, 0.0f, 1.0f, 1.0f});
	DefaultStats.Add(ECharacterStatType::AttackSpeed, FStat{1.f, 1.f, 1.2f, 0.0f, 1.0f, 1.0f});
	DefaultStats.Add(ECharacterStatType::ProjectileSpeed, FStat{500.f, 500.f, 1.2f, 0.0f, 1.0f, 1.0f});
	DefaultStats.Add(ECharacterStatType::Defense, FStat{5.f, 5.f, 1.2f, 0.0f, 1.0f, 1.0f});
	DefaultStats.Add(ECharacterStatType::CriticalChance, FStat{0.1f, 0.1f, 1.2f, 0.0f, 1.0f, 1.0f});
	DefaultStats.Add(ECharacterStatType::RangedCriticalDamage, FStat{1.5f, 1.5f, 1.2f, 0.0f, 1.0f, 1.0f});
	DefaultStats.Add(ECharacterStatType::MeleeCriticalDamage, FStat{1.5f, 1.5f, 1.2f, 0.0f, 1.0f, 1.0f});
	DefaultStats.Add(ECharacterStatType::RangedRange, FStat{1000.f, 1000.f, 1.2f, 0.0f, 1.0f, 1.0f});
	DefaultStats.Add(ECharacterStatType::Spread, FStat{0.1f, 0.1f, 1.2f, 0.0f, 1.0f, 1.0f});
	DefaultStats.Add(ECharacterStatType::Accuracy, FStat{0.9f, 0.9f, 1.2f, 0.0f, 1.0f, 1.0f});
	DefaultStats.Add(ECharacterStatType::AOESize, FStat{200.f, 200.f, 1.2f, 0.0f, 1.0f, 1.0f});
	DefaultStats.Add(ECharacterStatType::AOEDamage, FStat{50.f, 50.f, 1.2f, 0.0f, 1.0f, 1.0f});
	DefaultStats.Add(ECharacterStatType::Delay, FStat{0.2f, 0.2f, 1.2f, 0.0f, 1.0f, 1.0f});
	DefaultStats.Add(ECharacterStatType::Lifesteal, FStat{0.05f, 0.05f, 1.2f, 0.0f, 1.0f, 1.0f});
	DefaultStats.Add(ECharacterStatType::InvulnerableFrames, FStat{0.f, 0.f, 1.2f, 0.0f, 1.0f, 1.0f});
	DefaultStats.Add(ECharacterStatType::TrueDamage, FStat{10.f, 10.f, 1.2f, 0.0f, 1.0f, 1.0f});
	DefaultStats.Add(ECharacterStatType::DOTMultiplier, FStat{1.f, 1.f, 1.2f, 0.0f, 1.0f, 1.0f});
	DefaultStats.Add(ECharacterStatType::DOTDuration, FStat{5.f, 5.f, 1.2f, 0.0f, 1.0f, 1.0f});
	DefaultStats.Add(ECharacterStatType::DOTTick, FStat{1.f, 1.f, 1.2f, 0.0f, 1.0f, 1.0f});
	DefaultStats.Add(ECharacterStatType::Cooldown, FStat{1.f, 1.f, 1.2f, 0.0f, 1.0f, 1.0f});
	DefaultStats.Add(ECharacterStatType::HealingAmount, FStat{50.f, 50.f, 1.2f, 0.0f, 1.0f, 1.0f});
	DefaultStats.Add(ECharacterStatType::HOTAmount, FStat{5.f, 5.f, 1.2f, 0.0f, 1.0f, 1.0f});
	DefaultStats.Add(ECharacterStatType::HOTTick, FStat{1.f, 1.f, 1.2f, 0.0f, 1.0f, 1.0f});
	DefaultStats.Add(ECharacterStatType::HOTDuration, FStat{10.f, 10.f, 1.2f, 0.0f, 1.0f, 1.0f});
	DefaultStats.Add(ECharacterStatType::StunChance, FStat{0.1f, 0.1f, 1.2f, 0.0f, 1.0f, 1.0f});
	DefaultStats.Add(ECharacterStatType::StunDuration, FStat{2.f, 2.f, 1.2f, 0.0f, 1.0f, 1.0f});
	DefaultStats.Add(ECharacterStatType::KnockbackChance, FStat{0.1f, 0.1f, 1.2f, 0.0f, 1.0f, 1.0f});
	DefaultStats.Add(ECharacterStatType::KnockbackDistance, FStat{200.f, 200.f, 1.2f, 0.0f, 1.0f, 1.0f});
	DefaultStats.Add(ECharacterStatType::OnHitEffectChance, FStat{0.2f, 0.2f, 1.2f, 0.0f, 1.0f, 1.0f});
	DefaultStats.Add(ECharacterStatType::OnTakingDamageEffectChance, FStat{0.2f, 0.2f, 1.2f, 0.0f, 1.0f, 1.0f});
	DefaultStats.Add(ECharacterStatType::CharacterSize, FStat{1.f, 1.f, 1.2f, 0.0f, 1.0f, 1.0f});
	DefaultStats.Add(ECharacterStatType::Luck, FStat{0.05f, 0.05f, 1.2f, 0.0f, 1.0f, 1.0f});
	DefaultStats.Add(ECharacterStatType::Penetration, FStat{0.f, 0.f, 1.2f, 0.0f, 1.0f, 1.0f});
	DefaultStats.Add(ECharacterStatType::Rebound, FStat{0.f, 0.f, 1.2f, 0.0f, 1.0f, 1.0f});
	DefaultStats.Add(ECharacterStatType::OutOfCombatRegeneration, FStat{5.f, 5.f, 1.2f, 0.0f, 1.0f, 1.0f});
	DefaultStats.Add(ECharacterStatType::OutOfCombatDelay, FStat{10.f, 10.f, 1.2f, 0.0f, 1.0f, 1.0f});


    // Asignar el TMap a la variable correspondiente con el nuevo nombre
    PlayerStatsBaseMap = DefaultStats;
}
