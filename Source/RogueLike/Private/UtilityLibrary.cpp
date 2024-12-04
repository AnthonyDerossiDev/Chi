// Fill out your copyright notice in the Description page of Project Settings.


#include "UtilityLibrary.h"

class UNavigationPath;

bool UUtilityLibrary::IsRunningInEditor()
{
#if WITH_EDITOR
	return GEngine && GEngine->IsEditor(); // True if in editor mode
#else
	return false; // Not in editor
#endif
}

bool UUtilityLibrary::IsPositionReachable(FVector Position)
{
		//FVector PathStart = GetPawn()->GetActorLocation();
		//UNavigationPath* NavPath = UNavigationSystem::FindPathToLocationSynchronously(GetWorld(), PathStart, Position, NULL);
		return false;
		// if (!NavPath)
		// 	return false;
		//
		// return !NavPath->IsPartial();
}
