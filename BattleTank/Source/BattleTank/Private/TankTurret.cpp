// Copyright Ignacio Martinez.

#include "Public/TankTurret.h"



void UTankTurret::Rotate(float RelativeSpeed) 
{
	//auto time = GetWorld()->GetTimeSeconds();
	//UE_LOG(LogTemp, Warning, TEXT("%f: Turret->Rotate(%f)"), time,RelativeSpeed)
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);

	auto RotationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto Rotation = RelativeRotation.Yaw + RotationChange;

	SetRelativeRotation(FRotator(0, Rotation, 0));
}

