// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PlayerControl.generated.h"

UCLASS()
class PROJECT_API APlayerControl : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerControl();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//	The mesh
	UPROPERTY(EditAnywhere, Category = "Setup");
	USceneComponent* OurVisibleComponent{ nullptr };

	//	Movement-speed
	UPROPERTY(EditAnywhere, Category = "Setup	")
		float MoveSpeed{ 50.f };

	//	Static Camera
	UPROPERTY(EditAnywhere, Category = "Setup");
	ACameraActor* StaticCamera{ nullptr };

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private: 
	//Functions for movement and shooting
	void MoveRight(float Value);

	//The movement that will be applied in the next Tick
	FVector CurrentVelocity{ 0.f };
};
