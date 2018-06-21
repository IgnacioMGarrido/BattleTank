// Copyright Ignacio Martinez.

#include "Public/TankBarrel.h"



void UTankBarrel::Elevate(float RelativeSpeed) 
{
	//auto time = GetWorld()->GetTimeSeconds();
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);

	auto ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto NewRawElevation = RelativeRotation.Pitch + ElevationChange;

	//Clamp the values
	auto Elevation = FMath::Clamp<float>(NewRawElevation, MinEleveationDegrees, MaxElevationDegrees);
	SetRelativeRotation(FRotator(Elevation, 0, 0));
}
