// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "CrabSelectPointTask.generated.h"


/**
 * 
 */
UCLASS()
class PROJECT_API UCrabSelectPointTask : public UBTTaskNode
{
	GENERATED_BODY()

		int Size;
		
		int Index;

		virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	
};
