// Fill out your copyright notice in the Description page of Project Settings.


#include "RoomTrigger.h"
#include "Components/BoxComponent.h"
#include "PlayerWilliam.h"

// Sets default values
ARoomTrigger::ARoomTrigger()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Collider
	Collider = CreateDefaultSubobject<UBoxComponent>(TEXT("Collider"));
	RootComponent = Collider;

	Collider->SetGenerateOverlapEvents(true);
}

void ARoomTrigger::OverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweeb, const FHitResult& SweepResult)
{
	if (OtherActor->IsA(APlayerWilliam::StaticClass())) {
		Walls->WallDown();
	}
}

void ARoomTrigger::OverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweeb, const FHitResult& SweepResult)
{
	if (OtherActor->IsA(APlayerWilliam::StaticClass())) {
		Walls->WallUp();
	}
}

// Called when the game starts or when spawned
void ARoomTrigger::BeginPlay()
{
	Super::BeginPlay();

	Cast<UBoxComponent>(RootComponent)->OnComponentBeginOverlap.AddDynamic(this, &ARoomTrigger::OverlapBegin);
	/*Cast<UBoxComponent>(RootComponent)->OnActorEndOverlap.AddDynamic(this, &ARoomTrigger::OverlapEnd);
	Collider->OnComponentEndOverlap.AddDynamic(this, &ARoomTrigger::OverlapEnd);*/
	Cast<UBoxComponent>(RootComponent)->OnComponentEndOverlap.AddDynamic(this, &ARoomTrigger::OverlapEnd);
}

// Called every frame
void ARoomTrigger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

