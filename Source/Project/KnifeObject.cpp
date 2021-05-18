// Fill out your copyright notice in the Description page of Project Settings.


#include "KnifeObject.h"
#include "Kismet/GameplayStatics.h"	

#include "PlayerWilliam.h"

void AKnifeObject::Interacted() {
	Cast<APlayerWilliam>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0))->GetWeapon();
	this->Destroy();
}