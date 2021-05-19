// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractionObject.h"
#include "Door.h"
#include "KeyItem.generated.h"

UCLASS()
class PROJECT_API AKeyItem : public AInteractionObject
{
	GENERATED_BODY()
	
public:
	void Interacted();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Linked_Items");
	TArray <ADoor*> Door{ nullptr };

private:
	int ArrLenght{ 0 };

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
