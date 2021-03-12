// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerWilliam.h"

#include "Camera/CameraComponent.h"
#include "Camera/CameraActor.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
APlayerWilliam::APlayerWilliam()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//*

	// Create a camera boom - the placement/position of the 
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 500.f;	//the distance from the camera down to the player
	CameraBoom->SetRelativeRotation(FRotator(-40.f, 0.f, 0.f)); //X = pitch = angle down on player, Y = yaw = angle around the player

	CameraBoom->bInheritYaw = false;				// Ignore Yaw rotations - since we want a fixed camera
	CameraBoom->bDoCollisionTest = false;			// Should not zoom closer to player when colliding  - since we want a fixed camera

	//CameraBoom->bEnableCameraLag = true;	//just to let the camera lag and not be that fixed at the end of the boom
	//CameraBoom->CameraLagSpeed = 40.f;		//how much lag


	// Create a follow camera - the actual camera the game is viewed through
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);	//put it at the end of the boom

	//*/
}

// Called when the game starts or when spawned
void APlayerWilliam::BeginPlay()
{
	Super::BeginPlay();
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
}

void APlayerWilliam::MoveForward(float Value)
{
	FVector Direction;
	Direction = GetActorForwardVector();
	AddMovementInput(Direction, Value);
}

void APlayerWilliam::MoveRight(float Value)
{
	FVector Direction;
	Direction = GetActorRightVector();
	AddMovementInput(Direction, Value);
}

