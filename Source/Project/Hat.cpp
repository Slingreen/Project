// Fill out your copyright notice in the Description page of Project Settings.


#include "Hat.h"
#include "PlayerWilliam.h"
#include "HatRack.h"

void AHat::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

	if (Movable) {
		FVector Location = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();
		//FVector MyCharacterPosition = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();
		Location.Z = 80.f;
		SetActorLocation(Location);
	}
}

void AHat::Interacted() {
	Movable = true;
	SetActorEnableCollision(!Movable);
}

bool AHat::Placed(FVector Loc) {
	Loc.Z = 190.f;
	SetActorLocation(Loc);
	Movable = false;
	return true;
}