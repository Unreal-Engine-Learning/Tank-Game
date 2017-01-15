// Fill out your copyright notice in the Description page of Project Settings.

#include "Tanks.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "TankAimingComponent.h"

class UTankBarrel;

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = false;
	// ...
}

void UTankAimingComponent::Initialise(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet)
{
    Barrel = BarrelToSet;
    Turret = TurretToSet;
}

void UTankAimingComponent::AimAt( FVector HitLocation, float LaunchSpeed )
{
    if (!ensure(Barrel)) { return; }
    FVector OutLaunchVelocity;
    FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
    bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity
        (
         this,
         OutLaunchVelocity,
         StartLocation,
         HitLocation,
         LaunchSpeed,
         false,
         0,
         0,
         ESuggestProjVelocityTraceOption::DoNotTrace //parameter must be present to prevent bug
        ); // calculate launch velocity
    
    if (bHaveAimSolution)
    {
        auto AimDirection = OutLaunchVelocity.GetSafeNormal();
        auto TankName = GetOwner()->GetName();
        MoveBarrelTowards( AimDirection );
        auto Time = GetWorld()->GetTimeSeconds();
        // UE_LOG(LogTemp, Warning, TEXT("%f: aim solve found"), Time);
    }
    else
    {
        auto Time = GetWorld()->GetTimeSeconds();
        // UE_LOG(LogTemp, Warning, TEXT("%f: No aim solve found"), Time);
    }
    // if no solution found do nothing
}

void UTankAimingComponent::MoveBarrelTowards( FVector AimDirection )
{
    if (!ensure((Barrel || !Turret))) { return; }
    // Work-out difference between current barrel rotation and aim direction
    auto BarrelRotator = Barrel->GetForwardVector().Rotation();
    auto AimAsRotator = AimDirection.Rotation();
    auto DeltaRotator = AimAsRotator - BarrelRotator;
    
    Barrel->Elevate(DeltaRotator.Pitch);
    Turret->Rotate(DeltaRotator.Yaw);
}
