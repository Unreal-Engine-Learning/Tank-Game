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
class AProjectile;
class UTankTurret;

// holds barrels properties and elevate method
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TANKS_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:
    UFUNCTION( BlueprintCallable, Category = "Setup")
    void Initialise(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet);
    
    UFUNCTION(BlueprintCallable, Category = "Firing")
    void Fire();

    void AimAt (FVector HitLocation);
    
    EFiringState GetFiringState() const;
    
    
protected:
    UPROPERTY(BlueprintReadOnly, Category = "State")
    EFiringState FiringState = EFiringState::Reloading;
    
private:
    
    // Sets default values for this component's properties
    UTankAimingComponent();
    
    
    void MoveBarrelTowards( FVector AimDirection );
    void MoveTurretTowards( FVector AimDirection );
    
    bool IsBarrelMoving();
    
    virtual void BeginPlay() override;
    virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;
    
    UTankBarrel* Barrel = nullptr;
    UTankTurret* Turret = nullptr;
    
    UPROPERTY(EditDefaultsOnly, Category = "Setup")
    float LaunchSpeed = 4000; // 1000 m/s in cm
    
    UPROPERTY(EditDefaultsOnly, Category = "Setup")
    TSubclassOf<AProjectile> ProjectileBlueprint;
    
    UPROPERTY(EditDefaultsOnly, Category = "Setup")
    float ReloadTimeInSeconds = 3;
    
    double LastFireTime = 0;

    FVector AimDirection;
};
