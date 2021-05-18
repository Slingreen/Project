// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractionObject.h"
#include "Door.generated.h"

UCLASS()
class PROJECT_API ADoor : public AInteractionObject
{
	GENERATED_BODY()
	
public:
	ADoor();
	void Interacted();

	UPROPERTY(EditAnywhere, Category = "Rotation")
		int RotSpeed{ 2 };

	UPROPERTY(EditAnywhere, Category = "Key")
		bool Unlocked{ false };

	UPROPERTY(EditAnywhere, Category = "Key")
		bool Unlocked{ false };

private:
	bool Rotate_B{ false };
	bool Open{ false };
	int Max_Degrees{ 90 };
	int Current_Degree{ 0 };
	int Min_Degree{ 0 };
	void Rotate();

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
