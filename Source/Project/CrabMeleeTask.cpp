// Fill out your copyright notice in the Description page of Project Settings.


#include "CrabMeleeTask.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AICrabController.h"
#include "CrabMonster.h"

EBTNodeResult::Type UCrabMeleeTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{

	AAICrabController* AICon = Cast<AAICrabController>(OwnerComp.GetAIOwner());
	ACrabmonster* Crab = Cast<ACrabmonster>(AICon->GetPawn());
	if (AICon)
	{
	
		Crab->MeleeAttack();

	}
	return EBTNodeResult::Type();
}
