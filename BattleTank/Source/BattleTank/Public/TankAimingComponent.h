// Copyright Ignacio Martinez.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Actor.h"
#include "Components/ActorComponent.h"
#include "Engine/StaticMesh.h"
#include "TankAimingComponent.generated.h"


// Enum aiming state.
UENUM()
enum class EFiringState : uint8 
{
	Reloading,
	Aming,
	Locked
};

class UTankBarrel; //Forward Declaration
class UTankTurret;
class UTankTracks;
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	

	void AimAt(FVector WorldSpaceAim, float LaunchSpeed);
	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Initialise(UTankBarrel *BarrelToSet, UTankTurret *TurretToSet);

private:	
	// Sets default values for this component's properties
	UTankAimingComponent();
	void MoveBarrelTowards(FVector AimDirection);

private:
	UTankBarrel *Barrel = nullptr;
	UTankTurret *Turret = nullptr;


protected:
	UPROPERTY(BlueprintReadOnly, Category = "State")
	EFiringState FiringState = EFiringState::Locked;
};
