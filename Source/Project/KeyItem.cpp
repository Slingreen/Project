// Fill out your copyright notice in the Description page of Project Settings.


#include "KeyItem.h"

void AKeyItem::Interacted() {
	for (int i = 0; i < Door.Max(); i++) {
		Door[i]->Unlocked = true;
	}
	this->Destroy();
}