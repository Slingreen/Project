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

	Collider->OnComponentBeginOverlap.AddDynamic(this, &ARoomTrigger::OnOverlap);
}

void ARoomTrigger::Enter()
{
	UE_LOG(LogTemp, Warning, TEXT("Walls Down"));
	if (!WallsDown) {
		for (int i = 0; i < WallsLength; i++) {
			WallsArr[i]->WallDown();
		}
	}
	WallsDown = true;
}

void ARoomTrigger::Exit()
{
	UE_LOG(LogTemp, Warning, TEXT("Walls Up"));
	if (WallsDown) {
		for (int i = 0; i < WallsLength; i++) {
			WallsArr[i]->WallUp();
		}
	}
	WallsDown = false;
}

// Called when the game starts or when spawned
void ARoomTrigger::BeginPlay()
{
	Super::BeginPlay();
	WallsLength = WallsArr.Num();
}

// Called every frame
void ARoomTrigger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void ARoomTrigger::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex,
	bool bFromSweep, const FHitResult& SweepResult)
{
		if (OtherActor->IsA(APlayerWilliam::StaticClass()))
		{
			UE_LOG(LogTemp, Warning, TEXT("Enter"));
			Enter();
		}
}