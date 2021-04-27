// Fill out your copyright notice in the Description page of Project Settings.


#include "AICrabController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "Crabmonster.h"
#include "PatrolPoint.h"
#include "Kismet/GameplayStatics.h"






AAICrabController::AAICrabController()
{

	BehaviorCrab = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorCrab"));
	BlackboardCrab = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardCrab"));

	PlayerKey = "PlayerKey";
	MoveKey = "MoveKey";
	PastPlayerKey = "PastPlayerKey";
}

void AAICrabController::SetPlayerCaught(APawn* APawn)
{

	if (BlackboardCrab)
	{
		BlackboardCrab->SetValueAsObject(PlayerKey, APawn);
	}

}


void AAICrabController::OnPossess(APawn* APawn)
{

	Super::OnPossess(APawn);

	ACrabmonster* CrabMonster = Cast<ACrabmonster>(APawn);

	if (CrabMonster)
	{
		
		if (CrabMonster->BehaviorTree->BlackboardAsset)
		{
			BlackboardCrab->InitializeBlackboard(*(CrabMonster->BehaviorTree->BlackboardAsset));

			BehaviorCrab->StartTree(*CrabMonster->BehaviorTree);
		}

		
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), APatrolPoint::StaticClass(), AllPatrolKeys);
		//ArraySize = PatrolKeys.Num();
		for (int i = 0; i < AllPatrolKeys.Num(); i++)
		{

			APatrolPoint* PatrolRef = Cast<APatrolPoint>(AllPatrolKeys[i]);

			if (PatrolRef->PointOwner != nullptr)
			{


				if (PatrolRef->PointOwner->GetName() == CrabMonster->GetName())
				{

					//The code does what I want it to, but also not
					//This happens whenever PointOwnerName = CrabMonsterName,
					//but it still only goes to the points I choose
					//Only seems to choose one when I try to remove from a tarray istead of adding them to a different one.

					//Also, this only seems to trigger once when I pass it into another tarray.

					//CrabMonster->GetName
					GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("I own this"));
					PatrolKeys.Insert(AllPatrolKeys[i],i);
					//PatrolKeys.RemoveAt(i);
					//i--;
					//i++;
					//ArraySize = PatrolKeys.Num();


				}

			}
			//A = GetOwner()->FindComponentByClass<AAICrabPoint>();
			//PatrolPoint.get
			
			//if (Patrolpoint.PatrolOwner)
			//if (AllPatrolKeys[i]->PointOwner == this)
			//{

				//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("I found a control point"));
					
			//}

		}
		BlackboardCrab->SetValueAsObject(MoveKey, PatrolKeys[0]);


	}

}
