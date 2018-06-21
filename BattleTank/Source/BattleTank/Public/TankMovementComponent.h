// Copyright Ignacio Martinez.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"

/**
 * Responisble for driveing the car.
 */
class UTankTracks;
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintCallable, Category = "Input")
	void IntendMovementForward(float Throw);

	UFUNCTION(BlueprintCallable, Category = "Input")
	void IntendTurnRight(float Throw);

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Initialise(UTankTracks* RightTrackToSet, UTankTracks* LeftTrackToSet);

private:
	//Called from the pathfinding logic by AI Controllers
	virtual void RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) override;
private:
	UTankTracks * RightTrack;
	UTankTracks * LeftTrack;
};
