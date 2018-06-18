// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"



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
	//GetWorld Location through Crosshair.
	//If it hits the landscape
		//Tell Controlled Tank to aim at this point
}

