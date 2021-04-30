// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractionObject.h"
#include "KeyItem.generated.h"

UCLASS()
class PROJECT_API AKeyItem : public AInteractionObject
{
	GENERATED_BODY()
	
public:
	void Interacted();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Linked_Items");
	ADoor* Door{ nullptr };
};
