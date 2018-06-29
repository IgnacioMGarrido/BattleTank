// Copyright Ignacio Martinez.
#include "Public/TankAIController.h"
#include "BattleTank.h"
#include "TankPlayerController.h"
#include "Public/Tank.h"
#include "Public/TankAimingComponent.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!ensure(PlayerTank && GetPawn())) { return; }
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

void ATankAIController::SetPawn(APawn * InPawn)
{
	Super::SetPawn(InPawn);
	if (InPawn) 
	{
		auto PossessedTank = Cast<ATank>(InPawn);
		if (!PossessedTank) { return; }
		// Subscribe our local method to the tanks Death event
		PossessedTank->OnDeath.AddUniqueDynamic(this, &ATankAIController::OnTankDeath);
	}
}
void ATankAIController::OnTankDeath()
{
	if (!ensure(GetPawn())) { return; } //TODO: Remove if ok
	GetPawn()->DetachFromControllerPendingDestroy();
}



