// Fill out your copyright notice in the Description page of Project Settings.


#include "Painting.h"

void APainting::BeginPlay()
{
	Super::BeginPlay();

	FVector InitLoc = GetActorLocation();
	Min_Loc = InitLoc.Y;
	Max_Loc = Min_Loc - 160;
	Current_Loc = Min_Loc;
}

// Called every frame
void APainting::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (Move_B) {
		Move();
		SetActorEnableCollision(!Move_B);
	}
}

void APainting::Move()
{
	if (Current_Loc <= Max_Loc) {
		Move_B = false;
		SetActorEnableCollision(!Move_B);
		return;
	}
	Current_Loc -= MoveSpeed;
	FVector Loc = GetActorLocation();
	Loc.Y = Current_Loc;
	SetActorLocation(Loc);
}

void APainting::Interacted() {
	UE_LOG(LogTemp, Warning, TEXT("Hello"));
	//if (Open == false) {
		if (Unlocked == false) {
			Comment = "This painting always creeped me out, the eyes seems too follow you.";
			Unlocked = true;
			UE_LOG(LogTemp, Warning, TEXT("Can now open"));
		}
		else {
			Comment = "Aha, a secret passage to my sisters room. That Bitch";
			Move_B = true;
		}
	//}
}