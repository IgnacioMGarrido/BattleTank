// Copyright Ignacio Martinez.

#include "Public/TankMovementComponent.h"
#include "Public/TankTracks.h"



void UTankMovementComponent::Initialise(UTankTracks* RightTrackToSet, UTankTracks* LeftTrackToSet) {
		
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
	
}

void UTankMovementComponent::RequestDirectMove(const FVector & MoveVelocity, bool bForceMaxSpeed) 
{
	//No need to call super
	auto TankForward = GetOwner()->GetActorForwardVector().GetSafeNormal();
	auto AIForwardIntention = MoveVelocity.GetSafeNormal();

	float ForwardThrow = FVector::DotProduct(TankForward, AIForwardIntention);

	FVector CrossProduct = FVector::CrossProduct(TankForward, AIForwardIntention);
	float RotationThrow = CrossProduct.Z;

	IntendMovementForward(ForwardThrow);
	IntendTurnRight(RotationThrow);


}

void UTankMovementComponent::IntendMovementForward(float Throw)
{
	if (!ensure(RightTrack) && !ensure(LeftTrack)) { return; }
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
	
}

void UTankMovementComponent::IntendTurnRight(float Throw)
{
	if (!ensure(RightTrack) && !ensure(LeftTrack)) { return; }
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);
	
}



