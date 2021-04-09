// Fill out your copyright notice in the Description page of Project Settings.


#include "AISentryController.h"
#include "Sentry.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BehaviorTree.h"



AAISentryController::AAISentryController()
{

	BehaviorSentry = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorSentry"));
	BlackboardSentry = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardSentry"));

	PlayerKey = "Target";

}																	




void AAISentryController::OnPossess(APawn* APawn)
{

	Super::OnPossess(APawn);

	ASentry* Sentry = Cast<ASentry>(APawn);

	if (Sentry)
	{
		if (Sentry->BehaviorTree->BlackboardAsset)
		{
			BlackboardSentry->InitializeBlackboard(*(Sentry->BehaviorTree->BlackboardAsset));


			BehaviorSentry->StartTree(*Sentry->BehaviorTree);


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






