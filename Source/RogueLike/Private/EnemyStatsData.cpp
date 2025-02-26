// // // Copyright (c) 2025 BrokenQuill Studios. All rights reserved. // // This game and its associated assets (including code, graphics, sounds, and other media)  // are the intellectual property of BrokenQuill Studios. All rights to the content are  // reserved by BrokenQuill Studios. // // This game was developed using the Unreal Engine, which is a product of Epic Games, Inc.  // Unreal Engine is a trademark or registered trademark of Epic Games, Inc. in the United States  // and elsewhere. // // This software and all its components are provided "as is" without warranty of any kind,  // either express or implied, including but not limited to the warranties of merchantability,  // fitness for a particular purpose, or noninfringement.  // // In no event shall BrokenQuill Studios or its contributors be liable for any damages  // arising from the use of this software. // // For inquiries, support, or licensing, please contact BrokenQuill Studios at:  // https://www.brokenquillstudio.com  //


#include "EnemyStatsData.h"

UEnemyStatsData::UEnemyStatsData()
{
	// Inicialización del TMap con el nuevo nombre
    TMap<EEnemyStatType, FEnemyStat> DefaultStats;

    // Crear e inicializar FEnemyStat para cada tipo de estadística
	DefaultStats.Add(EEnemyStatType::BaseHealth, FEnemyStat{100.f, 1.f});
	DefaultStats.Add(EEnemyStatType::MaxHealth, FEnemyStat{100.f, 1.f});
	DefaultStats.Add(EEnemyStatType::CurrentHealth, FEnemyStat{100.f, 1.f});
	DefaultStats.Add(EEnemyStatType::TemporaryHealth, FEnemyStat{0.f, 0.f});
	DefaultStats.Add(EEnemyStatType::MovementSpeed, FEnemyStat{600.f, 10.f});
	DefaultStats.Add(EEnemyStatType::Attack, FEnemyStat{10.f, 1.f});
	DefaultStats.Add(EEnemyStatType::AttackSpeed, FEnemyStat{1.f, 0.1f});
	DefaultStats.Add(EEnemyStatType::ProjectileSpeed, FEnemyStat{500.f, 5.f});
	DefaultStats.Add(EEnemyStatType::Defense, FEnemyStat{5.f, 1.f});
	DefaultStats.Add(EEnemyStatType::CriticalChance, FEnemyStat{0.1f, 0.01f});
	DefaultStats.Add(EEnemyStatType::CriticalDamage, FEnemyStat{1.5f, 0.1f});
	DefaultStats.Add(EEnemyStatType::RangedRange, FEnemyStat{1000.f, 50.f});
	DefaultStats.Add(EEnemyStatType::Spread, FEnemyStat{0.1f, 0.01f});
	DefaultStats.Add(EEnemyStatType::Accuracy, FEnemyStat{0.9f, 0.05f});
	DefaultStats.Add(EEnemyStatType::AOESize, FEnemyStat{200.f, 10.f});
	DefaultStats.Add(EEnemyStatType::AOEDamage, FEnemyStat{50.f, 5.f});
	DefaultStats.Add(EEnemyStatType::Delay, FEnemyStat{0.2f, 0.02f});
	DefaultStats.Add(EEnemyStatType::Lifesteal, FEnemyStat{0.05f, 0.f});
	DefaultStats.Add(EEnemyStatType::InvulnerableFrames, FEnemyStat{0.f, 0.f});
	DefaultStats.Add(EEnemyStatType::TrueDamage, FEnemyStat{10.f, 1.f});
	DefaultStats.Add(EEnemyStatType::DOTMultiplier, FEnemyStat{1.f, 0.f});
	DefaultStats.Add(EEnemyStatType::DOTDuration, FEnemyStat{5.f, 0.f});
	DefaultStats.Add(EEnemyStatType::DOTTick, FEnemyStat{1.f, 0.f});
	DefaultStats.Add(EEnemyStatType::Cooldown, FEnemyStat{1.f, 0.f});
	DefaultStats.Add(EEnemyStatType::StunChance, FEnemyStat{0.1f, 0.01f});
	DefaultStats.Add(EEnemyStatType::StunDuration, FEnemyStat{2.f, 0.1f});
	DefaultStats.Add(EEnemyStatType::KnockbackChance, FEnemyStat{0.1f, 0.01f});
	DefaultStats.Add(EEnemyStatType::KnockbackDistance, FEnemyStat{200.f, 10.f});
	DefaultStats.Add(EEnemyStatType::OnHitEffectChance, FEnemyStat{0.2f, 0.02f});
	DefaultStats.Add(EEnemyStatType::OnTakingDamageEffectChance, FEnemyStat{0.2f, 0.02f});
	DefaultStats.Add(EEnemyStatType::CharacterSize, FEnemyStat{1.f, 0.1f});
	DefaultStats.Add(EEnemyStatType::ReactionInterval, FEnemyStat{1.f, 0.1f});
	
	EnemyStatsBaseMap = DefaultStats;
	
}
