// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SentryProjectile.generated.h"

UCLASS()
class PROJECT_API ASentryProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASentryProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;



public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//Collider
	UPROPERTY(EditAnywhere, Category = "Setup")
		class USphereComponent* Collider{ nullptr };

	UFUNCTION()
		void Overlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
			UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweeb,
			const FHitResult& SweepResult);

	//Move
	UPROPERTY(EditAnywhere, Category = "Setup")
		float Speed{ 400.f };

	//FVector NewLocation = GetActorLocation();

	//Mesh
	UPROPERTY(EditAnywhere, Category = "Setup");
	UStaticMeshComponent* ProjectileMesh{ nullptr };

	//Timer
	UPROPERTY(EditAnywhere, Category = "Setup")
		float DestructionTime{ 4.f };

	float TimeLived{ 0.f };

};
