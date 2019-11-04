// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"
#include "BattleTank.h"
#include "Tank.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = Cast<ATank>(GetPawn());

	if (PlayerTank)
	{		
		// TODO Move towards player

		// Aim At Player
		ControlledTank->AimAt(PlayerTank->GetActorLocation());
		// Fire if ready
		ControlledTank->Fire(); // TODO Limit Firing Rate

		
	}
}