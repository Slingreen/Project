// Fill out your copyright notice in the Description page of Project Settings.


#include "CrabMeleeTask.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AICrabController.h"
#include "CrabMonster.h"
#include "PlayerWilliam.h"

EBTNodeResult::Type UCrabMeleeTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{

	AAICrabController* AICon = Cast<AAICrabController>(OwnerComp.GetAIOwner());
	ACrabmonster* Crab = Cast<ACrabmonster>(AICon->GetPawn());
	if (AICon)
	{
	
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("AttackTriggered"));
		Crab->MeleeAttack();

	}
	//APlayerController* PlayerController = Cast<APlayerController>(GEngine->GetFirstLocalPlayerController(GetWorld()));
	//APlayerWilliam* Player = Cast<APlayerWilliam>(PlayerController->GetCharacter());
	//Player->death();
	return EBTNodeResult::Succeeded;
}															  
