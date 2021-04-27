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
			UGameplayStatics::GetAllActorsOfClass(GetWorld(), APatrolPoint::StaticClass(), AllPatrolKeys);
			//ArraySize = PatrolKeys.Num();
			for (int i = 0; i < AllPatrolKeys.Num(); i++)
			{

				APatrolPoint* PatrolRef = Cast<APatrolPoint>(AllPatrolKeys[i]);

				if (PatrolRef->PointOwner != nullptr)
				{


					if (PatrolRef->PointOwner->GetName() == Sentry->GetName())
					{

						//The code does what I want it to, but also not
						//This happens whenever PointOwnerName = CrabMonsterName,
						//but it still only goes to the points I choose
						//Only seems to choose one when I try to remove from a tarray istead of adding them to a different one.

						GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("I own this"));
						PatrolKeys.Insert(AllPatrolKeys[i], i);
					}
					
				}
			}
			BlackboardSentry->SetValueAsObject(MoveKey, PatrolKeys[0]);
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






