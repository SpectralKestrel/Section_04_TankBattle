// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

class UTankAimingComponent;

UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	void BeginPlay() override;
	//how close can the AI get to the player
	UPROPERTY(EditDefaultsOnly)
	float AcceptanceRadius = 8000;

private:
	virtual void Tick(float DeltaTime) override;
	

};
