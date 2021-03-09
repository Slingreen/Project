// Benjamin A.E. Darici


#include "PlayerControl.h"

// Sets default values
APlayerControl::APlayerControl()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//	Create a dummy root component we can attach things to.
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	OurVisibleComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("OurVisibleComponent"));
	OurVisibleComponent->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void APlayerControl::BeginPlay()
{
	Super::BeginPlay();
	
	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
	//PlayerController->SetViewTarget(StaticCamera);
}

// Called every frame
void APlayerControl::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//If CurrentVelocity == 0 no movement will happen
	FVector NewLocation = GetActorLocation() + (CurrentVelocity * DeltaTime);

	//	Input setup
	PlayerInputComponent->BindAxis("Right", this, &ACannon::MoveRight);
	PlayerInputComponent->BindAction("Shoot", IE_Pressed, this, &ACannon::Shoot);
}

// Called to bind functionality to input
void APlayerControl::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ACannon::MoveRight(float Value)
{
	CurrentVelocity.Y = FMath::Clamp(Value, -1.f, 1.f) * MoveSpeed;
}
