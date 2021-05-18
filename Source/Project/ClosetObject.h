// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractionObject.h"
#include "ClosetObject.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_API AClosetObject : public AInteractionObject
{
	GENERATED_BODY()
public:
	void Interacted();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
private:
	FVector HideSpot{ 0.f, 0.f, 0.f };
};
