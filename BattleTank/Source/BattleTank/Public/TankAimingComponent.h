// Copyright Ignacio Martinez.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Actor.h"
#include "Components/ActorComponent.h"
#include "Engine/StaticMesh.h"
#include "TankAimingComponent.generated.h"


class UTankBarrel; //Forward Declaration
class UTankTurret;
class UTankTracks;
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	void AimAt(FVector WorldSpaceAim, float LaunchSpeed);
	void SetBarrelReference(UTankBarrel *BarrelToSet);
	void SetTurretReference(UTankTurret *TurretToSet);
	void SetTracksReference(UTankTracks *RightTrackToSet, UTankTracks *LeftTrackToSet);


private:	
	void MoveBarrelTowards(FVector AimDirection);

private:
	UTankBarrel *Barrel = nullptr;
	UTankTurret *Turret = nullptr;
	UTankTracks *RightTrack = nullptr;
	UTankTracks *LeftTrack = nullptr;
};
