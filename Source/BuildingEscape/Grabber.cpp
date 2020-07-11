// Fill out your copyright notice in the Description page of Project Settings.

#include "DrawDebugHelpers.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "Grabber.h"

#define OUT

// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("Grabber ready for duty!"));	
}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	//Get Player's viewpiont
	FVector PlayerViewPointLocation;
	FRotator PlayerVeiwPointRotation;

	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
		OUT PlayerViewPointLocation,
		OUT PlayerVeiwPointRotation
	);

	//Logging out to test
	FString PlayerLocation = PlayerViewPointLocation.ToString();
	FString PlayerRotation = PlayerVeiwPointRotation.ToString();

	UE_LOG(LogTemp, Warning, TEXT("Location: %s, Rotation: %s"), *PlayerLocation, *PlayerRotation);

	//Draw a line from player showing reach
	FVector LineTraceEnd = PlayerViewPointLocation + PlayerVeiwPointRotation.Vector() * Reach;

	DrawDebugLine(
		GetWorld(),
		PlayerViewPointLocation,
		LineTraceEnd,
		FColor(0, 255, 0),
		false,
		0.f,
		0,
		5.f
	);

	//Ray Cast out to a certain distance (Reach)
	//See what it hits
}

