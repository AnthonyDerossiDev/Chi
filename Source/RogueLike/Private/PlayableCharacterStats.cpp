// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayableCharacterStats.h"

UPlayableCharacterStats::UPlayableCharacterStats()
{
	PlayerStats.Luck = 0.0f;
	PlayerStats.Penetration = 1.0f;
	PlayerStats.Rebound = 0.0f;
	PlayerStats.OutOfCombatRegeneration = 0.0f;
	PlayerStats.OutOfCombatDelay = 1.0f;
}
