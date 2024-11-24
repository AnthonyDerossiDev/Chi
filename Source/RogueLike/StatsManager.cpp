// Fill out your copyright notice in the Description page of Project Settings.


#include "StatsManager.h"

// Constructor
UStatsManager::UStatsManager()
{
	// Llenar el mapa con todos los EPlayerStatType
	for (int32 StatIndex = 0; StatIndex < static_cast<int32>(EPlayerStatType::AvoidAttacksProbability) + 1; ++StatIndex)
	{
		EPlayerStatType StatType = static_cast<EPlayerStatType>(StatIndex);
        
		FPlayerStatStruct StatStruct;
		StatStruct.Value = 0.0f; // Valor inicial, puedes personalizarlo según lo necesites
		StatStruct.BaseValue = 0.0f; // Puedes cambiar este valor si lo deseas
		StatStruct.LevelIncreaseMultiplier = 0.0f; // Ajusta este valor también si lo deseas
		StatStruct.AdditiveValues = 0.0f; // Ajusta este valor también si lo deseas
		StatStruct.MultiplicativeValues = 1.0f; // Ajusta este valor también si lo deseas
		StatStruct.DivisorValues = 1.0f; // Ajusta este valor también si lo deseas
		StatStruct.MaxValue = 100.0f;

		// Insertar el nuevo stat en el mapa
		StatsMap.Add(StatType, StatStruct);
	}
	SetDefaultValues();
}

// Actualiza el valor de una estadística específica
void UStatsManager::UpdateStatValue(EPlayerStatType StatType, EStatModifierType StatModifier,float Delta)
{
	if (StatsMap.Contains(StatType))
	{
		StatsMap[StatType].Value += Delta;
		switch (StatModifier)
		{
			case EStatModifierType::Addition:
				StatsMap[StatType].AdditiveValues += Delta;
				//GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, FString::Printf(TEXT("%f"), StatsMap[StatType].AdditiveValues));
				//GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, FString::Printf(TEXT("%f"), Delta));
				break;
			case EStatModifierType::Multiplication:
				StatsMap[StatType].MultiplicativeValues += Delta;
				break;
			case EStatModifierType::Division:
				StatsMap[StatType].DivisorValues += Delta;
				break;
		}
	}
}

// Devuelve la estructura de una estadística específica
FPlayerStatStruct UStatsManager::GetStat(EPlayerStatType StatType) const
{
	if (const FPlayerStatStruct* Stat = StatsMap.Find(StatType))
	{
		return *Stat;
	}

	// Devuelve un valor por defecto si la estadística no existe
	return FPlayerStatStruct();
}

float UStatsManager::GetStatValueByFormula(EPlayerStatType StatType) const
{
	// EstadísticaBase * Σ ValoresMultiplicativos / Σ Valores divisores + Σ Valores aditivos
	float StatValue = 0.0f;
	if (const FPlayerStatStruct* Stat = StatsMap.Find(StatType))
	{
		//StatValue = Stat->BaseValue * Stat->MultiplicativeValues / Stat->DivisorValues + Stat->AdditiveValues;
		StatValue = (Stat->BaseValue + (Stat->LevelIncreaseMultiplier * Level)) * Stat->MultiplicativeValues / Stat->DivisorValues + Stat->AdditiveValues;

		if(Stat->MaxValue != -1 && StatValue >= Stat->MaxValue) StatValue = Stat->MaxValue;
	}
	return StatValue;
}

void UStatsManager::SetValuesOnBegin()
{
	SetDefaultValues();
}

void UStatsManager::AddExperience(float Delta)
{
	float DeltaDifference = Delta;
	if(CurrentLevelExperience + Delta >= 100)
	{
		Level++;
		DeltaDifference = CurrentLevelExperience + Delta - 100;
		CurrentLevelExperience = 0;
	}
	CurrentLevelExperience += DeltaDifference;
}

void UStatsManager::AddBalance(float Delta)
{
	CoinsBalance += Delta;
}

void UStatsManager::SetDefaultValues()
{
	// Salud
	StatsMap[EPlayerStatType::MaxHealth].BaseValue = InitialHP;
	StatsMap[EPlayerStatType::MaxHealth].MaxValue = -1;
	StatsMap[EPlayerStatType::CurrentHealth].BaseValue = InitialHP;
	StatsMap[EPlayerStatType::CurrentHealth].MaxValue = -1;

	// Regeneración de salud
	StatsMap[EPlayerStatType::HealingAmount].BaseValue = InitialHPRegeneration;

	// Velocidad de ataque
	StatsMap[EPlayerStatType::ProjectileSpeed].BaseValue = InitialProjectileSpeed;
	
	//
	// if(StatsMap[EPlayerStatType::CriticalDamage].BaseValue == 0) StatsMap[EPlayerStatType::CriticalDamage].BaseValue = 2.0f;
	// if(StatsMap[EPlayerStatType::ProjectileSpeed].BaseValue == 0) StatsMap[EPlayerStatType::ProjectileSpeed].BaseValue = 1.0f;
	// if(StatsMap[EPlayerStatType::StunDuration].BaseValue == 0) StatsMap[EPlayerStatType::StunDuration].BaseValue = 1.0f;
	// if(StatsMap[EPlayerStatType::HealingTick].BaseValue == 0) StatsMap[EPlayerStatType::HealingTick].BaseValue = 1.0f;
}

void UStatsManager::RecoverChiiHPInstant(float MaxHPPercentage)
{
	float MaxHealth = StatsMap[EPlayerStatType::MaxHealth].BaseValue;
	float TargetHealth = MaxHPPercentage*MaxHealth/100;
	
	StatsMap[EPlayerStatType::CurrentHealth].AdditiveValues = TargetHealth - StatsMap[EPlayerStatType::CurrentHealth].BaseValue;
}


