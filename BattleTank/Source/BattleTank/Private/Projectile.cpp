// Copyright Ignacio Martinez.

#include "Public/Projectile.h"
#include "Engine/World.h"

// Sets default values
AProjectile::AProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(FName("Movement Component"));
	MovementComponent->bAutoActivate = false;
}

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void AProjectile::LaunchProjectile(float LaunchSpeed)
{
	auto time = GetWorld()->GetTimeSeconds();

	UE_LOG(LogTemp, Warning, TEXT("%f: Projectile Fires at speed %f"), time, LaunchSpeed)

	MovementComponent->SetVelocityInLocalSpace(FVector::ForwardVector * LaunchSpeed);
	MovementComponent->Activate();
}
