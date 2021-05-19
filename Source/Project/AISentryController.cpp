// Fill out your copyright notice in the Description page of Project Settings.


#include "AISentryController.h"
#include "Sentry.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "PatrolPoint.h"
#include "Kismet/GameplayStatics.h"



AAISentryController::AAISentryController()
{

	BehaviorSentry = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorSentry"));
	BlackboardSentry = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardSentry"));

	PlayerKey = "Target";
	MoveKey = "MoveKey";
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), APatrolPoint::StaticClass(), AllPatrolKeys);
	AllPatrolKeySize = AllPatrolKeys.Num();
}																	




void AAISentryController::OnPossess(APawn* APawn)
{

	Super::OnPossess(APawn);

	ASentry* Sentry = Cast<ASentry>(APawn);

	if (Sentry)
	{
		if (Sentry->Melee)
		{
			Melee = "Melee";

			BlackboardSentry->SetValueAsBool(Melee, true);

		}

		if (Sentry->BehaviorTree->BlackboardAsset)
		{
			BlackboardSentry->InitializeBlackboard(*(Sentry->BehaviorTree->BlackboardAsset));
			BehaviorSentry->StartTree(*Sentry->BehaviorTree);
		}
		if (Sentry->Melee)
		{
			
			//ArraySize = PatrolKeys.Num();
			//AllPatrolKeys = Sentry->AllPatrolKeys;
			for (int i = 0; i < AllPatrolKeySize; i++)
			{
				
				APatrolPoint* PatrolRef = Cast<APatrolPoint>(AllPatrolKeys[i]);

				if (PatrolRef->PointOwner != nullptr)
				{


					if (PatrolRef->PointOwner->GetName() == Sentry->GetName())
					{
						GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("First "));
						Sentry->PatrolKeys.Insert(AllPatrolKeys[i], -1);
					}
				}
			}
			if (Sentry->PatrolKeys.Num() > 0)
			{
				
				//BlackboardSentry->SetValueAsObject(MoveKey, Sentry->PatrolKeys[0]);
				BlackboardSentry->SetValueAsObject(MoveKey, Sentry->PatrolKeys[0]);
			}
		}
	}
}

void AAISentryController::SetPlayerCaught(APawn* APawn)
{

	if (BlackboardSentry)
	{

			BlackboardSentry->SetValueAsObject(PlayerKey, APawn);

	}

}






