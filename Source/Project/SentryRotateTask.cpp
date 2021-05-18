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
	//Result = Sentry->RotateSentry();

	//if (Result)
	//{
	AAISentryController* AICon = Cast<AAISentryController>(OwnerComp.GetAIOwner());
	if (AICon)
	{
		ASentry* Sentry = Cast<ASentry>(AICon->GetPawn());
		if (Sentry)
		{

			Sentry->RotateSentry();
			//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("I'm Rotating :)"));
			//Result = false;
			return EBTNodeResult::Succeeded;

		}
	}
	return EBTNodeResult::Failed;
		
	//}
	//else
	//{
		//return EBTNodeResult::Failed;
	//}
}
