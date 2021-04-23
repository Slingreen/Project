// Fill out your copyright notice in the Description page of Project Settings.


#include "Door.h"
#include "Components/BoxComponent.h"

ADoor::ADoor() {
	Collider->InitBoxExtent(FVector(0.2f, 1.9f, 3.4f));
	Collider->SetRelativeLocation(FVector(0.f, -60.f, 110.f));
}

// Called when the game starts or when spawned
void ADoor::BeginPlay()
{
	Super::BeginPlay();

	FRotator Begining_Rotation = GetActorRotation();
	Min_Degree = Begining_Rotation.Yaw;
	Max_Degrees = Min_Degree + 90;
	Current_Degree = Min_Degree;
}

// Called every frame
void ADoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (Rotate_B) {
		Rotate();
	}
}

void ADoor::Interacted() {
	if (Unlocked) {
		Rotate_B = true;
		SetActorEnableCollision(!Rotate_B);
	}
}

void ADoor::Rotate() {
	if (Current_Degree >= Max_Degrees && Open == false) {
		Open = true;
		Rotate_B = false;
		SetActorEnableCollision(!Rotate_B);
		return;
	}
	else if (Current_Degree <= Min_Degree && Open == true) {
		Open = false;
		Rotate_B = false;
		SetActorEnableCollision(!Rotate_B);
		return;
	}
	if (Open) {
		Current_Degree -= RotSpeed;
	}else {
		Current_Degree += RotSpeed;
	}
	FRotator Rot = GetActorRotation();
	Rot.Yaw = Current_Degree;
	SetActorRotation(Rot);
}