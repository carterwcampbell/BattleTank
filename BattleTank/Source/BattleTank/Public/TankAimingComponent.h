// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"
#include "Components/StaticMeshComponent.h"
#include "TankAimingComponent.generated.h"

// Enum for Aiming State
UENUM()
enum class EFiringState : uint8
{
	Locked,
	Aiming,
	Reloading,
	OutOfAmmo
};

// Forward Declaration
class UTankBarrel;
class UTankTurret;
class AProjectile;

// Holds Barrel's Propertaies and Elevate Method
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

	public:	
		// Sets default values for this component's properties
		UTankAimingComponent();

		UFUNCTION(BlueprintCallable, Category = "Setup")
		void Initialise(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet);

		// Called when the game starts
		virtual void BeginPlay() override;

		void AimAt(FVector HitLocation);

		UFUNCTION(BlueprintCallable, Category = "Firing")
		void Fire();

		EFiringState GetFiringState() const;

		UFUNCTION(BlueprintCallable, Category = "Firing")
		int GetRoundsLeft() const;

	protected:
		UPROPERTY(BlueprintReadOnly, Category = "State")
		EFiringState FiringState = EFiringState::Reloading;
	
	private:
		UTankTurret* Turret = nullptr;
		UTankBarrel* Barrel = nullptr;

		virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;

		void MoveBarrel(FVector AimDirection);

		bool IsBarrelMoving();

		UPROPERTY(EditDefaultsOnly, Category = "Firing")
		float LaunchSpeed = 10000.0;

		UPROPERTY(EditDefaultsOnly, Category = "Setup")
		float ReloadTimeInSeconds = 3.0;

		UPROPERTY(EditDefaultsOnly, Category = "Setup")
		TSubclassOf<AProjectile> ProjectileBlueprint;

		double LastFireTime = 0.0;
		FVector AimDirection;
		int RoundsLeft = 20;
};
