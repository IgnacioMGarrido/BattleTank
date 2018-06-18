// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

#define OUT
void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	ControlledTank = GetControlledTank();
	if (ControlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("Player Controller Controlling Tank: %s"),*ControlledTank->GetName())
	}
	else {
		UE_LOG(LogTemp, Error, TEXT("Player Controller Controlling failed to Control Tank. NULL"), *ControlledTank->GetName())
	}

}
void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick( DeltaTime );

	AimTowardsCrosshair();
}
ATank* ATankPlayerController::GetControlledTank() const
{

	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }

	FVector HitLocation;
	if (GetSightRayHitLocation(OUT HitLocation)) {
		//UE_LOG(LogTemp, Warning, TEXT("Hit Location: %s"), *HitLocation.ToString())
		//Tell Controller tank to aim at this point.
		GetControlledTank()->AimAt(HitLocation);
	}

}

bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	
	// Find Crosshair position in Pixel Coordinates
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(OUT ViewportSizeX, OUT ViewportSizeY);
	FVector2D ScreenLocation = FVector2D(ViewportSizeX * CrossHairXLocation, ViewportSizeY * CrossHairYLocation);
	
	// De-project screen position to a world direction
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, OUT LookDirection)) {
		// line trace along that direction
		// See what we hit
		GetLookVectorHitLocation(LookDirection, OUT OutHitLocation);
	}

	return true;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	FVector CameraWorldLocation;
	return DeprojectScreenPositionToWorld(ScreenLocation.X,
		ScreenLocation.Y, 
		OUT CameraWorldLocation,
		OUT LookDirection);
}
bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const
{
	FHitResult HitResult;
	FVector StartLocation = PlayerCameraManager->GetCameraLocation();
	FVector EndLocation = StartLocation + (LookDirection * LineTraceRange * 100000);


	bool isLineTrace = GetWorld()->LineTraceSingleByChannel
	(
		HitResult, StartLocation, EndLocation, ECollisionChannel::ECC_Visibility
	);
	if (isLineTrace) 
	{
		HitLocation = HitResult.Location;
		return true;
	}
	return false;
}