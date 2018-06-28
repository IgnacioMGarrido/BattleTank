// Copyright Ignacio Martinez.

#include "Public/TankTracks.h"
#include "Components/PrimitiveComponent.h"

UTankTracks::UTankTracks() 
{
	PrimaryComponentTick.bCanEverTick = true;
}
void UTankTracks::BeginPlay()
{
	Super::BeginPlay();
}

void UTankTracks::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction * ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	//Calculate the slippage speed
	auto SlippageSpeed = FVector::DotProduct(GetRightVector(), GetComponentVelocity());

	//Work out the requiered acceleration this frame to correct.
	auto CorrectionAcceleration = -SlippageSpeed / DeltaTime * GetRightVector();

	//Claculate and apply sideways force (F = m * a)
	auto TankRoot = Cast<UStaticMeshComponent>(GetOwner()->GetRootComponent());
	auto CorrectionForce = (TankRoot->GetMass() * CorrectionAcceleration) / 2;
	UE_LOG(LogTemp, Warning, TEXT("Correction Force is: %d"), *CorrectionForce.ToString())
	TankRoot->AddForce(CorrectionForce);
}

void UTankTracks::SetThrottle(float Throttle) 
{

	Throttle = FMath::Clamp<float>(Throttle, -1, 1);

	auto ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}



