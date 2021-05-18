// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractionObject.h"
#include "Components/BoxComponent.h"

// Sets default values
AInteractionObject::AInteractionObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Mesh
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = Mesh;

	//Collider
	Collider = CreateDefaultSubobject<UBoxComponent>(TEXT("Collider"));
	Collider->SetupAttachment(RootComponent);

	Collider->SetGenerateOverlapEvents(true);

	Door_Mesh->SetRenderCustomDepth(true);
}

void AInteractionObject::Interacted()
{

}

// Called when the game starts or when spawned
void AInteractionObject::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AInteractionObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

