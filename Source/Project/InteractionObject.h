// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InteractionObject.generated.h"

UCLASS()
class PROJECT_API AInteractionObject : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInteractionObject();

	virtual void Interacted();

	//Collider
	UPROPERTY(EditAnywhere, Category = "Basic")
		class UBoxComponent* Collider{ nullptr };

	//Mesh
	UPROPERTY(EditAnywhere, Category = "Mesh");
	UStaticMeshComponent* Door_Mesh{ nullptr }; //I made this intended for the Doors first

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Comment")
		FString Comment {""};

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
