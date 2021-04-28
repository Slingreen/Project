// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TargetPoint.h"
#include "PatrolPoint.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_API APatrolPoint : public ATargetPoint
{
	GENERATED_BODY()

public:

		UPROPERTY(EditAnywhere, Category = "Setup")
		class ACharacter* PointOwner{ nullptr };


	
};