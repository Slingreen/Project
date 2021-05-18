// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractionObject.h"
#include "Painting.generated.h"

UCLASS()
class PROJECT_API APainting : public AInteractionObject
{
	GENERATED_BODY()

public:
		void Interacted();

	UPROPERTY(EditAnywhere, Category = "Rotation")
		int MoveSpeed = 2;

	UPROPERTY(EditAnywhere, Category = "Key")
		bool Unlocked{ false };

private:
	bool Move_B{ false };
	bool Open{ false };
	int Max_Loc{ 90 };
	int Current_Loc{ 0 };
	int Min_Loc{ 0 };
	void Move();
	
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
