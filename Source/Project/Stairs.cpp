// Fill out your copyright notice in the Description page of Project Settings.


#include "Stairs.h"
#include "PlayerWilliam.h"
#include "Kismet/GameplayStatics.h"
#include "Components/BoxComponent.h"

// Sets default values
AStairs::AStairs()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Collider
	Col = CreateDefaultSubobject<UBoxComponent>(TEXT("Collider"));
	RootComponent = Col;

	Col->SetGenerateOverlapEvents(true);

	//Mesh
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AStairs::BeginPlay()
{
	Super::BeginPlay();

	Cast<UBoxComponent>(RootComponent)->OnComponentBeginOverlap.AddDynamic(this, &AStairs::ChangeFloorCollision);
}

// Called every frame
void AStairs::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AStairs::ChangeFloorCollision(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweeb, const FHitResult& SweepResult)
{
	//UE_LOG(LogTemp, Warning, TEXT("Level2 loaded"));
	if (OtherActor->IsA(APlayerWilliam::StaticClass())) {
		UGameplayStatics::OpenLevel(GetWorld(), NxtLvl);
	}
}