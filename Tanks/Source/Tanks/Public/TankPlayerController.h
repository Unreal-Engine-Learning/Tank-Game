

#pragma once

#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class TANKS_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
private:
    virtual void BeginPlay() override;
    virtual void Tick( float DeltaTime ) override;
	
    ATank* GetControlledTank() const;
    ATank* GetPlayerTank() const;
    
    
    // Start the tank moving the barrel so that a shot would hit
    // where the crosshair intersects the world.
    void AimTowardsCrosshair();
    
    //return an out parameter, true if hit landscape
    bool GetSightRayHitLocation( FVector& HitLocation ) const;
};
