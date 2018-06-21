// Copyright Ignacio Martinez.
#include "Public/TankAIController.h"
#include "BattleTank.h"
#include "TankPlayerController.h"
#include "Public/Tank.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	InitVariables();


}
void ATankAIController::InitVariables()
{

	ControlledTank = Cast<ATank>(GetPawn());;

	if (!GetWorld()->GetFirstPlayerController()->GetPawn()) { PlayerTank = nullptr; }
		PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (PlayerTank) 
	{
		//Move Towards Player
		MoveToActor(PlayerTank, AcceptanceRadius); // TODO: Check radius is in cm.
		//Aim Towards Player
		AimTowardsPlayerTank();

		//Fire Shot
		//TODO: Don't fire every frame
		//ControlledTank->Fire(); 
	}
}


void ATankAIController::AimTowardsPlayerTank()
{
	if (!ensure(PlayerTank)) { return; }

	FVector HitLocation = PlayerTank->GetActorLocation();
	ControlledTank->AimAt(HitLocation);
}




