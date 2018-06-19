// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/TankAIController.h"
#include "BattleTank.h"
#include "TankPlayerController.h"
#include "Public/Tank.h"


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

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (PlayerTank) 
	{
		AimTowardsPlayerTank();

	}
}

ATank* ATankAIController::GetPlayerTank() const
{
	if (!GetWorld()->GetFirstPlayerController()->GetPawn()) { return nullptr; }

	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}

ATank* ATankAIController::GetControlledTank() const
{

	return Cast<ATank>(GetPawn());
}


void ATankAIController::AimTowardsPlayerTank()
{
	if (!GetControlledTank()) { return; }

	FVector HitLocation = PlayerTank->GetActorLocation();
	GetControlledTank()->AimAt(HitLocation);
}



