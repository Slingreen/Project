// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerAnimInstance.h"
#include "GameFramework/CharacterMovementComponent.h"

void UPlayerAnimInstance::NativeInitializeAnimation()
{
	if (MyPawn == nullptr)
	{
		MyPawn = TryGetPawnOwner();
	}
}

void UPlayerAnimInstance::UpdateAnimationProperties()
{
	if (MyPawn == nullptr)
	{
		MyPawn = TryGetPawnOwner();
	}

	if (MyPawn)
	{
		FVector TempSpeed = MyPawn->GetVelocity();
		FVector LateralSpeed = FVector(TempSpeed.X, TempSpeed.Y, 0.f);
		MovementSpeed = LateralSpeed.Size();
	}
}
