// Fill out your copyright notice in the Description page of Project Settings.


#include "StatsManager.h"

#include "StatsManager.h"

// Constructor
UStatsManager::UStatsManager()
{
	// Llenar el mapa con todos los EPlayerStatType
	for (int32 StatIndex = 0; StatIndex < static_cast<int32>(EPlayerStatType::KnockBackDistance) + 1; ++StatIndex)
	{
		EPlayerStatType StatType = static_cast<EPlayerStatType>(StatIndex);
        
		FPlayerStatStruct StatStruct;
		StatStruct.Value = 0.0f; // Valor inicial, puedes personalizarlo según lo necesites
		StatStruct.BaseValue = 1.0f; // Puedes cambiar este valor si lo deseas
		StatStruct.IncreaseMultiplier = 0.1f; // Ajusta este valor también si lo deseas

		// Insertar el nuevo stat en el mapa
		StatsMap.Add(StatType, StatStruct);
	}
}

// Actualiza el valor de una estadística específica
void UStatsManager::UpdateStatValue(EPlayerStatType StatType, float Delta)
{
	if (StatsMap.Contains(StatType))
	{
		StatsMap[StatType].Value += Delta;
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
