// Fill out your copyright notice in the Description page of Project Settings.


#include "KeyItem.h"

void AKeyItem::Interacted() {
	for (int i = 0; i < ArrLenght; i++) {
		Door[i]->Unlocked = true;
	}
	this->Destroy();
}

// Called when the game starts or when spawned
void AKeyItem::BeginPlay()
{
	Super::BeginPlay();
	ArrLenght = Door.Num();
}