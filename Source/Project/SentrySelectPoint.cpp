// Fill out your copyright notice in the Description page of Project Settings.


#include "SentrySelectPoint.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AISentryController.h"
#include "Sentry.h"
#include "PatrolPoint.h"

EBTNodeResult::Type USentrySelectPoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AAISentryController* AICon = Cast<AAISentryController>(OwnerComp.GetAIOwner());

	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Selecting new point"));
	if (AICon)
	{
		UBlackboardComponent* BlackboardComp = AICon->GetBlackboardComponent();

		APatrolPoint* CurrentKey = Cast<APatrolPoint>(BlackboardComp->GetValueAsObject("MoveKey"));

		TArray<AActor*> AvailablePatrolKeys = AICon->GetPatrolKeys();

		APatrolPoint* NextPatrolKey = nullptr;

		Size = AvailablePatrolKeys.Num() - 1;

		//Index = FMath::RandRange(0, Size);
		Index++;
		AICon->Index++;
		if (Index > Size)
		{
			Index = 0;
			AICon->Index = Index;
		}


		NextPatrolKey = Cast<APatrolPoint>(AvailablePatrolKeys[Index]);




		BlackboardComp->SetValueAsObject("MoveKey", NextPatrolKey);

		ASentry* Sentry = Cast<ASentry>(AICon->GetPawn());
		Sentry->GradualRotate();

		

		return EBTNodeResult::Succeeded;


	}

	return EBTNodeResult::Failed;
}
