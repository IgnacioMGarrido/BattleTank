// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"

/**
 * 
 */
class UTankTracks;
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintCallable, Category = Input)
	void IntendMovementForward(float Throw);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void Initialise(UTankTracks* RightTrackToSet, UTankTracks* LeftTrackToSet);

private:
	UTankTracks * RightTrack;
	UTankTracks * LeftTrack;
};
