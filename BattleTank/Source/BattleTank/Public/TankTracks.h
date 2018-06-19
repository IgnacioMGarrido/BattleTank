// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTracks.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent), hidecategories = ("Collision"))
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