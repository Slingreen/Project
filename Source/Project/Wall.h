// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Wall.generated.h"

UCLASS()
class PROJECT_API AWall : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWall();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//  Collider
	UPROPERTY(EditAnywhere, Category = "Setup");
	class UBoxComponent* WallCollider{ nullptr };

	//  Visual mesh
	UPROPERTY(EditAnywhere, Category = "Mesh");
	class UStaticMeshComponent* MeshComponent{ nullptr };

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
