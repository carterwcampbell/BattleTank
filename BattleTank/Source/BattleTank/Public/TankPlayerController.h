// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "GameFramework/PlayerController.h"
#include "Engine/World.h"
#include "TankPlayerController.generated.h" // Must be the last include

class ATank;

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

    public:
	    ATank* GetControlledTank() const;

		void BeginPlay() override;

		void Tick( float DeltaSeconds ) override;

		void AimTowardsCrosshair();

		bool GetSightRayHitLocation(FVector &HitLocation) const;

		bool GetLookDirection(FVector2D ScreenLocation, FVector &LookDirection) const;

		bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;

	private:
		UPROPERTY(EditDefaultsOnly)
		float CrossHairXLocation = 0.5;
		UPROPERTY(EditDefaultsOnly)
		float CrossHairYLocation = 0.333333;
		UPROPERTY(EditDefaultsOnly)
		float LineTraceRange = 1000000;
};