// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Wall_Movement.h"
#include "Room_Detection.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECT_API URoom_Detection : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	URoom_Detection();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Category = "Wall")
		void Overlap();

	UPROPERTY(EditAnywhere, Category = "Wall")
		class AWall_Movement* Wall_Move;

	UFUNCTION(BlueprintCallable, Category = "Wall")
		void EndOverlap();

	UFUNCTION(BlueprintCallable, Category = "Wall")
		void FailWarning3946();
};
