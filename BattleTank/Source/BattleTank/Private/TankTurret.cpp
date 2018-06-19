// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/TankTurret.h"



void UTankTurret::Rotate(float RelativeSpeed) 
{
	auto time = GetWorld()->GetTimeSeconds();
	UE_LOG(LogTemp, Warning, TEXT("%f: Turret->Rotate(%f)"), time,RelativeSpeed)
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);

	auto RotationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto Rotation = RelativeRotation.Yaw + RotationChange;

	//Clamp the values
	SetRelativeRotation(FRotator(0, Rotation, 0));
}

