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

		UGameplayStatics::GetAllActorsOfClass(GetWorld(), AAICrabPoint::StaticClass(), PatrolKeys);
		BlackboardCrab->SetValueAsObject(MoveKey, PatrolKeys[0]);


	}

}
