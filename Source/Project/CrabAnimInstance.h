// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "CrabAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_API UCrabAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:

		UFUNCTION(BlueprintCallable, Category = "Properties")
		void UpdateProperties();

		UPROPERTY(EditAnywhere, Category = "Setup")
			class UPawn* ThisPawn{ nullptr };

	

};
