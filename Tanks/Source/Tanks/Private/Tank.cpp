// Fill out your copyright notice in the Description page of Project Settings.

#include "Tanks.h"
#include "TankAimingComponent.h"
#include "Projectile.h"
#include "TankBarrel.h"
#include "Tank.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
    
    auto TankName = GetName();
}


void ATank::AimAt( FVector HitLocation )
{
    if (!ensure(TankAimingComponent)) { return; }
    TankAimingComponent->AimAt( HitLocation, LaunchSpeed );
}

void ATank::BeginPlay()
{
    Super::BeginPlay(); // Needed for BP Begin Play to run!
    
    auto TankName = GetName();
    TankAimingComponent = FindComponentByClass<UTankAimingComponent>();
}

void ATank::Fire()
{
    if (!ensure(Barrel)) { return; }
    bool isReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTimeInSeconds;
    if (isReloaded)
    {
        auto Projectile = GetWorld()->SpawnActor<AProjectile>(
                                                              ProjectileBlueprint,
                                                              Barrel->GetSocketLocation(FName ("Projectile")),
                                                              Barrel->GetSocketRotation(FName ("Projectile"))
                                                              );
        
        Projectile->LaunchProjectile( LaunchSpeed );
        LastFireTime = FPlatformTime::Seconds();
    }
}

