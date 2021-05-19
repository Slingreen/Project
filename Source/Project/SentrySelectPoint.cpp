// Fill out your copyright notice in the Description page of Project Settings.


#include "SentrySelectPoint.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AISentryController.h"
#include "Sentry.h"
#include "PatrolPoint.h"

EBTNodeResult::Type USentrySelectPoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AAISentryController* AICon = Cast<AAISentryController>(OwnerComp.GetAIOwner());
	ASentry* Sentry = Cast<ASentry>(AICon->GetPawn());

	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Sentry Selecting new point"));
	if (AICon)
	{
		UBlackboardComponent* BlackboardComp = AICon->GetBlackboardComponent();

		APatrolPoint* CurrentKey = Cast<APatrolPoint>(BlackboardComp->GetValueAsObject("MoveKey"));

		TArray<AActor*> AvailablePatrolKeys = Sentry->PatrolKeys;

		//APatrolPoint* NextPatrolKey = nullptr;
		AActor* NextPatrolKey = nullptr;

		Size = AvailablePatrolKeys.Num() ;

		//Index = FMath::RandRange(0, Size);
		
		if (Index > Size-1)
		{
			Index = 0;
			//Sentry->Index = Index;
		}
		if (Size > 0)
		{
			//NextPatrolKey = Cast<APatrolPoint>(AvailablePatrolKeys[Index]);
			NextPatrolKey = AvailablePatrolKeys[Index];
			BlackboardComp->SetValueAsObject("MoveKey", NextPatrolKey);
			//Sentry->PatrolLocation = NextPatrolKey->GetActorLocation();
			//Sentry->GradualRotate();
			Index++;
			//Sentry->Index = Index;
			return EBTNodeResult::Succeeded;
		}
		
	}
	return EBTNodeResult::Failed;
}
