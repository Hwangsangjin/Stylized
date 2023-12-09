// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Platform/BasePlatform.h"
#include "RotatingPlatform.generated.h"

/**
 * 
 */
UCLASS()
class STYLIZED_API ARotatingPlatform : public ABasePlatform
{
	GENERATED_BODY()
	
public:
	ARotatingPlatform();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

private:
	void Rotate(float DeltaTime);

	UPROPERTY(EditAnywhere, Category = "Rotate")
	FRotator RotateVelocity;
};
