// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * Tank track is used to set maximum driving force, and to move the tank
 */
UCLASS(meta=(BlueprintSpawnableComponent))
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()

	public:
		UTankTrack();

		virtual void BeginPlay() override;

		virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;

		UFUNCTION()
		void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);

		UFUNCTION(BlueprintCallable, Category = "Setup")
		void SetThrottle(float Throttle);
	
		// Max force per track, in Newtons
		UPROPERTY(EditDefaultsOnly)
		float TrackMaxDrivingForce = 40000000.0; // Assume 40 tonne tank, 1g acceleration
};
