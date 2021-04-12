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

	UPROPERTY(EditAnywhere, Category = "AI")
		class UBehaviorTree* BehaviorTree;


	UPROPERTY(VisibleAnywhere, Category = "AI")
		class UPawnSensingComponent* PawnSensing;

	FRotator NewRotation = FRotator(0.f, 0.f, 0.f);

	UPROPERTY(EditAnywhere, Category = "AI")
		float SentryIdleSpeed = 0.5f;

	bool RotateSentry();

	float CurrentTimer = 0.f;
private:

	UFUNCTION()
		void OnPlayerCaught(APawn* APawn);

	UPROPERTY(EditAnywhere, Category = "AI")
		float VisibleTimer = 5.f;





	bool PlayerVisible = false;	





};