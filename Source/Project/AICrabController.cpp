// Fill out your copyright notice in the Description page of Project Settings.


#include "AICrabController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "Crabmonster.h"
#include "AICrabPoint.h"
#include "Kismet/GameplayStatics.h"






AAICrabController::AAICrabController()
{

	BehaviorCrab = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorCrab"));
	BlackboardCrab = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardCrab"));

	PlayerKey = "PlayerKey";
	MoveKey = "MoveKey";
	PastPlayerKey = "PastPlayerKey";
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AAICrabPoint::StaticClass(), AllPatrolKeys);
}


void AAICrabController::OnPossess(APawn* APawn)
{

	Super::OnPossess(APawn);
	

	ACrabmonster* CrabMonster = Cast<ACrabmonster>(APawn);

	//AllPatrolKeys = CrabMonster->AllPatrolKeys;
	//AllPatrolKeySize = AllPatrolKeys.Num();

	if (CrabMonster)
	{
		
		if (CrabMonster->BehaviorTree->BlackboardAsset)
		{
			
			BlackboardCrab->InitializeBlackboard(*(CrabMonster->BehaviorTree->BlackboardAsset));

			BehaviorCrab->StartTree(*CrabMonster->BehaviorTree);
		}
		//ArraySize = PatrolKeys.Num();
		
		//for (int i = 0; i < AllPatrolKeySize; i++)
		//{
		//	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Crab behavior is good"));
		//	AAICrabPoint* PatrolRef = Cast<AAICrabPoint>(AllPatrolKeys[i]);

		//	if (PatrolRef->PointOwner != nullptr)
		//	{
		//		
		//		if (PatrolRef->PointOwner->GetName() == CrabMonster->GetName())
		//		{
		//			//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Crab Owns this point"));
		//			PatrolKeys.Insert(AllPatrolKeys[i],i);
		//		}
		//	}
		//}
		if (AllPatrolKeys.Num() > 0)
		{
			//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("MoveKey is set"));
			BlackboardCrab->SetValueAsObject(MoveKey, AllPatrolKeys[0]);
		}
	}
}


void AAICrabController::SetPlayerCaught(APawn* APawn)
{

	if (BlackboardCrab)
	{
		BlackboardCrab->SetValueAsObject(PlayerKey, APawn);
	}

}