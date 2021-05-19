// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Crabmonster.generated.h"

UCLASS()
class PROJECT_API ACrabmonster : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACrabmonster();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	UPROPERTY(EditAnywhere, Category = "AI")
		class UBehaviorTree* BehaviorTree;


	UPROPERTY(VisibleAnywhere, Category = "AI")
		class UPawnSensingComponent* Sensing;

	//UPROPERTY(EditAnywhere, Category = "Setup")
		//class UBoxComponent* Collider{ nullptr };

	//UPROPERTY(EditAnywhere, Category = "Setup")
		//class UBoxComponent* Root{ nullptr };
	//UFUNCTION()
		void MeleeAttack();
	UFUNCTION(BlueprintCallable)
		void AttackEnd();
	UFUNCTION(BlueprintCallable)
		void AttackKill();
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Animation")
		bool AmIAttacking{ false };
	UFUNCTION(BlueprintCallable)
		void AttackBottom();
	UFUNCTION(BlueprintCallable)
		void DisableOverlap();

	TArray<AActor*> AllPatrolKeys;

	UPROPERTY(VisibleAnywhere, Category = "AI")
		bool PlayerVisible = false;
	UPROPERTY(EditAnywhere, Category = "AI")
		float VisibleTimer = 5.f;
	UPROPERTY(VisibleAnywhere, Category = "AI")
		float CurrentTimer = 0.f;



private:

	UFUNCTION()
		void OnPlayerCaught(APawn* APawn);



	UFUNCTION()
		void Overlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
			UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweeb,
			const FHitResult& SweepResult);

	

};
