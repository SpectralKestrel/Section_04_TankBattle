// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TankBarrel.h"
#include "Projectile.h"
#include "Engine/World.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

float ATank::TakeDamage(float DamageAmount, FDamageEvent const & DamageEvent, AController * EventInstigator, AActor * DamageCauser)
{
	int32 DamagePoints = FPlatformMath::RoundToInt(DamageAmount);
	int32 ActualDamage = FMath::Clamp(DamagePoints, 0, CurrentHealth);
	CurrentHealth -= ActualDamage;
	if (CurrentHealth <= 0)
	{
		OnDeath.Broadcast();
	}
	return ActualDamage;
}
float ATank::GetHealthPercent() const
{
	return(float)CurrentHealth / (float)MaxLife;
}