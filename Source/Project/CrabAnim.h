// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "CrabAnim.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_API UCrabAnim : public UAnimInstance
{
	GENERATED_BODY()
public:

		virtual void NativeInitializeAnimation() override;
	
		UFUNCTION(BlueprintCallable, Category = AnimationProperties)
		void CrabUpdateAnimProperties();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Movement)
		class APawn* CrabPawn{ nullptr };

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Movement)
		float CrabMoveSpeed{ 0.f };

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Movement)
		bool CrabAttacking{ false };

};
