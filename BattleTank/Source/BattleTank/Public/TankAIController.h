// Copyright Ignacio Martinez.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Engine/World.h"
#include "TankAIController.generated.h"


class UTankAimingComponent;

UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	//How close can the AI tank get.
	UPROPERTY(EditDefaultsOnly, Category = "Setup") 
	float AcceptanceRadius = 6000;

private:
	void AimTowardsPlayerTank(APawn* PlayerTank);
	

};
