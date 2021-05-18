// Fill out your copyright notice in the Description page of Project Settings.


#include "Crabmonster.h"
#include "AICrabController.h"
#include "Perception/PawnSensingComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "Components/BoxComponent.h"
#include "PlayerWilliam.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
ACrabmonster::ACrabmonster()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	Sensing = CreateDefaultSubobject<UPawnSensingComponent>(TEXT("Sensing"));
	Sensing->SetPeripheralVisionAngle(70.f);

	//Collider = CreateDefaultSubobject<UBoxComponent>(TEXT("Collider"));
	//Root = CreateDefaultSubobject<UBoxComponent>(TEXT("Collider"));
	//Collider->SetGenerateOverlapEvents(true);
	//SetRootComponent(Root);
//<<<<<<< Updated upstream
	//Collider->AttachTo(RootComponent);
//=======
	//USkeletalMeshComponent* Mesh = GetMesh();
	//GetMesh()->AttachTo(RootComponent);
	//GetCapsuleComponent()->AttachTo(RootComponent);
	//Collider->USceneComponent::AttachTo(RootComponent);
	
//>>>>>>> Stashed changes

}

// Called when the game starts or when spawned
void ACrabmonster::BeginPlay()
{
	Super::BeginPlay();

	if (Sensing)
	{
		Sensing->OnSeePawn.AddDynamic(this, &ACrabmonster::OnPlayerCaught);
		//Cast<UBoxComponent>(Collider)->OnComponentBeginOverlap.AddDynamic(this, &ACrabmonster::Overlap);
		//MeeleeAttack.AddDynamic(this, &ACrabmonster::MeeleeAttack);
		GetMesh()->OnComponentBeginOverlap.AddDynamic(this, &ACrabmonster::Overlap);
		//UCharacterMovementComponent* Moving = GetCharacterMovement();
		//GetCharacterMovement()->MaxWalkSpeed = 600;
		
		
	}
	
}

// Called every frame
void ACrabmonster::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);



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
		AIController->SetPlayerCaught(APawn);
		//AIController->PlayerVisible = true;
		//CurrentTimer = 0.f;
		//PlayerVisible = true;
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
	GetOverlappingActors(TargetsHit,APlayerWilliam::StaticClass());
	if (TargetsHit.Num() > 0)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("PlayerCollision!"));
		APlayerController* PlayerController = Cast<APlayerController>(GEngine->GetFirstLocalPlayerController(GetWorld()));
		APlayerWilliam* Player = Cast<APlayerWilliam>(PlayerController->GetCharacter());
		Player->death();
	}
}

void ACrabmonster::DisableOverlap()
{
}

void ACrabmonster::Overlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweeb, const FHitResult& SweepResult)
{

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("DetectedCollision"));
	if (OtherActor->IsA(APlayerWilliam::StaticClass())) 
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("PlayerCollision!"));
		APlayerController* PlayerController = Cast<APlayerController>(GEngine->GetFirstLocalPlayerController(GetWorld()));
		APlayerWilliam* Player = Cast<APlayerWilliam>(PlayerController->GetCharacter());
		Player->death();
		
		
	}
}


