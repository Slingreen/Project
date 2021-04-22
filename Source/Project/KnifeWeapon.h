// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "KnifeWeapon.generated.h"

UCLASS()
class PROJECT_API AKnifeWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AKnifeWeapon();


	//	Overlap function
	UFUNCTION()
		void OnOverlap(UPrimitiveComponent* OverlappedComponent,
			AActor* OtherActor,
			UPrimitiveComponent* OtherComponent,
			int32 OtherBodyIndex,
			bool bFromSweep,
			const FHitResult& SweepResult);

	// Attack collider = the dangerous part of the weapon
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Setup")
		class USphereComponent *AttackCollider{ nullptr };

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
		class USceneComponent *RootBase{ nullptr };

	UPROPERTY(EditAnywhere, Category = "Setup")
		class UStaticMeshComponent *WeaponMesh{ nullptr };

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
