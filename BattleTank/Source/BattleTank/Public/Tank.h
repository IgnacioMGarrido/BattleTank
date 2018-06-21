// Copyright Ignacio Martinez.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankBarrel;
class UTankTurret;
class UTankTracks;
class UTankAimingComponent;
class UTankMovementComponent;
class AProjectile;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();
	void AimAt(FVector HitLocation);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void SetBarrelReference(UTankBarrel *BarrelToSet);
	
	UFUNCTION(BlueprintCallable, Category = "Setup")
	void SetTurretReference(UTankTurret *TurretToSet);
	
	UFUNCTION(BlueprintCallable, Category = "Setup")
	void SetTrackReference(UTankTracks *RightTrackToSet, UTankTracks *LeftTrackToSet);
	
	UFUNCTION(BlueprintCallable, Category = "Fire")
	void Fire();

protected:
	UPROPERTY(BlueprintReadOnly)
	UTankAimingComponent * TankAimingComponent = nullptr;

	//UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Input)
	//UPROPERTY(BlueprintReadOnly)
	//UTankMovementComponent * TankMovementComponent = nullptr;
private:
	UPROPERTY(EditAnywhere, Category = Firing)
	float LaunchSpeed = 10000; 
	
	UPROPERTY(EditAnywhere, Category = Setup)
	TSubclassOf<AProjectile> ProjectileBlueprint;

	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float ReloadTimeInSeconds = 3;
	double LastFireTime = 0;

	UTankBarrel* Barrel = nullptr;




};
