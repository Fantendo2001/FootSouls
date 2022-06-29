// Fill out your copyright notice in the Description page of Project Settings.


#include "cppTest.h"
const APlayerController* PlayerController;
const FVector ForwardVector;
// Sets default values
AcppTest::AcppTest()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AcppTest::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AcppTest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	// print log to unreal console
	GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Red, FString::Printf(TEXT("Hello World")));
	//////////////////////////////////////////////////////////////////////////
	// get the first person camera
	const APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
	// Get the direction of the camera
	const FVector ForwardVector = PlayerController->GetControlRotation().Vector();
	// log forward vector in unreal console
	UE_LOG(LogTemp, Warning, TEXT("ForwardVector: %s"), *ForwardVector.ToString());
	// get the location of the camera
	const FVector Location = PlayerController->GetPawn()->GetActorLocation();
	// log location in unreal console
	UE_LOG(LogTemp, Warning, TEXT("Location: %s"), *Location.ToString());
	//////////////////////////////////////////////////////////////////////////
}
