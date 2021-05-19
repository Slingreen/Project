// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "PatrolPoint.h"
#include "AICrabController.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_API AAICrabController : public AAIController
{
	GENERATED_BODY()

public:

	UBlackboardComponent* BlackboardCrab;
	UBehaviorTreeComponent* BehaviorCrab;

	int32 AllPatrolKeySize;
	int32 PatrolKeySize;

	UPROPERTY(EditAnywhere, Category = "AI")
		FName MoveKey;

	UPROPERTY(EditAnywhere, Category = "AI")
		FName PlayerKey;

	UPROPERTY(EditAnywhere, Category = "AI")
		FName PastPlayerKey;
		
	TArray<AActor*> PatrolKeys;
	TArray<AActor*> AllPatrolKeys;
	AActor* PatrolPoint{ nullptr };




	virtual void OnPossess(APawn* APawn) override;


public:
	AAICrabController();

	void SetPlayerCaught(APawn* APawn);

	int32 CurrentPatrolKey = 0;

	FORCEINLINE UBlackboardComponent* GetBlackboardComponent() const { return BlackboardCrab; }
	FORCEINLINE TArray<AActor*> GetPatrolKeys() const { return PatrolKeys; }

private:
	int ArraySize;
	
	
};
