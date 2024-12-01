// Fill out your copyright notice in the Description page of Project Settings.


#include "UtilityLibrary.h"

bool UUtilityLibrary::IsRunningInEditor()
{
#if WITH_EDITOR
	return GEngine && GEngine->IsEditor(); // True if in editor mode
#else
	return false; // Not in editor
#endif
}
