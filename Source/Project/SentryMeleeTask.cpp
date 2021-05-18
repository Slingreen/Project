// Fill out your copyright notice in the Description page of Project Settings.


#include "SentryMeleeTask.h"
#include "AISentryController.h"
#include "Sentry.h"
//#include "PlayerWilliam.h"



EBTNodeResult::Type USentryMeleeTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Sentry attack"));
	AAISentryController* AICon = Cast<AAISentryController>(OwnerComp.GetAIOwner());
	ASentry* Sentry = Cast<ASentry>(AICon->GetPawn());

	Sentry->Attack();

	//GetWorld()->GetPlayer
	//ACharacter* Player = UGameplayStatics::GetPlayerCharacter(this, 0);
	//Player.death();
	//APlayerWilliam* Player = Cast<APlayerWilliam>(GetCharacter());
	//APlayerController* PlayerController = Cast<APlayerController>(GEngine->GetFirstLocalPlayerController(GetWorld()));
	//APlayerWilliam* Player = Cast<APlayerWilliam>(PlayerController->GetCharacter());
	//Player->death();
	
	return EBTNodeResult::Succeeded;
}
