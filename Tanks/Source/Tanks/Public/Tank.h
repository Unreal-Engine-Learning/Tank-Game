// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h" //paste new includes above

class UTankBarrel;
class UTankAimingComponent;
class AProjectile;

UCLASS()
class TANKS_API ATank : public APawn
{
	GENERATED_BODY()

public:
    void AimAt( FVector HitLocation );
    
    UFUNCTION(BlueprintCallable, Category = "Firing")
    void Fire();

protected:
    UPROPERTY(BlueprintReadOnly)
    UTankAimingComponent* TankAimingComponent = nullptr;
    
private:
    UPROPERTY(EditDefaultsOnly, Category = "Setup")
    float LaunchSpeed = 4000; // 1000 m/s in cm
    
    UPROPERTY(EditDefaultsOnly, Category = "Setup")
    TSubclassOf<AProjectile> ProjectileBlueprint;
    
    UTankBarrel* Barrel = nullptr;
    
	// Sets default values for this pawn's properties
	ATank();
    
    virtual void BeginPlay() override;
	
    UPROPERTY(EditDefaultsOnly, Category = "Setup")
    float ReloadTimeInSeconds = 3;
    
    double LastFireTime = 0;
    
};
