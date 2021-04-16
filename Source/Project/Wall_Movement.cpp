// Fill out your copyright notice in the Description page of Project Settings.


#include "Wall_Movement.h"

// Sets default values
AWall_Movement::AWall_Movement()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AWall_Movement::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWall_Movement::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AWall_Movement::Wall_Raise()
{
	FVector Location = GetActorLocation();
	Location.Z = 140.f;
	SetActorLocation(Location);
}

void AWall_Movement::Wall_Lower()
{
	FVector Location = GetActorLocation();
	Location.Z = -50.f;
	SetActorLocation(Location);
}