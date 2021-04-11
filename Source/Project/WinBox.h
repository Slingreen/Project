// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WinBox.generated.h"

UCLASS()
class PROJECT_API AWinBox : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWinBox();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	//  Collider
	UPROPERTY(EditAnywhere, Category = "Setup");
	class UBoxComponent* OurCollider{ nullptr };

	UFUNCTION()
		void OnOverlap(UPrimitiveComponent* OverlappedComponent,
			AActor* OtherActor,
			UPrimitiveComponent* OtherComponent,
			int32 OtherBodyIndex,
			bool bFromSweep,
			const FHitResult& SweepResult);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
