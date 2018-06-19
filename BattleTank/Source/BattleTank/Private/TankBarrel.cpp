// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/TankBarrel.h"



void UTankBarrel::Elevate(float RelativeSpeed) 
{
	//auto time = GetWorld()->GetTimeSeconds();
	//UE_LOG(LogTemp, Warning, TEXT("%f: Barrel->Elevate(%f)"), time,RelativeSpeed)
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);

	auto ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto NewRawElevation = RelativeRotation.Pitch + ElevationChange;

	//Clamp the values
	auto Elevation = FMath::Clamp<float>(NewRawElevation, MinEleveationDegrees, MaxElevationDegrees);
	SetRelativeRotation(FRotator(Elevation, 0, 0));
}
