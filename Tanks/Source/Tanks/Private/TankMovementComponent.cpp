// Fill out your copyright notice in the Description page of Project Settings.

#include "Tanks.h"
#include "TankTrack.h"
#include "TankMovementComponent.h"

void UTankMovementComponent::Initialise(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet)
{
    if (!LeftTrackToSet || !RightTrackToSet) { return; }
    LeftTrack = LeftTrackToSet;
    RightTrack = RightTrackToSet;
}

void UTankMovementComponent::IntendMoveForward(float Throw)
{
    if (!ensure(LeftTrack && RightTrack)) { return; }
    LeftTrack->SetThrottle(Throw);
    RightTrack->SetThrottle(Throw);
}

void UTankMovementComponent::IntendTurnRight(float Throw)
{
    if (!ensure(LeftTrack && RightTrack)) { return; }
    LeftTrack->SetThrottle(Throw);
    RightTrack->SetThrottle(-Throw);
}

void UTankMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed)
{
    // no need to call super as we are replacing functionality
    
    auto TankForward = GetOwner()->GetActorForwardVector().GetSafeNormal();
    auto AIForwardIntention = MoveVelocity.GetSafeNormal();
    auto ForwardThrow = FVector::DotProduct(TankForward, AIForwardIntention);
    auto RightThrow = FVector::CrossProduct(AIForwardIntention, TankForward).Z;
    
    IntendTurnRight(RightThrow);
    IntendMoveForward(ForwardThrow);
}