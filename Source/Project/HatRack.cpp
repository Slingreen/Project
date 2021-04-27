// Fill out your copyright notice in the Description page of Project Settings.


#include "HatRack.h"
#include "Door.h"
#include "Hat.h"

void AHatRack::Interacted() {
	FVector Location = GetActorLocation();
	//Hat->Placed(Location);
	Door->Unlocked = Hat->Placed(Location);
}