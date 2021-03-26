// Fill out your copyright notice in the Description page of Project Settings.


#include "SoundBall.h"
#include "Components/SphereComponent.h"

// Sets default values
ASoundBall::ASoundBall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Collision object and RootObject
	OurCollider = CreateDefaultSubobject<USphereComponent>(TEXT("MyCollider"));
	RootComponent = OurCollider;
	OurCollider->SetGenerateOverlapEvents(true);

	//Attaching the visual mesh
	OurVisibleComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("OurVisibleComponent"));
	OurVisibleComponent->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ASoundBall::BeginPlay()
{
	Super::BeginPlay();

	//Connecting the Overlap-event from the engine to a function in this object
	Cast<USphereComponent>(RootComponent)->OnComponentBeginOverlap.AddDynamic(this, &ASoundBall::OnOverlap);
}

// Called every frame
void ASoundBall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//	Bullet life time
	TimeLived += DeltaTime;
	if (TimeLived > TimeBeforeDestroy)
	{
		this->Destroy();
	}
	else//	Move the bullet 
	{
		FVector NewSize = GetActorScale();
		NewSize *= Speed;
		SetActorScale3D(NewSize);
	}
}

//The function that handles Overlap Events
void ASoundBall::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex,
	bool bFromSweep, const FHitResult& SweepResult)
{

	//if other actor is of a type we are interested in (eg. the enemy)
	/*if (OtherActor->IsA(AEnemy::StaticClass()))
	{
		Cast<AEnemy>(OtherActor)->ImHit();
		Destroy();
	}*/
}