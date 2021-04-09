// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "AICrabPoint.h"
#include "AICrabController.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_API AAICrabController : public AAIController
{
	GENERATED_BODY()

	UBlackboardComponent* BlackboardCrab;
	UBehaviorTreeComponent* BehaviorCrab;

	UPROPERTY(EditAnywhere, Category = "AI")
		FName MoveKey;

	UPROPERTY(EditAnywhere, Category = "AI")
		FName PlayerKey;

	UPROPERTY(EditAnywhere, Category = "AI")
		FName PastPlayerKey;
		
	TArray<AActor*> PatrolKeys;


	virtual void OnPossess(APawn* APawn) override;


public:
	AAICrabController();

	void SetPlayerCaught(APawn* APawn);

	int32 CurrentPatrolKey = 0;


	




	FORCEINLINE UBlackboardComponent* GetBlackboardComponent() const { return BlackboardCrab; }
	FORCEINLINE TArray<AActor*> GetPatrolKeys() const { return PatrolKeys; }
	
	
};
