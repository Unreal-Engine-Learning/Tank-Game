// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
#include "TankAIController.generated.h"

class ATank;

/**
 * 
 */
UCLASS()
class TANKS_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
public:
    ATank* GetControlledTank() const;
    ATank* GetPlayerTank() const;
    
protected:
    UPROPERTY(EditDefaultsOnly, Category = "Setup") //consider EditDefaultsOnly
    float AcceptanceRadius = 1000;
    
private:
    void BeginPlay() override;
    
    virtual void SetPawn(APawn* InPawn) override;
    
    virtual void Tick(float DeltaTime) override;
    
    UFUNCTION()
    void OnPossedTankDeath();
};
