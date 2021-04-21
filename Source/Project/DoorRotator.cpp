// Fill out your copyright notice in the Description page of Project Settings.


#include "DoorRotator.h"
#include "Components/BoxComponent.h"

// Sets default values for this component's properties
UDoorRotator::UDoorRotator()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	Collider = CreateDefaultSubobject<UBoxComponent>(TEXT("DoorCollider"));
	RootComponent = Collider;

	Collider->SetGenerateOverlapEvents(true);
}


// Called when the game starts
void UDoorRotator::BeginPlay()
{
	Super::BeginPlay();
}

void UDoorRotator::Collision(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweeb, const FHitResult& SweepResult)
{

}


// Called every frame
void UDoorRotator::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

