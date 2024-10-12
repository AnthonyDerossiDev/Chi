// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DungeonTypes.generated.h"

// Enumeración para definir los tipos de sala en la mazmorra
UENUM(BlueprintType)
enum E_RoomType {
	EMPTY,    // Espacio vacío (sin sala)
	ENTRY,    // Sala de entrada
	COMBAT,   // Sala deBlueprintType combate
	SHOP,     // Tienda
	REWARD,   // Sala de recompensa
	SACRIFICE,
	EXIT      // Sala de salida
};

// Enumeración para las posiciones de las puertas
enum class E_DoorType {
	UP,    // Puerta arriba
	DOWN,  // Puerta abajo
	LEFT,  // Puerta izquierda
	RIGHT  // Puerta derecha
};


/**
 * 
 */
UCLASS()
class ROGUELIKE_API UDungeonTypes : public UObject
{
	GENERATED_BODY()
	
};
