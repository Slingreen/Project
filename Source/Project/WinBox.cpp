// Fill out your copyright notice in the Description page of Project Settings.


#include "WinBox.h"
#include "PlayerWilliam.h"
#include "Components/BoxComponent.h"

// Sets default values
AWinBox::AWinBox()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Collision object and RootObject
	OurCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("MyCollider"));
	RootComponent = OurCollider;
	OurCollider->SetGenerateOverlapEvents(true);
}

// Called when the game starts or when spawned
void AWinBox::BeginPlay()
{
	Super::BeginPlay();

	//Connecting the Overlap-event from the engine to a function in this object
	Cast<UBoxComponent>(RootComponent)->OnComponentBeginOverlap.AddDynamic(this, &AWinBox::OnOverlap);
}

// Called every frame
void AWinBox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AWinBox::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex,
	bool bFromSweep, const FHitResult& SweepResult)
{

	//	Checks if enemy reaches the player
	if (OtherActor->IsA(APlayerWilliam::StaticClass()))
	{
		Cast<APlayerWilliam>(OtherActor)->Win();
	}
}