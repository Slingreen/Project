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

	PawnSensing->SetPeripheralVisionAngle(20.f);
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




