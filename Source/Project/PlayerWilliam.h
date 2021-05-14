// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerWilliam.generated.h"

UCLASS()
class PROJECT_API APlayerWilliam : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerWilliam();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	// Camera boom positioning the camera behind the character
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
		class USpringArmComponent* CameraBoom;

	// Camera
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
		class UCameraComponent* FollowCamera;

	// Interact collider
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Colliders")
		class UBoxComponent* InteractCollider;


	// Interaction
	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
		TSubclassOf<class AInteractionBox> InteractionBox;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class AInteractionBox* MyInteraction{ nullptr };

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Animation")
		bool bIsInteracting{ false };

	UFUNCTION(BlueprintCallable)
		void InteractFinished();


	// Melee Weapon
	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
		TSubclassOf<class AKnifeWeapon> WeaponType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class AKnifeWeapon* MyWeapon{ nullptr };

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Animation")
		bool bIsAttacking{ false };

	UFUNCTION(BlueprintCallable)
		void AttackFinished();


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Setup")
		bool bWin{ false };

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Animation")
		bool bAmIDead{ false };

	void Hiding(FVector p);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//	Overlap function
	UFUNCTION()
		void OnOverlap(UPrimitiveComponent* OverlappedComponent,
			AActor* OtherActor,
			UPrimitiveComponent* OtherComponent,
			int32 OtherBodyIndex,
			bool bFromSweep,
			const FHitResult& SweepResult);

	float TimeBetweenSpawns{ 0.25f };
	float TimeGone{ 0.f };

	float MaxSneakSpeed{ 300.f };
	float MaxWalkSpeed{ 600.f };
	

private:
	
	//Functions for movement
	void MoveForward(float Value);
	void MoveRight(float Value);

	void StartFast();
	void StopFast();

	void StartAttack();
	void StopAttack();

	void StartInteract();
	void StopInteract();

	bool bAttackFinished{ false };		//Used to make the whole attack animation run
	bool bInteractFinished{ false };		//Used to make the whole attack animation run

public: 
	void death();
	void Win();
};
