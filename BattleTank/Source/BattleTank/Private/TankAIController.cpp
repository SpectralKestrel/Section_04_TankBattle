// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Engine/World.h"
#include "TankAimingComponent.h"
#include "Classes/GameFramework/Pawn.h"
#include "Tank.h"
//Depends on movement component via pathfinding system


void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = (GetWorld()->GetFirstPlayerController()->GetPawn());
	auto AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	
	if (!(PlayerTank && AimingComponent)) { return; }
	{
	// move towards player
	MoveToActor(PlayerTank, AcceptanceRadius); 
	//aim at player
	AimingComponent->AimAt(PlayerTank->GetActorLocation());
   	
	//if aiming or locked
	if (AimingComponent->GetFiringState() == EFiringStatus::Locked)
	{
		AimingComponent->Fire(); 
	}
	}
}

void ATankAIController::SetPawn(APawn * InPawn)
{
	Super::SetPawn(InPawn);
	if (InPawn)
	{
		auto PossessedTank = Cast<ATank>(InPawn);
		if (!ensure(PossessedTank)) { return; }
		//subscribe our local method to the tanks death event
		PossessedTank->OnDeath.AddUniqueDynamic(this, &ATankAIController::OnPossessedTankDeath);
	}
}

void ATankAIController::OnPossessedTankDeath()
{
	UE_LOG(LogTemp, Warning, TEXT("Recieved!"))
		auto ThisTank = this->GetPawn();
		ThisTank->DetachFromControllerPendingDestroy();
	}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

}


