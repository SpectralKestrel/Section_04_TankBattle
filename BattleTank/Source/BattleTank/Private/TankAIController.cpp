// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "Engine/World.h"
#include "TankAIController.h"
//Depends on movement component via pathfinding system


void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = Cast<ATank>(GetPawn());

	if (ensure(PlayerTank))
	{
	// move towards player
	MoveToActor(PlayerTank, AcceptanceRadius); //TODO check radius is in cm
	//aim at player
	ControlledTank->AimAt(PlayerTank->GetActorLocation());
	   	
	ControlledTank->Fire(); //TODO limit firing rate
	}
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}


