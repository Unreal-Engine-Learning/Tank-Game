// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"

class UTankTrack;

/**
 * RESPONSIBLE FOR DRIVING THE TANK TRACKS
 */
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TANKS_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()
	
public:
    UFUNCTION( BlueprintCallable, Category = "Setup")
    void Initialise(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet);
    
    
    UFUNCTION( BlueprintCallable, Category = "Input")
    void IntendMoveForward( float Throw );
    
    UFUNCTION( BlueprintCallable, Category = "Input")
    void IntendTurnRight( float Throw );
    
    
private:
    // called from pathfinding logic by the AIControllers
    virtual void RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) override;
    UTankTrack* LeftTrack = nullptr;
    UTankTrack* RightTrack = nullptr;
};
