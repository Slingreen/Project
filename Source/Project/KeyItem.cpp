// Fill out your copyright notice in the Description page of Project Settings.


#include "KeyItem.h"

void AKeyItem::Interacted() {
	Door->Unlocked = true;
	this->Destroy();
}