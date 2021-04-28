// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Sentry.generated.h"

UCLASS()
class PROJECT_API ASentry : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASentry();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;





	//Used https://www.youtube.com/watch?v=3Z1A825gTA8 as a guide/base for the sentry AI

//<<<<<<< Updated upstream
//=======
	
	
//>>>>>>> Stashed changes
public:
	UPROPERTY(EditAnywhere, Category = "AI")
		class UBehaviorTree* BehaviorTree;


	UPROPERTY(VisibleAnywhere, Category = "AI")
		class UPawnSensingComponent* PawnSensing;

	//UPROPERTY(EditAnywhere, Category = "Setup")
	//	class UBoxComponent* Collider{ nullptr };

	FRotator NewRotation = FRotator(0.f, 0.f, 0.f);

	UPROPERTY(EditAnywhere, Category = "AI")
		float SentryIdleSpeed = 0.5f;

	



//<<<<<<< Updated upstream
public:

	void RotateSentry();

	//float CurrentTimer = 0.f;
//=======
	//void RotateSentry();
	UPROPERTY(VisibleAnywhere, Category = "AI")
	float CurrentTimer = 0.f;
	UPROPERTY(VisibleAnywhere, Category = "AI")
	float ShootCooldownTimer = 0.f;
	float ShootCooldown = 2.f;
	bool PlayerVisible = false;
	UPROPERTY(EditAnywhere, Category = "Setup")
		FVector Offset {
		0.f, 0.f, 0.f
	};

	UPROPERTY(EditAnywhere, Category = "Setup")
		bool Melee{ false };
	

	void Shoot();
	void Death();
	void GradualRotate();
	void Attack();
	UPROPERTY(EditAnywhere, Category = "Setup")
	bool NeedRotation{ false };
	float NeedRotationTimer{ 0.f };


	FRotator PlayerRotation = FRotator(0.f, 0.f, 0.f);
	
//>>>>>>> Stashed changes
private:

	UFUNCTION()
		void OnPlayerCaught(APawn* APawn);

	UPROPERTY(EditAnywhere, Category = "AI")
		float VisibleTimer = 5.f;

	UPROPERTY(EditAnywhere, Category = "Setup")
		TSubclassOf<class ASentryProjectile> ProjectileBlueprint;





	//bool PlayerVisible = false;	





};
