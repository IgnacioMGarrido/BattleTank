// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/TankBarrel.h"



void UTankBarrel::Elevate(float RelativeSpeed) 
{
	auto time = GetWorld()->GetTimeSeconds();
	UE_LOG(LogTemp, Warning, TEXT("%f: Barrel->Elevate(%f)"), time,RelativeSpeed)
}
