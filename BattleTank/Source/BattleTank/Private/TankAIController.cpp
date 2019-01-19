// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Engine/World.h"
#include "TankAimingComponent.h"
//Depends on movement component via pathfinding system


void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = (GetWorld()->GetFirstPlayerController()->GetPawn());
	auto AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	
	if (!ensure(PlayerTank && AimingComponent)) { return; }
	{
	// move towards player
	MoveToActor(PlayerTank, AcceptanceRadius); //TODO check radius is in cm
	//aim at player
	AimingComponent->AimAt(PlayerTank->GetActorLocation());
   	
	//if aiming or locked
	if (AimingComponent->GetFiringState() == EFiringStatus::Locked)
	{
		AimingComponent->Fire(); //TODO limit firing rate
	}
	}
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

}


