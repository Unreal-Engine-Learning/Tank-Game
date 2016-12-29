

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankTurret.generated.h"

/**
 * 
 */
UCLASS(meta=(BlueprintSpawnableComponent), hidecategories = ("Collision"))
class TANKS_API UTankTurret : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
    // -1 is max downward movement, +1 is  max upward movement
    void Rotate(float RelativeSpeed);
    
private:
    UPROPERTY(EditAnywhere, Category = Setup)
    float MaxDegreesPerSecond = 10;
};