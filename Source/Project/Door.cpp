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
	}
}

void ADoor::Interacted() {
	Rotate_B = true;
}

void ADoor::Rotate() {
	if (Current_Degree >= Max_Degrees && Open == false) {
		Open = true;
		Rotate_B = false;
		return;
	}
	else if (Current_Degree <= Min_Degree && Open == true) {
		Open = false;
		Rotate_B = false;
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