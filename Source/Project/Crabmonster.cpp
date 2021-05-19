// Fill out your copyright notice in the Description page of Project Settings.


#include "Crabmonster.h"
#include "AICrabController.h"
#include "Perception/PawnSensingComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "Components/BoxComponent.h"
#include "PlayerWilliam.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "AICrabPoint.h"
#include "Math/Vector.h"


// Sets default values
ACrabmonster::ACrabmonster()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	Sensing = CreateDefaultSubobject<UPawnSensingComponent>(TEXT("Sensing"));
	Sensing->SetPeripheralVisionAngle(70.f);

}

// Called when the game starts or when spawned
void ACrabmonster::BeginPlay()
{
	Super::BeginPlay();

	if (Sensing)
	{
		Sensing->OnSeePawn.AddDynamic(this, &ACrabmonster::OnPlayerCaught);
		GetMesh()->OnComponentBeginOverlap.AddDynamic(this, &ACrabmonster::Overlap);
		GetCharacterMovement()->MaxWalkSpeed = 250;
		//UGameplayStatics::GetAllActorsOfClass(GetWorld(), AAICrabPoint::StaticClass(), AllPatrolKeys);
	}
	
}

// Called every frame
void ACrabmonster::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AAICrabController* AICon = Cast<AAICrabController>(GetController());

	if (PlayerVisible)
	{

		if (CurrentTimer >= VisibleTimer)
		{
			PlayerVisible = false;

			//AICon->PlayerVisible = false;
			AICon->SetPlayerCaught(nullptr);
			//AICon->BlackboardCrab->SetValueAsObject(AICon->PlayerKey, AICon->GetPawn());
			CurrentTimer = 0.f;
			GetCharacterMovement()->MaxWalkSpeed = 250;

		}
		CurrentTimer += DeltaTime;

	}

}

// Called to bind functionality to input
void ACrabmonster::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ACrabmonster::OnPlayerCaught(APawn* APawn)
{
	AAICrabController* AIController = Cast<AAICrabController>(GetController());
	if (AIController)
	{
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("I See You!"));
		GetCharacterMovement()->MaxWalkSpeed = 600;
		AIController->SetPlayerCaught(APawn);
		//AIController->PlayerVisible = true;
		//CurrentTimer = 0.f;
		PlayerVisible = true;
		CurrentTimer = 0.f;
	}
}


void ACrabmonster::MeleeAttack()
{

	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("PlayerCollision!"));
	AmIAttacking = true;

}

void ACrabmonster::AttackEnd()
{
	AmIAttacking = false;
	
}

void ACrabmonster::AttackKill()
{
}

void ACrabmonster::AttackBottom()
{
	TArray<AActor*> TargetsHit;
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("PlayerCollision!"));
	GetOverlappingActors(TargetsHit,APlayerWilliam::StaticClass());
	//if (TargetsHit.Num() > 0)
	//{
		
	APlayerController* PlayerController = Cast<APlayerController>(GEngine->GetFirstLocalPlayerController(GetWorld()));
	APlayerWilliam* Player = Cast<APlayerWilliam>(PlayerController->GetCharacter());
	FVector PlayerLoc = Player->GetActorLocation();
	float Distance = GetDistanceTo(Player);
	if (Distance < 100.f)
	{
		Player->death();
	}
	//Player->death();
	AmIAttacking = false;
	//}
}

void ACrabmonster::DisableOverlap()
{
}

void ACrabmonster::Overlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweeb, const FHitResult& SweepResult)
{

	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("DetectedCollision"));
	if (OtherActor->IsA(APlayerWilliam::StaticClass())) 
	{
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("PlayerCollision!"));
		APlayerController* PlayerController = Cast<APlayerController>(GEngine->GetFirstLocalPlayerController(GetWorld()));
		APlayerWilliam* Player = Cast<APlayerWilliam>(PlayerController->GetCharacter());
		Player->death();
		
		
	}
}


