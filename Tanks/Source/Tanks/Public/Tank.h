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
    
    UFUNCTION(BlueprintCallable, Category = Firing)
    void Fire();
    
    UFUNCTION(BlueprintCallable, Category = Setup)
    void SetBarrelReference( UTankBarrel* BarrelToSet );
    
    UFUNCTION(BlueprintCallable, Category = Setup)
    void SetTurretReference( UTankTurret* TurretToSet );
    
protected:
    UTankAimingComponent* TankAimingComponent = nullptr;
    
private:
    UPROPERTY(EditDefaultsOnly, Category = Setup)
    float LaunchSpeed = 4000; // 1000 m/s in cm
    
    UPROPERTY(EditDefaultsOnly, Category = Setup)
    TSubclassOf<AProjectile> ProjectileBlueprint;
    
    UTankBarrel* Barrel = nullptr;
    
	// Sets default values for this pawn's properties
	ATank();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent( class UInputComponent* InputComponent ) override;
	
    UPROPERTY(EditDefaultsOnly, Category = Setup)
    float ReloadTimeInSeconds = 3;
    
    double LastFireTime = 0;
    
};
