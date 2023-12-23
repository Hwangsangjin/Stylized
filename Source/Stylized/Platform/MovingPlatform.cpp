// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

AMovingPlatform::AMovingPlatform()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();
}

void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Move(DeltaTime);
}

void AMovingPlatform::Move(float DeltaTime)
{
	if (ShouldReturn())
	{
		FVector Direction = MoveVelocity.GetSafeNormal();
		StartLocation = StartLocation + Direction * MoveDistance;
		SetActorLocation(StartLocation);
		MoveVelocity = -MoveVelocity;
	}
	else
	{
		FVector CurrentLocation = GetActorLocation();
		CurrentLocation += MoveVelocity * DeltaTime;
		SetActorLocation(CurrentLocation);
	}
}

bool AMovingPlatform::ShouldReturn() const
{
	return GetMovedDistance() > MoveDistance;
}

float AMovingPlatform::GetMovedDistance() const
{
	return FVector::Dist(StartLocation, GetActorLocation());
}
