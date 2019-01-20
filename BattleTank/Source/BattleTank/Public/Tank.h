// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/StaticMeshComponent.h"
#include "Delegates/Delegate.h"
#include "Tank.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE (FTankDelegate);

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	//returns current health as percentage of starting health
	UFUNCTION(BlueprintPure, Category = "Health")
	float GetHealthPercent() const;

	FTankDelegate OnDeath;

private:	
	// Sets default values for this pawn's properties
	ATank();

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const & DamageEvent, class AController * EventInstigator, AActor * DamageCauser) override;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	int32 MaxLife = 100;

	UPROPERTY(VisibleAnywhere, Category = "Setup")
	int32 CurrentHealth = MaxLife;

};
