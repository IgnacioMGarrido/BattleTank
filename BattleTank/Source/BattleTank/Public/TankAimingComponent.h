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
	Locked,
	OutOfAmmo
};

class UTankBarrel; //Forward Declaration
class UTankTurret;
class UTankTracks;
class AProjectile;
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	

	void AimAt(FVector HitLocation);
	
	UFUNCTION(BlueprintCallable, Category = "Fire")
	void Fire();

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Initialise(UTankBarrel *BarrelToSet, UTankTurret *TurretToSet);
	
	UFUNCTION(BlueprintCallable, Category = "Setup")
	int GetRemainingAmmo() const;

	EFiringState GetFiringState() const;

private:	
	// Sets default values for this component's properties
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;

	UTankAimingComponent();
	void MoveBarrelTowards(FVector AimDirection);
	bool IsBarrelStateMoving() const;
private:
	UTankBarrel *Barrel = nullptr;
	UTankTurret *Turret = nullptr;
	FVector AimDirection;

protected:
	UPROPERTY(BlueprintReadOnly, Category = "State")
	EFiringState FiringState = EFiringState::Reloading;
	
	UPROPERTY(EditAnywhere, Category = "Firing")
	float LaunchSpeed = 10000;

	UPROPERTY(EditAnywhere, Category = "Setup")
	TSubclassOf<AProjectile> ProjectileBlueprint;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float ReloadTimeInSeconds = 3;
	double LastFireTime = 0;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	int RemainingAmmo = 3;
};
