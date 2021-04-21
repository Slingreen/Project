// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DoorRotator.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECT_API UDoorRotator : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UDoorRotator();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Basic")
		class UBoxComponent* Collider{ nullptr };

	UFUNCTION()
		void Collision(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
			UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweeb,
			const FHitResult& SweepResult);

	//Timer
	UPROPERTY(EditAnywhere, Category = "Basic")
		float RotTime{ 9.f };

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
