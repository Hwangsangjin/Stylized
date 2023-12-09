// Fill out your copyright notice in the Description page of Project Settings.


#include "Platform/RotatingPlatform.h"

ARotatingPlatform::ARotatingPlatform()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ARotatingPlatform::BeginPlay()
{
	Super::BeginPlay();
}

void ARotatingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Rotate(DeltaTime);
}

void ARotatingPlatform::Rotate(float DeltaTime)
{
	FRotator CurrentRotation = GetActorRotation();
	AddActorLocalRotation(RotateVelocity * DeltaTime);
}
