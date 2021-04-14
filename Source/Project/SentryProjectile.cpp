// Fill out your copyright notice in the Description page of Project Settings.


#include "SentryProjectile.h"
#include "Components/SphereComponent.h"
#include "PlayerWilliam.h"

// Sets default values
ASentryProjectile::ASentryProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Collider
	Collider = CreateDefaultSubobject<USphereComponent>(TEXT("MyCollider"));
	RootComponent = Collider;

	Collider->SetGenerateOverlapEvents(true);

	//Mesh
	ProjectileMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ProjectileMesh"));
	ProjectileMesh->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void ASentryProjectile::BeginPlay()
{
	Super::BeginPlay();

	Cast<USphereComponent>(RootComponent)->OnComponentBeginOverlap.AddDynamic(this, &ASentryProjectile::Overlap);
	
}

void ASentryProjectile::Overlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweeb, const FHitResult& SweepResult)
{
	if (OtherActor->IsA(APlayerWilliam::StaticClass()))
	{

		Cast<APlayerWilliam>(OtherActor)->death();

	}
	if (TimeLived > 1.f)
	{
		this->Destroy();
	}
}


// Called every frame
void ASentryProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	TimeLived += DeltaTime;

	if (TimeLived > DestructionTime)
	{
		this->Destroy();

	}

	//Movement

	FVector NewLocation = GetActorLocation();
	NewLocation += GetActorForwardVector() * Speed * DeltaTime;
	SetActorLocation(NewLocation);


}


