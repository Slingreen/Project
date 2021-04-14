// Fill out your copyright notice in the Description page of Project Settings.


#include "CrabSelectPointTask.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AICrabController.h"
#include "CrabMonster.h"
#include "AICrabPoint.h"
#include "Math/UnrealMathUtility.h"


EBTNodeResult::Type UCrabSelectPointTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{

	AAICrabController* AICon = Cast<AAICrabController>(OwnerComp.GetAIOwner());
	ACrabmonster* Crab = Cast<ACrabmonster>(AICon->GetPawn());
	
	if (AICon)
	{
		UBlackboardComponent* BlackboardComp = AICon->GetBlackboardComponent();

		AAICrabPoint* CurrentKey = Cast<AAICrabPoint>(BlackboardComp->GetValueAsObject("MoveKey"));

		TArray<AActor*> AvailablePatrolKeys = AICon->GetPatrolKeys();

		Size = AvailablePatrolKeys.Num()-1;

		AAICrabPoint* NextPatrolKey = nullptr;

		Index = FMath::RandRange(0, Size);

		NextPatrolKey = Cast<AAICrabPoint>(AvailablePatrolKeys[Index]);

		BlackboardComp->SetValueAsObject("MoveKey", NextPatrolKey);


		//AActor* Crab = AICon->GetPawn();
		Crab->MeleeAttack();
		

		return EBTNodeResult::Succeeded;

		

		

	}

	return EBTNodeResult::Failed;
}
