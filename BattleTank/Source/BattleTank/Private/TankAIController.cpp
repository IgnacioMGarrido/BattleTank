// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/TankAIController.h"




void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	ControlledTank = GetControlledTank();
	PlayerTank = GetPlayerTank();

	if (ControlledTank && PlayerTank) {
		UE_LOG(LogTemp, Warning, TEXT("AI Controller Controlling Tank: %s Found Player Tank: %s"), *ControlledTank->GetName(), *PlayerTank->GetName())
	}
	else {
		UE_LOG(LogTemp, Error, TEXT("AI Controller failed to Control Tank. NULL"), *ControlledTank->GetName())
	}

}
ATank* ATankAIController::GetPlayerTank() const
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}

ATank* ATankAIController::GetControlledTank() const 
{

	return Cast<ATank>(GetPawn());
}

