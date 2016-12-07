// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "TankAimingComponent.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h" //paste new includes above

UCLASS()
class TANKS_API ATank : public APawn
{
	GENERATED_BODY()

public:
    void AimAt( FVector HitLocation );
    
    UFUNCTION(BlueprintCallable, Category = Setup)
    void SetBarrelReference( UStaticMeshComponent* BarrelToSet );
    
protected:
    UTankAimingComponent* TankAimingComponent = nullptr;
    
private:
    UPROPERTY(EditAnywhere, Category = Firing)
    float LaunchSpeed = 100000; // 1000 m/s in cm
    
	// Sets default values for this pawn's properties
	ATank();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent( class UInputComponent* InputComponent ) override;
	
};