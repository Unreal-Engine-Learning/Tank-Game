// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

//forward declaration
class UTankBarrel;

// holds barrels properties and elevate method
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TANKS_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

    void AimAt ( FVector HitLocation, float LaunchSpeed );
    
    // setter
    void SetBarrelReference( UTankBarrel* BarrelToSet );
    
private:
    UTankBarrel* Barrel = nullptr;
    
    void MoveBarrel( FVector AimDirection );
	
};
