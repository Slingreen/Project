// Fill out your copyright notice in the Description page of Project Settings.


#include "Wall_UPDOWN.h"
#include "Components/BoxComponent.h"

// Sets default values
AWall_UPDOWN::AWall_UPDOWN()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Mesh
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = Mesh;
}

void AWall_UPDOWN::WallUp()
{
	FVector Loc = GetActorLocation();
	Loc.Z += Diff;
	SetActorLocation(Loc);
}

void AWall_UPDOWN::WallDown()
{
	FVector Loc = GetActorLocation();
	Loc.Z -= Diff;
	SetActorLocation(Loc);
}

// Called when the game starts or when spawned
void AWall_UPDOWN::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWall_UPDOWN::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

