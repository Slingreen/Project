// Fill out your copyright notice in the Description page of Project Settings.


#include "Room_Detection.h"
#include "PlayerWilliam.h"

// Sets default values for this component's properties
URoom_Detection::URoom_Detection()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void URoom_Detection::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void URoom_Detection::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void URoom_Detection::Overlap()
{
	Wall_Move->Wall_Lower();
	//FailWarning3946();
}

void URoom_Detection::EndOverlap()
{
	Wall_Move->Wall_Raise();
}

void URoom_Detection::FailWarning3946()
{
	UE_LOG(LogTemp, Warning, TEXT("I'M here"));
}

