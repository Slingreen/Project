// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SoundBall.generated.h"

UCLASS()
class PROJECT_API ASoundBall : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASoundBall();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

    //  Speed
    UPROPERTY(EditAnywhere, Category = "Setup")
        float Speed{ 1.1f };

    //  Bullet lifetime
    UPROPERTY(EditAnywhere, Category = "Setup")
        float TimeBeforeDestroy{ 0.3f };

    //  Time lived
    float TimeLived{ 0.f };

    //  Collider
    UPROPERTY(EditAnywhere, Category = "Setup");
    class USphereComponent* OurCollider{ nullptr };

    //  Visual mesh
    UPROPERTY(EditAnywhere, Category = "Setup");
    class UStaticMeshComponent* OurVisibleComponent{ nullptr };

    //This is the function that gets called when the collider of this object 
    //overlaps another object in the world.
    //Both objects have to have the "Generate Overlap Events" set for this to work!!!!
    //This function must be a UFUNCTION
    UFUNCTION()
        void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
            UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex,
            bool bFromSweep, const FHitResult& SweepResult);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
