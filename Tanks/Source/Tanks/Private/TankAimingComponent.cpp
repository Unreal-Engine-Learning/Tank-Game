// Fill out your copyright notice in the Description page of Project Settings.

#include "Tanks.h"
#include "TankBarrel.h"
#include "TankAimingComponent.h"

class UTankBarrel;

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UTankAimingComponent::SetBarrelReference( UTankBarrel* BarrelToSet )
{
    Barrel = BarrelToSet;
}

void UTankAimingComponent::AimAt( FVector HitLocation, float LaunchSpeed )
{
    //auto OurTankName = GetOwner()->GetName();
    //auto BarrelLocation = Barrel->GetComponentLocation().ToString();
    if ( !Barrel ) { return; }
    FVector OutLaunchVelocity;
    FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
    bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity
        (
         this,
         OutLaunchVelocity,
         StartLocation,
         HitLocation,
         LaunchSpeed,
         ESuggestProjVelocityTraceOption::DoNotTrace
    ); // calculate launch velocity
    
    if (bHaveAimSolution)
    {
        auto AimDirection = OutLaunchVelocity.GetSafeNormal();
        auto TankName = GetOwner()->GetName();
        MoveBarrel( AimDirection );
    }
    // if no solution found do nothing
}

void UTankAimingComponent::MoveBarrel( FVector AimDirection )
{
    // Work-out difference between current barrel rotation and aim direction
    auto BarrelRotator = Barrel->GetForwardVector().Rotation();
    auto AimAsRotator = AimDirection.Rotation();
    auto DeltaRotator = AimAsRotator - BarrelRotator;
    
    Barrel->Elevate(5);
}
