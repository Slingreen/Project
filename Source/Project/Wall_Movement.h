// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Wall_Movement.generated.h"

UCLASS()
class PROJECT_API AWall_Movement : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWall_Movement();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	UFUNCTION(BlueprintCallable, Category = "Blueprint_Code")//BlueprintImplementableEvent, BlueprintCallable
		void Wall_Lower();

	UFUNCTION(BlueprintCallable, Category = "Blueprint_Code")
		void Wall_Raise();

};
