// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/TankMovementComponent.h"
#include "Public/TankTracks.h"


void UTankMovementComponent::Initialise(UTankTracks* RightTrackToSet, UTankTracks* LeftTrackToSet) {
	if (!ensure(RightTrack) || !ensure(LeftTrack)) {
		LeftTrack = LeftTrackToSet;
		RightTrack = RightTrackToSet;
	}
}

void UTankMovementComponent::IntendMovementForward(float Throw)
{
	UE_LOG(LogTemp, Warning, TEXT("%s Intend move forward throw: %f"), *GetName(), Throw);
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
}


