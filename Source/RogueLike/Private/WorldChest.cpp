// Fill out your copyright notice in the Description page of Project Settings.

#include "RogueLike/Public/WorldChest.h"
#include "RogueLike/StatsManager.h"


// Sets default values
AWorldChest::AWorldChest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AWorldChest::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWorldChest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

EItemRarity AWorldChest::GetItemBasedOnLuck(float Luck)
{
	float AdjustedChances[static_cast<int32>(EItemRarity::Purple)];

	// Ajustar probabilidades según Luck
	for (int i = 0; i < static_cast<int32>(EItemRarity::Purple) + 1; i++)
	{
		AdjustedChances[i] = BaseChances[i];
	}
    
	// Suerte afecta negativamente a "Normal" y positivamente a las demás
	AdjustedChances[0] -= Luck * 0.5; // Reduce probabilidad de Normal
	AdjustedChances[1] += Luck * 0.3; // Aumenta probabilidad de Bueno
	AdjustedChances[2] += Luck * 0.15; // Aumenta probabilidad de Épico
	AdjustedChances[3] += Luck * 0.05; // Aumenta probabilidad de Legendario

	// Normalizar las probabilidades para asegurarnos de que sumen 100
	float TotalChance = 0.0;
	for (int i = 0; i < 4; i++) {
		TotalChance += AdjustedChances[i];
	}
	for (int i = 0; i < 4; i++) {
		AdjustedChances[i] = (AdjustedChances[i] / TotalChance) * 100.0;
	}

	// Generar un número aleatorio entre 0 y 100
	float RandomRoll = FMath::RandRange(0.0, 100.0);
	// Mostrar RandomRoll en pantalla
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("RandomRoll: %f"), RandomRoll));
	}

	// Determinar el resultado basado en las probabilidades ajustadas
	float CumulativeChance = 0.0;
	for (int i = 0; i < 4; i++) {
		CumulativeChance += AdjustedChances[i];
		if (RandomRoll <= CumulativeChance) {
			return static_cast<EItemRarity>(i);
		}
	}

	// Por seguridad, regresar Normal si algo sale mal (esto no debería ocurrir)
	return EItemRarity::White;
}

