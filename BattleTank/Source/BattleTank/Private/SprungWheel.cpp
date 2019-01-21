// Fill out your copyright notice in the Description page of Project Settings.

#include "SprungWheel.h"
#include "Classes/PhysicsEngine/PhysicsConstraintComponent.h"
#include "Classes/Components/StaticMeshComponent.h"


// Sets default values
ASprungWheel::ASprungWheel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Wheel = CreateDefaultSubobject<UStaticMeshComponent>(FName("Wheel"));
	Mass = CreateDefaultSubobject<UStaticMeshComponent>(FName("Mass"));
	PhysicsContraint = CreateDefaultSubobject<UPhysicsConstraintComponent>(FName("Physics Constraint"));
	
	SetRootComponent(PhysicsContraint);
	Mass->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	Wheel->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	}

// Called when the game starts or when spawned
void ASprungWheel::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ASprungWheel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

