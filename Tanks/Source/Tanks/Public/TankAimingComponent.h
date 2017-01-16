// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

// enum aiming state

UENUM()
enum class EFiringState : uint8
{
    Reloading,
    Aiming,
    Locked
};

//forward declaration
class UTankBarrel;
class UTankTurret;

// holds barrels properties and elevate method
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TANKS_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:
    UFUNCTION( BlueprintCallable, Category = "Setup")
    void Initialise(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet);

    void AimAt (FVector HitLocation);
    
    
protected:
    UPROPERTY(BlueprintReadOnly, Category = "State")
    EFiringState FiringState = EFiringState::Reloading;
    
private:
    
    // Sets default values for this component's properties
    UTankAimingComponent();
    
    UTankBarrel* Barrel = nullptr;
    UTankTurret* Turret = nullptr;
    
    UPROPERTY(EditDefaultsOnly, Category = "Setup")
    float LaunchSpeed = 4000; // 1000 m/s in cm
    
    void MoveBarrelTowards( FVector AimDirection );
    void MoveTurretTowards( FVector AimDirection );
	
};
