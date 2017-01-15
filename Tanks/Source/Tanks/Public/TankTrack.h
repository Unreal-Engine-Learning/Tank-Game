// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * TankTrack is used to apply forces to the tank
 */
UCLASS(meta=(BlueprintSpawnableComponent))
class TANKS_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
    UFUNCTION(BlueprintCallable, Category = "Input")
    void SetThrottle( float Throttle );
    // Max force per track in Newtons
    UPROPERTY(EditDefaultsOnly, Category = "Input")
    float TrackMaxDrivingForce = 400000; //assume 40 ton tank and 1 g acceleration
};
