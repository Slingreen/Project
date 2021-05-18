// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractionBox.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"	

#include "PlayerWilliam.h"
#include "InteractionObject.h"

// Sets default values
AInteractionBox::AInteractionBox()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootBase = CreateDefaultSubobject<USceneComponent>(TEXT("MyRoot"));
	SetRootComponent(RootBase);

	InteractCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("InteractBox"));
	InteractCollider->InitBoxExtent(FVector(1.f, 1.f, 1.f));
	InteractCollider->SetupAttachment(RootBase);
	InteractCollider->SetGenerateOverlapEvents(false);

	InteractCollider->OnComponentBeginOverlap.AddDynamic(this, &AInteractionBox::OnOverlap);

	
	
}

// Called when the game starts or when spawned
void AInteractionBox::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AInteractionBox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void AInteractionBox::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex,
	bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("Overlap Detected: %s"), *OtherActor->GetName())

		if (OtherActor->IsA(AInteractionObject::StaticClass()))
		{
			UE_LOG(LogTemp, Warning, TEXT("Interacting true!"));
			Cast<AInteractionObject>(OtherActor)->Interacted();
			thought = Cast<AInteractionObject>(OtherActor)->Comment;
			bThought = true;
			//	This works to teleport now
			//Cast<APlayerWilliam>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0))->Hiding(FVector(1000.f, 1000.f, 1000.f));
		}

} 