// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "AISentryController.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_API AAISentryController : public AAIController
{
	GENERATED_BODY()


		//Used https://www.youtube.com/watch?v=3Z1A825gTA8 as a guide/base for the sentry AI

		UBehaviorTreeComponent* BehaviorSentry;

		UBlackboardComponent* BlackboardSentry;
		

		
		//Using APawn because using just Pawn apparently hides the class
		virtual void OnPossess(APawn* APawn) override;

//private:


public:
	AAISentryController();

	void SetPlayerCaught(APawn* APawn);

	UPROPERTY(EditDefaultsOnly, Category = "AI")
		FName PlayerKey;
	UPROPERTY(EditAnywhere, Category = "AI")
		bool PlayerVisible = false;

	float SentryYaw = 0.f;
	FRotator Rotation = FRotator(0.f, 0.f, 0.f);



	//class ASentry* AISentry;

private:
	TArray<AActor*> PatrolKeys;
	TArray<AActor*> AllPatrolKeys;
public:

	FORCEINLINE UBlackboardComponent* GetBlackboardComp() const { return BlackboardSentry; }

	class ASentry* BSentry;


};
