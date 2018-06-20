// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/TankMovementComponent.h"

void UTankMovementComponent::IntendMovementForward(float Throw)
{
	UE_LOG(LogTemp, Warning, TEXT("%s Intend move forward throw: %f"), *GetName(), Throw);

}


