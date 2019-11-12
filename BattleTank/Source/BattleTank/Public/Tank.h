// Copyright CWC Games

#pragma once

#include "GameFramework/Pawn.h"
#include "Projectile.h"
#include "Tank.generated.h"

class UTankBarrel;
class UTankAimingComponent;
class AProjectile;
class UTankMovementComponent;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

	public:
		void AimAt(FVector HitLocation);

		UFUNCTION(BlueprintCallable, Category = "Firing")
		void Fire();

	protected:
		UPROPERTY(BlueprintReadOnly)
		UTankAimingComponent* TankAimingComponent = nullptr;

		UPROPERTY(BlueprintReadOnly)
		UTankMovementComponent* TankMovementComponent =  nullptr;

	private:
		// Sets default values for this pawn's properties
		ATank();

		// Called when the game starts or when spawned
		virtual void BeginPlay() override;

		UPROPERTY(EditDefaultsOnly, Category = "Firing")
		float LaunchSpeed = 4000.0;

		UPROPERTY(EditDefaultsOnly, Category = "Setup")
		float ReloadTimeInSeconds = 3.0;

		UPROPERTY(EditDefaultsOnly, Category = "Setup")
		TSubclassOf<AProjectile> ProjectileBlueprint;

		UTankBarrel* Barrel = nullptr;

		double LastFireTime = 0.0;
};