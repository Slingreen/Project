// Fill out your copyright notice in the Description page of Project Settings.


#include "ClosetObject.h"
#include "Kismet/GameplayStatics.h"	

#include "PlayerWilliam.h"

void AClosetObject::BeginPlay() 
{
	HideSpot = this->GetActorLocation();
	HideSpot += this->GetActorForwardVector() * 40;
	HideSpot.Z = 90.f;
}

void AClosetObject::Interacted() 
{
	UE_LOG(LogTemp, Error, TEXT("Vector %s"), *HideSpot.ToString());
	Cast<APlayerWilliam>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0))->Hiding(HideSpot);
}
