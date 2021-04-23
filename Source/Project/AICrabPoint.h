// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TargetPoint.h"
#include "Crabmonster.h"
#include "AICrabPoint.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_API AAICrabPoint : public ATargetPoint
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, Category = "Setup")
		class ACharacter* PointOwner{ nullptr };

	ACharacter* ReturnPointOwner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
};
