// Fill out your copyright notice in the Description page of Project Settings.


#include "SentryShootTask.h"
#include "Sentry.h"
#include "AISentryController.h"

EBTNodeResult::Type USentryShootTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{

	AAISentryController* AICon = Cast<AAISentryController>(OwnerComp.GetOwner());
	ASentry* Sentry = Cast<ASentry>(AICon->GetPawn());
	Sentry->Shoot();

	return EBTNodeResult::Succeeded;
}
