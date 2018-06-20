// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/TankMovementComponent.h"
#include "Public/TankTracks.h"



void UTankMovementComponent::Initialise(UTankTracks* RightTrackToSet, UTankTracks* LeftTrackToSet) {
		
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
	
}

void UTankMovementComponent::IntendMovementForward(float Throw)
{
	if (!ensure(RightTrack) || !ensure(LeftTrack)) { return; }
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
	
	//TODO: Prevent Double input for double speed


}

void UTankMovementComponent::IntendTurnRight(float Throw)
{
	if (!ensure(RightTrack) || !ensure(LeftTrack)) { return; }
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);
	
}



