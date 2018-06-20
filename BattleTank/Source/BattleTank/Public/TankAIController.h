// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Engine/World.h"
#include "TankAIController.generated.h"


class ATank;
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

private:
	void AimTowardsPlayerTank();
	void InitVariables();
	
private:
	ATank * ControlledTank;
	ATank* PlayerTank;

	//How close can the AI tank get.
	float AcceptanceRadius = 3000;
};
