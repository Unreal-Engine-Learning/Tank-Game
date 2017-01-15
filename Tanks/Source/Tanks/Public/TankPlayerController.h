

#pragma once


#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"


class ATank;
class UTankAimingComponent;

/**
 * Responsible for helping the player aim.
 */
UCLASS()
class TANKS_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
    UFUNCTION(BlueprintCallable, Category = "Setup")
    ATank* GetControlledTank() const;
    
    UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
    void FoundAimingComponent(UTankAimingComponent* AimCompRef);

private:
    UPROPERTY(EditDefaultsOnly)
    float CrossHairXLocation = 0.5;
    
    UPROPERTY(EditDefaultsOnly)
    float CrossHairYLocation = 0.33333;
    
    UPROPERTY(EditDefaultsOnly)
    float LineTraceRange = 1000000;
    
    virtual void BeginPlay() override;
    virtual void Tick( float DeltaTime ) override;
	
    ATank* GetPlayerTank() const;
    
    // Start the tank moving the barrel so that a shot would hit
    // where the crosshair intersects the world.
    void AimTowardsCrosshair();
    
    //return an out parameter, true if hit landscape
    bool GetSightRayHitLocation( FVector& HitLocation ) const;
    bool GetLookDirection( FVector2D ScreenLocation, FVector& LookDirection ) const;
    bool GetLookVectorHitLocation(FVector LookDirection, FVector &HitLocation) const;
    
};