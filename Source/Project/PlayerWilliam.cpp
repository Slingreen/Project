// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerWilliam.h"

// Sets default values
APlayerWilliam::APlayerWilliam()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlayerWilliam::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerWilliam::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerWilliam::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("Forward", this, &APlayerWilliam::MoveForward);
	PlayerInputComponent->BindAxis("Right", this, &APlayerWilliam::MoveRight);
}

void APlayerWilliam::MoveForward(float Value)
{
	FVector Direction;
	Direction = GetActorForwardVector();
	AddMovementInput(Direction, Value);
}

void APlayerWilliam::MoveRight(float Value)
{
	FVector Direction;
	Direction = GetActorRightVector();
	AddMovementInput(Direction, Value);
}

