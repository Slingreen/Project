// Fill out your copyright notice in the Description page of Project Settings.


#include "CrabAnim.h"
#include "Crabmonster.h"

void UCrabAnim::NativeInitializeAnimation()
{
	if (CrabPawn == nullptr)
	{
		CrabPawn = TryGetPawnOwner();
	}
}

void UCrabAnim::CrabUpdateAnimProperties()
{
	if (CrabPawn == nullptr)
	{
		CrabPawn = TryGetPawnOwner();
	}

	if (CrabPawn)
	{

		FVector TempSpeed = CrabPawn->GetVelocity();
		FVector LateralSpeed = FVector(TempSpeed.X, TempSpeed.Y, 0.f);
		CrabMoveSpeed = LateralSpeed.Size();
		CrabAttacking = Cast<ACrabmonster>(CrabPawn)->AmIAttacking;


	}
}
