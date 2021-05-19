// Fill out your copyright notice in the Description page of Project Settings.


#include "CrabSelectPointTask.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AICrabController.h"
#include "CrabMonster.h"
#include "AICrabPoint.h"
#include "Math/UnrealMathUtility.h"


EBTNodeResult::Type UCrabSelectPointTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
//<<<<<<< Updated upstream

	//AAICrabController* AICon = Cast<AAICrabController>(OwnerComp.GetAIOwner());
	//ACrabmonster* Crab = Cast<ACrabmonster>(AICon->GetPawn());
//=======
//>>>>>>> Stashed changes
	
	AAICrabController* AICon = Cast<AAICrabController>(OwnerComp.GetAIOwner());
	//ACrabmonster* Crab = Cast<ACrabmonster>(AICon->GetPawn());
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Selecting new point"));
	if (AICon)
	{
		UBlackboardComponent* BlackboardComp = AICon->GetBlackboardComponent();

		AAICrabPoint* CurrentKey = Cast<AAICrabPoint>(BlackboardComp->GetValueAsObject("MoveKey"));

		TArray<AActor*> AvailablePatrolKeys = AICon->AllPatrolKeys;

		AActor* NextPatrolKey = nullptr;

		Size = AvailablePatrolKeys.Num() ;


		Index++;

		if (Index > Size - 1)
		{
			Index = 0;

		}
		if (Size > 0)
		{

			NextPatrolKey = AvailablePatrolKeys[Index];
			BlackboardComp->SetValueAsObject("MoveKey", NextPatrolKey);
			return EBTNodeResult::Succeeded;
		}
	}

	return EBTNodeResult::Failed;
}
