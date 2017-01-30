// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h" //paste new includes above

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTankDelegate);

UCLASS()
class TANKS_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();
    
    virtual float TakeDamage(float DamageAmount, struct FDamageEvent const &DamageEvent, class AController * EventInstigator, AActor *DamageCauser) override;
    
    //return current health as a percent
    UFUNCTION(BlueprintPure, Category="Health")
    float GetHealthPercent() const;
    
    FTankDelegate OnDeath;
    
private:
    UPROPERTY(EditDefaultsOnly, Category = "Setup")
    int32 StartingHealth = 100;
    
    UPROPERTY(EditDefaultsOnly, Category = "Health")
    int32 CurrentHealth = StartingHealth;
};