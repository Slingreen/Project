// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Wall_UPDOWN.h"
#include "RoomTrigger.generated.h"

UCLASS()
class PROJECT_API ARoomTrigger : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARoomTrigger();

	//Collider
	UPROPERTY(EditAnywhere, Category = "Basic")
	class UBoxComponent* Collider{ nullptr };

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Linked_Items");
	AWall_UPDOWN* Walls{ nullptr };

	UFUNCTION(BlueprintCallable, Category = "OverlapEvents")
		void Enter();

	UFUNCTION(BlueprintCallable, Category = "OverlapEvents")
		void Exit();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	bool WallsDown{ false };
};
