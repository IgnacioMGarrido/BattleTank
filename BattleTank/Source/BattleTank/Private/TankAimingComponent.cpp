// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/TankAimingComponent.h"
#include "Public/TankBarrel.h"
#include "Public/TankTurret.h"



// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}
void UTankAimingComponent::SetBarrelReference(UTankBarrel * BarrelToSet)
{
	if (!ensure(BarrelToSet)) { return; }
	this->Barrel = BarrelToSet;
}

void UTankAimingComponent::SetTurretReference(UTankTurret * TurretToSet)
{
	if (!ensure(TurretToSet)) { return; }
	this->Turret = TurretToSet;
}
void UTankAimingComponent::SetTracksReference(UTankTracks *RightTrackToSet, UTankTracks *LeftTrackToSet)
{
	if (!ensure(RightTrackToSet)) { return; }
	this->RightTrack = RightTrackToSet;
	if (!ensure(LeftTrackToSet)) { return; }
	this->RightTrack = LeftTrackToSet;
}
void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed)
{
	if (!ensure(Barrel)) { return; }

	FVector OutLaunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity(
		this,
		OutLaunchVelocity,
		StartLocation,
		HitLocation,
		LaunchSpeed,
		false,
		0,
		0,
		ESuggestProjVelocityTraceOption::DoNotTrace // Paramater must be present to prevent bug
	);
	

	if (bHaveAimSolution) {
		FVector AimDirection = OutLaunchVelocity.GetSafeNormal();
		FString TankName = GetOwner()->GetName();
		//UE_LOG(LogTemp, Warning, TEXT("%s Aiming at %s"), *TankName, *AimDirection.ToString())
		MoveBarrelTowards(AimDirection);
	}
}
void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection)
{
	//Work pout difference between current barrel rotation and aim Direction
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator;
	//UE_LOG(LogTemp, Warning, TEXT("Aim As rotator: %s"), *DeltaRotator.ToString())
	
	//Move Barrel the right amount this frame
	
	//given max elevetion speed, and frame time.
	Barrel->Elevate(DeltaRotator.Pitch);
	Turret->Rotate(DeltaRotator.Yaw);

}




