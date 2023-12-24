// Fill out your copyright notice in the Description page of Project Settings.


#include "Component/Trigger.h"

// Sets default values for this component's properties
UTrigger::UTrigger()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	AcceptableActorTag = FName(TEXT("Unlock"));
}


// Called when the game starts
void UTrigger::BeginPlay()
{
	Super::BeginPlay();

}


// Called every frame
void UTrigger::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	AActor* Actor = GetAcceptableActor();
	if (Actor)
	{
		UE_LOG(LogTemp, Display, TEXT("Unlocking"));
	}
	else
	{
		UE_LOG(LogTemp, Display, TEXT("Relocking"));
	}
}

AActor* UTrigger::GetAcceptableActor() const
{
	TArray<AActor*> Actors;
	GetOverlappingActors(Actors);

	for (const auto& Actor : Actors)
	{
		if (Actor->ActorHasTag(AcceptableActorTag))
		{
			return Actor;
		}
	}

	return nullptr;
}
