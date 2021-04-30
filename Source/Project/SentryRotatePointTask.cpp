// Fill out your copyright notice in the Description page of Project Settings.


#include "SentryRotatePointTask.h"
#include "AISentryController.h"
#include "Sentry.h"


EBTNodeResult::Type USentryRotatePointTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	//return EBTNodeResult::Type();

	AAISentryController* AICon = Cast<AAISentryController>(OwnerComp.GetAIOwner());
	if (AICon)
	{
		ASentry* Sentry = Cast<ASentry>(AICon->GetPawn());
		if (Sentry)
		{
			if (Sentry->NeedRotation)
			{

				return EBTNodeResult::Succeeded;

			}
			else if (Sentry->NeedRotation == false)
			{
				//Sentry->NeedRotation = true;

				return EBTNodeResult::Failed;
			}
		}
	}
	return EBTNodeResult::Failed;
}
