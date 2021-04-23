// Fill out your copyright notice in the Description page of Project Settings.


#include "Sentry.h"
#include "AISentryController.h"
#include "Perception/PawnSensingComponent.h"
#include "BehaviorTree/BehaviorTree.h"

//#include "Perception/PawnSensingComponent.h"

// Sets default values
ASentry::ASentry()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	PawnSensing = CreateDefaultSubobject<UPawnSensingComponent>(TEXT("PawnSensing"));

<<<<<<< Updated upstream
	PawnSensing->SetPeripheralVisionAngle(20.f);
=======
	PawnSensing->SetPeripheralVisionAngle(80.f);
	PawnSensing->SightRadius = 1000.f;

	Capsule = CreateDefaultSubobject<USceneComponent>(TEXT("Capsule"));
	Capsule->SetupAttachment(RootComponent);
	Capsule->SetRelativeLocation(FVector(0.f, 0.f, 0.f));
	EyeMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("EyeMesh"));
	EyeMesh->SetupAttachment(RootComponent);
	
	//EyeMesh->SetupAttachment(RootComponent);
	
	//Capsule = GetCapsuleComponent();
	//RootComponent = Capsule;
	//GetCapsuleComponent()->USceneComponent::AttachTo(RootComponent);
	//Sphere->SetupAttachment(RootComponent);
	//Capsule->SetupAttachment(RootComponent);
	
	
>>>>>>> Stashed changes
}

bool ASentry::RotateSentry()
{

	//Sentry->SetActorRotation(0.f, SentryYaw + SentryIdleSpeed, 0.f);
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("I'm Rotating :)"));
	NewRotation.Yaw += SentryIdleSpeed;
	SetActorRotation(NewRotation);
	return true;

}

// Called when the game starts or when spawned
void ASentry::BeginPlay()
{
	Super::BeginPlay();

	if (PawnSensing)
	{
		PawnSensing->OnSeePawn.AddDynamic(this, &ASentry::OnPlayerCaught);
	}

	
}

// Called every frame
void ASentry::Tick(float DeltaTime)
{
	AAISentryController* AIController = Cast<AAISentryController>(GetController());
	Super::Tick(DeltaTime);

	if (PlayerVisible)
	{

		if (CurrentTimer >= VisibleTimer)
		{

			PlayerVisible = false;
			
			AIController->PlayerVisible = false;
			AIController->SetPlayerCaught(nullptr); 
			CurrentTimer = 0.f;

		}
		CurrentTimer += DeltaTime;

	}

	//RotateSentry();




}




// Called to bind functionality to input
void ASentry::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

<<<<<<< Updated upstream
=======
void ASentry::Shoot()
{
	//UCapsuleComponent* Capsule = GetCapsuleComponent();
	UWorld* World = GetWorld();
	if (World)
	{

		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("BAM!"));
		//FRotator Rotation = GetActorRotation();
		//Location = GetActorLocation();
		//Location.Z += 100;
		
		World->SpawnActor<ASentryProjectile>(ProjectileBlueprint, GetActorLocation() + Offset, GetActorRotation());
		ShootCooldownTimer = 0.f;

		
																											  
	}

}

void ASentry::Death()
{
}

>>>>>>> Stashed changes
void ASentry::OnPlayerCaught(APawn* APawn)
{


	AAISentryController* AIController = Cast<AAISentryController>(GetController());
	if (AIController)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("I See You!"));
		AIController->SetPlayerCaught(APawn);
		AIController->PlayerVisible = true;
		CurrentTimer = 0.f;
		PlayerVisible = true;
	}

}




