

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
    UPROPERTY(EditAnywhere)
    float CrossHairXLocation = 0.5;
    
    UPROPERTY(EditAnywhere)
    float CrossHairYLocation = 0.33333;
    
    UPROPERTY(EditAnywhere)
    float LineTraceRange = 1000000;
    
    virtual void BeginPlay() override;
    virtual void Tick( float DeltaTime ) override;
	
    ATank* GetControlledTank() const;
    ATank* GetPlayerTank() const;
    
    
    // Start the tank moving the barrel so that a shot would hit
    // where the crosshair intersects the world.
    void AimTowardsCrosshair();
    
    //return an out parameter, true if hit landscape
    bool GetSightRayHitLocation( FVector& HitLocation ) const;
    bool GetLookDirection( FVector2D ScreenLocation, FVector& LookDirection ) const;
    bool GetLookVectorHitLocation(FVector LookDirection, FVector &HitLocation) const;
    
};