// Fill out your copyright notice in the Description page of Project Settings.


#include "Sentry.h"
#include "Perception/PawnSensingComponent.h"

// Sets default values
ASentry::ASentry()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Used this page to figure out how UPawnSensingComponent works: https://forums.unrealengine.com/development-discussion/c-gameplay-programming/19571-mini-tutorial-using-upawnsensingcomponent-in-c
	Sensing = CreateDefaultSubobject<UPawnSensingComponent>(TEXT("Sensing"));
	Sensing->bEnableSensingUpdates=true;
	Sensing->bOnlySensePlayers = true;
	//these are temporary values, change in gametesting
	Sensing->SensingInterval = .25f;
	Sensing->SetPeripheralVisionAngle(10.f);
	Sensing->SightRadius = 1000.f;
	Sensing->HearingThreshold = 500.f;
	Sensing->LOSHearingThreshold = 1500.f;



}

// Called when the game starts or when spawned
void ASentry::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASentry::OnSeePlayer(ACharacter* player)
{
}

// Called every frame
void ASentry::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FRotator CurrentRotation = GetActorRotation();
	CurrentRotation.Yaw += RotationSpeed * DeltaTime;
	SetActorRotation(CurrentRotation);

}

// Called to bind functionality to input
void ASentry::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

