// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "SentryAnim.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_API USentryAnim : public UAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeInitializeAnimation() override;

	UFUNCTION(BlueprintCallable, Category = AnimationProperties)
		void UpdateAnimProperties();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Movement)
		class APawn* MyPawn{ nullptr };

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Movement)
		float MoveSpeed{ 0.f };

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Movement)
		bool Dying{ false };

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Movement)
		bool Attacking{ false };

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Movement)
		bool Shooting{ false };

};
