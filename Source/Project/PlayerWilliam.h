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

	// Camera
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Setup")
		class USceneComponent* SoundSource{ nullptr };

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Setup")
		bool AmIDead{ false };

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Setup")
		bool bWin{ false };

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//	The bullets
	UPROPERTY(EditAnywhere, Category = "Setup");
	TSubclassOf<class ASoundBall> SoundBlueprint;

	//	Spawn Position
	UPROPERTY(EditAnywhere, Category = "Setup");
	FVector SpawnPoint{ 0.f, 0.f, -50.f };

	float TimeBetweenSpawns{ 0.25f };
	float TimeGone{ 0.f };

	float MaxSneakSpeed{ 300.f };
	float MaxWalkSpeed{ 600.f };
	

private:
	
	//Functions for movement
	void MoveForward(float Value);
	void MoveRight(float Value);

	void StartFast();
	void StopFast();



	void Sound();
public: 
	void death();
	void Win();
};
