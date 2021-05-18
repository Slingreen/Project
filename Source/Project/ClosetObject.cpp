// Fill out your copyright notice in the Description page of Project Settings.


#include "ClosetObject.h"
#include "Kismet/GameplayStatics.h"	

#include "PlayerWilliam.h"

void AClosetObject::Interacted() {
	Cast<APlayerWilliam>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0))->Hiding(this->GetActorLocation());
}
