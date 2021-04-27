// Fill out your copyright notice in the Description page of Project Settings.


#include "CrabSelectPointTask.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AICrabController.h"
#include "CrabMonster.h"
#include "PatrolPoint.h"
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
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Selecting new point"));
	if (AICon)
	{
		UBlackboardComponent* BlackboardComp = AICon->GetBlackboardComponent();

		APatrolPoint* CurrentKey = Cast<APatrolPoint>(BlackboardComp->GetValueAsObject("MoveKey"));

		TArray<AActor*> AvailablePatrolKeys = AICon->GetPatrolKeys();

		APatrolPoint* NextPatrolKey = nullptr;

		Size = AvailablePatrolKeys.Num() - 1;

		//for (int i = 0; i < 1; i++)
		//{
			//PatrolPoint = AvailablePatrolKeys[0];
			Index = FMath::RandRange(0, Size);

			NextPatrolKey = Cast<APatrolPoint>(AvailablePatrolKeys[Index]);

			
			
			/*if (CurrentKey == NextPatrolKey)
			{
				i--;
			}*/


//<<<<<<< Updated upstream
		//AActor* Crab = AICon->GetPawn();
		//Crab->MeleeAttack();
		
//=======
			//AActor* Crab = AICon->GetPawn();
			//Crab->MeleeAttack();
//>>>>>>> Stashed changes

		//}
		BlackboardComp->SetValueAsObject("MoveKey", NextPatrolKey);
		return EBTNodeResult::Succeeded;


	}

	return EBTNodeResult::Failed;
}
