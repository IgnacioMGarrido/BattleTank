// Copyright Ignacio Martinez.
#include "Public/TankAIController.h"
#include "BattleTank.h"
#include "TankPlayerController.h"
#include "Public/TankAimingComponent.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!ensure(PlayerTank)) { return; }
	if (PlayerTank) 
	{
		//Move Towards Player
		MoveToActor(PlayerTank, AcceptanceRadius); // TODO: Check radius is in cm.
		//Aim Towards Player
		AimTowardsPlayerTank(PlayerTank);

		//Fire Shot
		//TODO: Fix firing
		auto AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
		if(AimingComponent->GetFiringState() == EFiringState::Locked)
			AimingComponent->Fire();
	}
}


void ATankAIController::AimTowardsPlayerTank(APawn* PlayerTank)
{
	auto AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	if (!ensure(AimingComponent)) { return; }

	FVector HitLocation = PlayerTank->GetActorLocation();
	AimingComponent->AimAt(HitLocation);

}




