// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerWilliam.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"

#include "SoundBall.h"
//
//#include "Camera/CameraComponent.h"
//#include "Camera/CameraActor.h"
//
//#include "GameFramework/SpringArmComponent.h"
//#include "GameFramework/CharacterMovementComponent.h"
//#include "GameFramework/Controller.h"

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

	//CameraBoom->bEnableCameraLag = true;	//just to let the camera lag and not be that fixed at the end of the boom
	//CameraBoom->CameraLagSpeed = 40.f;		//how much lag
	
	// Create a follow camera - the actual camera the game is viewed through
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);	//put it at the end of the boom

	SoundSource = CreateDefaultSubobject<USceneComponent>(TEXT("SoundSource"));
	SoundSource->SetupAttachment(RootComponent);
	SoundSource->SetRelativeLocation(FVector(30.f, 0.f, -90.f));

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
}

// Called every frame
void APlayerWilliam::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime); 
	//AddControllerYawInput(1.0f);
	TimeGone += DeltaTime;
}

// Called to bind functionality to input
void APlayerWilliam::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("Forward", this, &APlayerWilliam::MoveForward);
	PlayerInputComponent->BindAxis("Right", this, &APlayerWilliam::MoveRight);
	PlayerInputComponent->BindAction("Run", IE_Pressed, this, &APlayerWilliam::StartFast);
	PlayerInputComponent->BindAction("Run", IE_Released, this, &APlayerWilliam::StopFast);
}

void APlayerWilliam::MoveForward(float Value)
{
	/*FVector Direction;
	Direction = GetActorForwardVector();
	AddMovementInput(Direction, Value);	*/

	if ((Controller != nullptr) && (Value != 0.0f))
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		Sound();
		AddMovementInput(Direction, Value);
	}
}

void APlayerWilliam::MoveRight(float Value)
{
	/*FVector Direction;
	Direction = GetActorRightVector();
	AddMovementInput(Direction, Value);*/
	if ((Controller != nullptr) && (Value != 0.0f))
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction
		Sound();
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

void APlayerWilliam::Sound()
{
	UWorld* World = GetWorld();

	if (World)	//	check if World is valid
	{
		
		//	If it is time to spawn more enemies and the game has not spawned all enemies yet
		if (TimeGone > TimeBetweenSpawns)
		{
			TimeGone = 0.f;
			//	Spawns bullet at SpawnPoint 
			World->SpawnActor<ASoundBall>(SoundBlueprint, SoundSource->GetComponentLocation(), GetActorRotation());
		}
	}
}