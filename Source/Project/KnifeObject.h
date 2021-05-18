// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractionObject.h"
#include "KnifeObject.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_API AKnifeObject : public AInteractionObject
{
	GENERATED_BODY()
public:
	void Interacted();
};
