// Fill out your copyright notice in the Description page of Project Settings.


#include "KnifeWeapon.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "Sentry.h"

// Sets default values
AKnifeWeapon::AKnifeWeapon()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootBase = CreateDefaultSubobject<USceneComponent>(TEXT("MyRoot"));
	SetRootComponent(RootBase);

	WeaponMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WeaponMesh"));
	WeaponMesh->SetupAttachment(RootBase);

	AttackCollider = CreateDefaultSubobject<USphereComponent>(TEXT("AttackSphere"));
	AttackCollider->InitSphereRadius(10.f);
	AttackCollider->SetGenerateOverlapEvents(false);
	AttackCollider->SetupAttachment(RootBase);

	AttackCollider->OnComponentBeginOverlap.AddDynamic(this, &AKnifeWeapon::OnOverlap);

}


// Called when the game starts or when spawned
void AKnifeWeapon::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AKnifeWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AKnifeWeapon::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, 
	UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, 
	bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("Overlap Detected: %s"), *OtherActor->GetName())
	if (OtherActor->IsA(ASentry::StaticClass()))
	{

		Cast<ASentry>(OtherActor)->Death();

	}
}