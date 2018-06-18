// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"




ATank* ATankPlayerController::GetControlledTank() const{
	
	return Cast<ATank>(GetPawn());
}

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
