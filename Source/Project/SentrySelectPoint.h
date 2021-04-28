// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "SentrySelectPoint.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_API USentrySelectPoint : public UBTTaskNode
{
	GENERATED_BODY()
	
		int Size;

	int Index{ 0 };

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

};
