// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "PlayerAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_API UPlayerAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
	public:
			virtual void NativeInitializeAnimation() override;

			UFUNCTION(BlueprintCallable, Category = AnimationProperties)
				void UpdateAnimationProperties();

			UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Movement)
				class APawn* MyPawn{ nullptr };

			UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Movement)
				float MovementSpeed{ 0.f };

			UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Movement)
				bool bDeath{ false };
};
