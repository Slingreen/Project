// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerWilliam.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "Camera/CameraComponent.h"

#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/BoxComponent.h"

#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"

#include "KnifeWeapon.h"
#include "InteractionBox.h"

// Sets default values
APlayerWilliam::APlayerWilliam()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//*
	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;

	// Create a camera boom - the placement/position of the 
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 500.f;	//the distance from the camera down to the player
	CameraBoom->SetRelativeRotation(FRotator(-55.f, 0.f, 0.f)); //X = pitch = angle down on player, Y = yaw = angle around the player

	CameraBoom->bInheritYaw = false;				// Ignore Yaw rotations - since we want a fixed camera
	CameraBoom->bDoCollisionTest = false;			// Should not zoom closer to player when colliding  - since we want a fixed camera
	
	// Create a follow camera - the actual camera the game is viewed through
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);	//put it at the end of the boom

	//Using this for run speed. Have to set it to other than default 600 = walkspeed
	GetCharacterMovement()->MaxCustomMovementSpeed = 300.f;
}



// Called when the game starts or when spawned
void APlayerWilliam::BeginPlay()
{
// Setting up movement speeds:
	//	600
	MaxWalkSpeed = GetCharacterMovement()->MaxWalkSpeed;
	//	300
	MaxSneakSpeed = GetCharacterMovement()->MaxCustomMovementSpeed;

	GetCharacterMovement()->MaxWalkSpeed = MaxSneakSpeed;

	Super::BeginPlay();
	TimeGone = 1.f;

	MyInteraction = GetWorld()->SpawnActor<AInteractionBox>(InteractionBox);
	MyInteraction->AttachToComponent(GetMesh(), FAttachmentTransformRules::KeepRelativeTransform, TEXT("InteractSocket"));

	bIsInteracting = false;
}

// Called every frame
void APlayerWilliam::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime); 
}

// Called to bind functionality to input
void APlayerWilliam::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("Forward", this, &APlayerWilliam::MoveForward);
	PlayerInputComponent->BindAxis("Right", this, &APlayerWilliam::MoveRight);
	PlayerInputComponent->BindAction("Run", IE_Pressed, this, &APlayerWilliam::StartFast);
	PlayerInputComponent->BindAction("Run", IE_Released, this, &APlayerWilliam::StopFast);
	PlayerInputComponent->BindAction("Die", IE_Pressed, this, &APlayerWilliam::death);
	PlayerInputComponent->BindAction("Attack", IE_Pressed, this, &APlayerWilliam::StartAttack);
	PlayerInputComponent->BindAction("Attack", IE_Released, this, &APlayerWilliam::StopAttack);
	PlayerInputComponent->BindAction("Interact", IE_Pressed, this, &APlayerWilliam::StartInteract);
	PlayerInputComponent->BindAction("Interact", IE_Released, this, &APlayerWilliam::StopInteract);
}

void APlayerWilliam::MoveForward(float Value)
{
	if ((Controller != nullptr) && (Value != 0.0f) && !bAmIDead && !bIsInteracting)
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void APlayerWilliam::MoveRight(float Value)
{
	if ((Controller != nullptr) && (Value != 0.0f) && !bAmIDead && !bIsInteracting)
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(Direction, Value);
	}
}

void APlayerWilliam::StartFast()
{
	GetCharacterMovement()->MaxWalkSpeed = MaxWalkSpeed;
}

void APlayerWilliam::StopFast()
{
	GetCharacterMovement()->MaxWalkSpeed = MaxSneakSpeed;
}

void APlayerWilliam::StartAttack()
{
	if (bWeapon)
	{
		UE_LOG(LogTemp, Warning, TEXT("start attack called!"));
		bIsAttacking = true;
	}
}

void APlayerWilliam::StopAttack()
{
	UE_LOG(LogTemp, Warning, TEXT("stop attack called!"));
	bAttackFinished = true;
}

void APlayerWilliam::AttackFinished()
{
	if (!bAttackFinished)
	{
		StartAttack();
	}
	else
	{
		bAttackFinished = false;
		bIsAttacking = false;
		UE_LOG(LogTemp, Warning, TEXT("Attack finished"));
	}
}

void APlayerWilliam::StartInteract()
{
	UE_LOG(LogTemp, Warning, TEXT("fiddle!"));
	bIsInteracting = true;
	if (bIsInteracting)
	{
		UE_LOG(LogTemp, Warning, TEXT("bIsInteracting"));
	}
}

void APlayerWilliam::StopInteract()
{
	UE_LOG(LogTemp, Warning, TEXT("diddle!"));
	bInteractFinished = true;
}

void APlayerWilliam::InteractFinished()
{
	if (!bInteractFinished)
	{
		StartAttack();
	}
	else
	{
		bInteractFinished = false;
		bIsInteracting = false;
		UE_LOG(LogTemp, Warning, TEXT("Interact finished"));
	}
}

void APlayerWilliam::death()
{
	//GetWeapon();
	//Hiding(FVector(140.f, -528.f, 0.f));
	//bAmIDead = true;
}

void APlayerWilliam::Win()
{
	bWin = true;
}

void APlayerWilliam::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex,
	bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("Overlap Detected: %s"), *OtherActor->GetName())
}


void APlayerWilliam::Hiding(FVector p)
{
	UE_LOG(LogTemp, Warning, TEXT("Hiding test"));
	if (bHide)
	{
		bHide = false;
		SetActorLocation(preHide);
	}
	else
	{
		bHide = true;
		preHide = GetActorLocation();
		SetActorLocation(p);
	}
}

void APlayerWilliam::GetWeapon()
{
	MyWeapon = GetWorld()->SpawnActor<AKnifeWeapon>(WeaponType);
	MyWeapon->AttachToComponent(GetMesh(), FAttachmentTransformRules::KeepRelativeTransform, TEXT("R_handSocket"));
	bWeapon = true;
}

