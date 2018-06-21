// Copyright Ignacio Martinez.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankBarrel;
class AProjectile;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();

	//TODO: Put this into AimingComponent instead of the tank
	UFUNCTION(BlueprintCallable, Category = "Fire")
	void Fire();

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere, Category = "Firing")
	float LaunchSpeed = 10000; 
	
	UPROPERTY(EditAnywhere, Category = "Setup")
	TSubclassOf<AProjectile> ProjectileBlueprint;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float ReloadTimeInSeconds = 3;
	double LastFireTime = 0;

	UTankBarrel* Barrel = nullptr; //TODO: Remove
};
