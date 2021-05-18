// Fill out your copyright notice in the Description page of Project Settings.


#include "CrabAnim.h"
#include "Crabmonster.h"

void UCrabAnim::NativeInitializeAnimation()
{
	if (MyPawn == nullptr)
	{
		MyPawn = TryGetPawnOwner();
	}
}

void UCrabAnim::CrabUpdateAnimProperties()
{
	if (MyPawn == nullptr)
	{
		MyPawn = TryGetPawnOwner();
	}

	if (MyPawn)
	{

		FVector TempSpeed = MyPawn->GetVelocity();
		FVector LateralSpeed = FVector(TempSpeed.X, TempSpeed.Y, 0.f);
		CrabMoveSpeed = LateralSpeed.Size();
		CrabAttacking = Cast<ACrabmonster>(MyPawn)->AmIAttacking;


	}
}
