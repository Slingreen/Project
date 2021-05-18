// Fill out your copyright notice in the Description page of Project Settings.


#include "SentryAnim.h"
#include "Sentry.h"


void USentryAnim::NativeInitializeAnimation()
{
	if (MyPawn == nullptr)
	{
		MyPawn = TryGetPawnOwner();
	}
}

void USentryAnim::UpdateAnimProperties()
{
	if (MyPawn == nullptr)
	{
		MyPawn = TryGetPawnOwner();
	}

	if (MyPawn)
	{

		FVector TempSpeed = MyPawn->GetVelocity();
		FVector LateralSpeed = FVector(TempSpeed.X, TempSpeed.Y, 0.f);
		MoveSpeed = LateralSpeed.Size();
		Dying = Cast<ASentry>(MyPawn)->AmIDead;
		Attacking = Cast<ASentry>(MyPawn)->AmIAttacking;
		Shooting = Cast<ASentry>(MyPawn)->AmIShooting;

	}

}
