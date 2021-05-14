// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Stairs.generated.h"

UCLASS()
class PROJECT_API AStairs : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AStairs();

	//Collider
	UPROPERTY(EditAnywhere, Category = "Basic")
		class UBoxComponent* Col{ nullptr };

	//Mesh
	UPROPERTY(EditAnywhere, Category = "Mesh");
	UStaticMeshComponent* Mesh{ nullptr };

	//Level
	UPROPERTY(EditAnywhere, Category = "Level");
	FName NxtLvl = FName("Floor2");

	UFUNCTION()
		void ChangeFloorCollision(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
			UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweeb,
			const FHitResult& SweepResult);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
