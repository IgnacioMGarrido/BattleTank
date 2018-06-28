// Copyright Ignacio Martinez.

#include "Public/TankTracks.h"
#include "Engine/World.h"
#include "Components/PrimitiveComponent.h"

UTankTracks::UTankTracks() 
{
	PrimaryComponentTick.bCanEverTick = false;

}
void UTankTracks::BeginPlay()
{
	Super::BeginPlay();
	OnComponentHit.AddDynamic(this, &UTankTracks::OnHit);
}


void UTankTracks::ApplySidewaysForce()
{
	//Calculate the slippage speed
	auto SlippageSpeed = FVector::DotProduct(GetRightVector(), GetComponentVelocity());

	//Work out the requiered acceleration this frame to correct.
	auto DeltaTime = GetWorld()->GetDeltaSeconds();
	auto CorrectionAcceleration = -SlippageSpeed / DeltaTime * GetRightVector();

	//Claculate and apply sideways force (F = m * a)
	auto TankRoot = Cast<UStaticMeshComponent>(GetOwner()->GetRootComponent());
	auto CorrectionForce = (TankRoot->GetMass() * CorrectionAcceleration) / 2;
	TankRoot->AddForce(CorrectionForce);
}

void UTankTracks::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
	//Drive the tracks
	DriveTrack();
	//Apply sideways force
	ApplySidewaysForce();
	CurrentThrottle = 0;
}

void UTankTracks::SetThrottle(float Throttle) 
{

	CurrentThrottle = FMath::Clamp(CurrentThrottle + Throttle,-1.0f,1.0f);

}

void UTankTracks::DriveTrack()
{
	auto ForceApplied = GetForwardVector() * CurrentThrottle * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}



