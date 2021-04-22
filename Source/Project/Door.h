// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Door.generated.h"

UCLASS()
class PROJECT_API ADoor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADoor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
<<<<<<< Updated upstream

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

=======
	
	//Collider
>>>>>>> Stashed changes
	UPROPERTY(EditAnywhere, Category = "Basic")
		class UBoxComponent* Collider{ nullptr };

	UFUNCTION()
<<<<<<< Updated upstream
		void Collision(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
			UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweeb,
			const FHitResult& SweepResult);

	//Timer
	UPROPERTY(EditAnywhere, Category = "Basic")
		float RotTime{ 9.f };

=======
		void Collision(UPrimitiveComponent* OverlappedComponent, AActor* Colliding_obj,
			UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweeb,
			const FHitResult& SweepResult);

	//Mesh
	UPROPERTY(EditAnywhere, Category = "Mesh");
	UStaticMeshComponent* Door_Mesh{ nullptr };

	//Timer
	UPROPERTY(EditAnywhere, Category = "Rotation")
		float RotationTimer{ 4.f };

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	bool Open{ false };
	int Max_Degrees{ 90 };
	int Current_Degree{ 0 };
	void Rotate();
>>>>>>> Stashed changes
};
