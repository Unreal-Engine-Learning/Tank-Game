// Fill out your copyright notice in the Description page of Project Settings.

#include "Tanks.h"
#include "TankAimingComponent.h"
#include "TankAIController.h"
#include "Tank.h"


void ATankAIController::BeginPlay()
{
    Super::BeginPlay();
}

void ATankAIController::SetPawn(APawn* InPawn)
{
    Super::SetPawn(InPawn);
    if (InPawn)
    {
        auto PossessedTank = Cast<ATank>(InPawn);
        if (!ensure(PossessedTank)) { return; }
        
        //subscribe local method
        PossessedTank->OnDeath.AddUniqueDynamic(this, &ATankAIController::OnPossedTankDeath);
    }
}

void ATankAIController::OnPossedTankDeath()
{
    UE_LOG(LogTemp, Warning, TEXT("Received!"))
}

void ATankAIController::Tick(float DeltaTime)
{
    Super::Tick( DeltaTime );
    
    auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
    
    auto ControlledTank = GetPawn();
    
    if (!ensure(PlayerTank && ControlledTank)) { return; }
    // move towards player
    MoveToActor(PlayerTank, AcceptanceRadius);
        
    // aim at the player
    auto AimingComponent = ControlledTank->FindComponentByClass<UTankAimingComponent>();
    AimingComponent->AimAt(PlayerTank->GetActorLocation());
        
    // fire if ready
    if (AimingComponent->GetFiringState() == EFiringState::Locked) {
        AimingComponent->Fire();
    }
}