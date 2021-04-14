// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "AISentryController.h"
#include "Sentry.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "SentryRotateTask.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_API USentryRotateTask : public UBTTaskNode
{
	GENERATED_BODY()

		
		//class ASentry* Sentry;
		//bool Result = false;

		//Apparently I'm not supposed to override this function after all, though the videoguide I used says I'm supposed to (doesn't work when using virtual override)
		//Apparently it works when I copy the line over, even though I can't find what's written differently...And I need the override, or the task won't execute
		//Also, for osme reason UE kept making more of the same task in the behavior tree selection, the right one should be the one with the biggest number
		//EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8 NodeMemory);
		virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;



	
};
