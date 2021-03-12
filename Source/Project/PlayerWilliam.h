// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerWilliam.generated.h"

UCLASS()
class PROJECT_API APlayerWilliam : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerWilliam();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	// Camera boom positioning the camera behind the character
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
		class USpringArmComponent* CameraBoom;

	// Camera
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
		class UCameraComponent* FollowCamera;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	//Functions for movement
	void MoveForward(float Value);
	void MoveRight(float Value);
	//UCharacterMovementComponent* CM;
};
