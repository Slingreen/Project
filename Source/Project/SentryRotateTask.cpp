// Fill out your copyright notice in the Description page of Project Settings.


#include "SentryRotateTask.h"

//EBTNodeResult::Type USentryRotateTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8 NodeMemory)
//{
//
//
//	
//}

EBTNodeResult::Type USentryRotateTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AAISentryController* AICon = Cast<AAISentryController>(OwnerComp.GetAIOwner());
	ASentry* Sentry = Cast<ASentry>(AICon->GetPawn());

	if (AICon)
	{

		if (Sentry->PlayerVisible)
		{

			if (Sentry->ShootCooldownTimer > Sentry->ShootCooldown)
			{
				Sentry->Shoot();
			}
			return EBTNodeResult::Succeeded;
			//AICon->SetActorRotation();

		}
		else 
		{
			Sentry->RotateSentry();
			//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("I'm Rotating :)"));
			return EBTNodeResult::Succeeded;
		}
		

	}
	return EBTNodeResult::Succeeded;
	

}


