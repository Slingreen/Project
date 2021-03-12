// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Perception/PawnSensingComponent.h"
//#include "Math/Rotator.h"
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

		UPROPERTY(EditAnywhere, Category = "AI")
			class UPawnSensingComponent* Sensing;

		UFUNCTION()
			void OnSeePlayer(ACharacter* player);

		UPROPERTY(EditAnywhere, Category = "AI")
			float RotationSpeed{ 10.f };


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
