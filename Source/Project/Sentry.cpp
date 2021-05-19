// Fill out your copyright notice in the Description page of Project Settings.


#include "Sentry.h"
#include "AISentryController.h"
#include "Perception/PawnSensingComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "SentryProjectile.h"
#include "Kismet/KismetMathLibrary.h"
#include "Components/BoxComponent.h"
#include "PlayerWilliam.h"
#include "Components/SpotLightComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "PatrolPoint.h"
#include "Kismet/GameplayStatics.h"


//#include "Perception/PawnSensingComponent.h"

// Sets default values
ASentry::ASentry()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	PawnSensing = CreateDefaultSubobject<UPawnSensingComponent>(TEXT("PawnSensing"));

	Spotlight = CreateDefaultSubobject<USpotLightComponent>(TEXT("VisionLight"));
	//SetRootComponent(GetMesh());
	//GetCapsuleComponent
	Spotlight->SetupAttachment(RootComponent);
	//RootComponent = Spotlight;
	//Spotlight->SetWorldLocation(GetActorLocation());

//<<<<<<< Updated upstream
	PawnSensing->SetPeripheralVisionAngle(40.f);
//=======
	//PawnSensing->SetPeripheralVisionAngle(80.f);
	PawnSensing->SightRadius = 1000.f;


}



void ASentry::RotateSentry()
{

	//Sentry->SetActorRotation(0.f, SentryYaw + SentryIdleSpeed, 0.f);
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("I'm Rotating :)"));
	NewRotation.Yaw += SentryIdleSpeed;
	SetActorRotation(NewRotation);
	//Rotation
	//return true;

}

// Called when the game starts or when spawned
void ASentry::BeginPlay()
{
	Super::BeginPlay();

	if (PawnSensing)
	{
		PawnSensing->OnSeePawn.AddDynamic(this, &ASentry::OnPlayerCaught);
	}
	//UGameplayStatics::GetAllActorsOfClass(GetWorld(), APatrolPoint::StaticClass(), AllPatrolKeys);



	
}

// Called every frame
void ASentry::Tick(float DeltaTime)
{
	AAISentryController* AICon = Cast<AAISentryController>(GetController());
	Super::Tick(DeltaTime);
	

	if (PlayerVisible)
	{

		if (CurrentTimer >= VisibleTimer)
		{

			PlayerVisible = false;
			
			AICon->PlayerVisible = false;
			AICon->SetPlayerCaught(nullptr); 
			CurrentTimer = 0.f;
			GetCharacterMovement()->MaxWalkSpeed = 300;

		}
		CurrentTimer += DeltaTime;

	}
	//else if (NeedRotation)
	//{

	//	//FVector Location = GetActorLocation();
	//	//FVector PointLocation = AICon->PatrolKeys[AICon->Index]->GetActorLocation();
	//	if (PatrolKeys.Num()>0)
	//	{
	//		
	//		FRotator StopRot = UKismetMathLibrary::FindLookAtRotation(this->GetActorLocation(), PatrolKeys[Index]->GetActorLocation());
	//		//FRotator StopRot = UKismetMathLibrary::FindLookAtRotation(Location, PointLocation);
	//		FRotator StartRot = GetActorRotation();
	//		//NewRot.Yaw += SentryIdleSpeed;
	//		//SetActorRotation(NewRot);
	//		if (NeedRotationTimer > 2)
	//		{
	//			NeedRotation = false;
	//		}
	//		else if (NeedRotationTimer < 2)
	//		{
	//			FRotator NewRot = UKismetMathLibrary::RInterpTo(StartRot, StopRot, DeltaTime, 2);
	//			NewRot.Roll = 0.f;
	//			NewRot.Pitch = 0.f;
	//			SetActorRotation(NewRot);
	//			NeedRotationTimer += DeltaTime;

	//		}
	//	}
	//	
	//}

}




// Called to bind functionality to input
void ASentry::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);



}

//<<<<<<< Updated upstream
//=======
void ASentry::Shoot()
{

	AmIShooting = true;
	//UCapsuleComponent* Capsule = GetCapsuleComponent();


}

void ASentry::ShootEnd()
{
	AmIShooting = false;
}

void ASentry::ShootSpawn()
{

	UWorld* World = GetWorld();
	if (World)
	{

		World->SpawnActor<ASentryProjectile>(ProjectileBlueprint, GetActorLocation() + Offset, GetActorRotation());
		ShootCooldownTimer = 0.f;
	}
}

void ASentry::Death()
{
	//temporary, until I can fix the animations that github destroyed
	AmIDead = true;
	AAISentryController* AICon = Cast<AAISentryController>(GetController());
	AICon->SetPlayerCaught(nullptr);
	UnPossessed();

	//this->Destroy();
}

void ASentry::DeathEnd()
{
	//AmIDead = false;
	this->UninitializeComponents();
	this->Destroy();

	
}

void ASentry::GradualRotate()
{
	NeedRotation = true;
	NeedRotationTimer = 0;
}

void ASentry::Attack()
{
	AmIAttacking = true;

}

void ASentry::AttackEnd()
{

	AmIAttacking = false;

}

void ASentry::AttackKill()
{
	APlayerController* PlayerController = Cast<APlayerController>(GEngine->GetFirstLocalPlayerController(GetWorld()));
	APlayerWilliam* Player = Cast<APlayerWilliam>(PlayerController->GetCharacter());
	Player->death();
}

//>>>>>>> Stashed changes
void ASentry::OnPlayerCaught(APawn* APawn)
{


	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("I see you"));
	AAISentryController* AIController = Cast<AAISentryController>(GetController());
	GetCharacterMovement()->MaxWalkSpeed = 600;
	if (AIController)
	{
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("I See You!"));
		AIController->SetPlayerCaught(APawn);
		AIController->PlayerVisible = true;
		CurrentTimer = 0.f;
		PlayerVisible = true;
		
	}

}




