// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTurret.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent), hidecategories = ("Collision"))
class BATTLETANK_API UTankTurret : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	//-1 is max down, +1 is max up movement
	void Rotate(float RelativeSpeed);

private:
	UPROPERTY(EditDefaultsOnly, category = Setup)
		float MaxDegreesPerSecond = 7.5; // sensible default
	
	
};
