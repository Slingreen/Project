// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Wall_UPDOWN.generated.h"

UCLASS()
class PROJECT_API AWall_UPDOWN : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWall_UPDOWN();

	void WallUp();
	void WallDown();

	//Mesh
	UPROPERTY(EditAnywhere, Category = "Basic")
		UStaticMeshComponent* Mesh{ nullptr };

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	const int Diff{ 190 };
};
