// Fill out your copyright notice in the Description page of Project Settings.


#include "KnifeWeapon.h"

// Sets default values
AKnifeWeapon::AKnifeWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AKnifeWeapon::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AKnifeWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

