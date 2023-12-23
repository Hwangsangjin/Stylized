// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePlatform.h"
#include "MovingPlatform.generated.h"

/**
 *
 */
UCLASS()
class STYLIZED_API AMovingPlatform : public ABasePlatform
{
	GENERATED_BODY()
	
public:
	AMovingPlatform();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

private:
	void Move(float DeltaTime);
	bool ShouldReturn() const;
	float GetMovedDistance() const;

	FVector StartLocation;

	UPROPERTY(EditAnywhere, Category = "Move")
	FVector MoveVelocity;

	UPROPERTY(EditAnywhere, Category = "Move")
	float MoveDistance;
};
