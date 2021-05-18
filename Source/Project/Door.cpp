// Fill out your copyright notice in the Description page of Project Settings.


#include "Door.h"

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
		SetActorEnableCollision(!Rotate_B);
	}
}

void ADoor::Interacted() {
	if (Unlocked) {
		Rotate_B = true;
		Comment = "Yes, It's unlocked";
	}
	else {
		Comment = "Huh, It's locked";
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