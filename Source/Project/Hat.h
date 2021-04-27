// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractionObject.h"
#include "PlayerWilliam.h"
#include "Hat.generated.h"

UCLASS()
class PROJECT_API AHat : public AInteractionObject
{
	GENERATED_BODY()

public:
	void Interacted();
	bool Placed(FVector Loc);

	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	bool Movable{ false };
};
