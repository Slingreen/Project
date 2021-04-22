// Fill out your copyright notice in the Description page of Project Settings.


#include "Door.h"
<<<<<<< Updated upstream
=======
#include "Components/BoxComponent.h"
#include "PlayerWilliam.h"
#include "Misc/App.h"
>>>>>>> Stashed changes

// Sets default values
ADoor::ADoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

<<<<<<< Updated upstream
	Collider = CreateDefaultSubobject<UBoxComponent>(TEXT("DoorCollider"));
	RootComponent = Collider;
=======
	//Mesh
	Door_Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Door_Mesh"));
	RootComponent = Door_Mesh;

	//Collider
	Collider = CreateDefaultSubobject<UBoxComponent>(TEXT("MyCollider"));
	Collider->SetupAttachment(RootComponent);
>>>>>>> Stashed changes

	Collider->SetGenerateOverlapEvents(true);

}

// Called when the game starts or when spawned
void ADoor::BeginPlay()
{
	Super::BeginPlay();
<<<<<<< Updated upstream
=======

	Cast<UBoxComponent>(Collider)->OnComponentBeginOverlap.AddDynamic(this, &ADoor::Collision);
>>>>>>> Stashed changes
	
}

// Called every frame
void ADoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
<<<<<<< Updated upstream

=======
	if (Open == true) {
		Rotate();
	}
}

void ADoor::Collision(UPrimitiveComponent* OverlappedComponent, AActor* Colliding_obj, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweeb, const FHitResult& SweepResult) {
	if (Colliding_obj->IsA(APlayerWilliam::StaticClass())) {
		Open = true;
	}
}

void ADoor::Rotate() {
	if (Current_Degree >= Max_Degrees) {
		Open = false;
		return;
	}
	Current_Degree++;

	FRotator Rotation = this->GetActorRotation();
	Rotation.Yaw += Current_Degree;
	SetActorRotation(Rotation);
>>>>>>> Stashed changes
}

