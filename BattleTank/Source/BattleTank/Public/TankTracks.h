// Copyright Ignacio Martinez.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTracks.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTracks : public UStaticMeshComponent
{
	GENERATED_BODY()
	
	
public:
	///Set Throttle between -1 and +1
	UFUNCTION(BlueprintCallable, Category = Fire)
	void SetThrottle(float Throttle);
	
	//This is max Force per track.
	UPROPERTY(EditDefaultsOnly)
		float TrackMaxDrivingForce = 400000; //Force in Newtons - 40000 kg * 10 ms^-2 
};
