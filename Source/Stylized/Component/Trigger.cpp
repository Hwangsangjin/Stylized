// Fill out your copyright notice in the Description page of Project Settings.


#include "Component/Trigger.h"
#include "Component/Mover.h"

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
		UPrimitiveComponent* Component = Cast<UPrimitiveComponent>(Actor->GetRootComponent());
		if (Component)
		{
			Component->SetSimulatePhysics(false);
		}

		Actor->AttachToComponent(this, FAttachmentTransformRules::KeepWorldTransform);
		Mover->SetShouldMove(true);
	}
	else
	{
		Mover->SetShouldMove(false);
	}
}

void UTrigger::SetMover(UMover* NewMover)
{
	Mover = NewMover;
}

AActor* UTrigger::GetAcceptableActor() const
{
	TArray<AActor*> Actors;
	GetOverlappingActors(Actors);

	for (const auto& Actor : Actors)
	{
		bool bHasAcceptableTag = Actor->ActorHasTag(AcceptableActorTag);
		bool bIsGrabbed = Actor->ActorHasTag("Grabbed");
		if (bHasAcceptableTag && !bIsGrabbed)
		{
			return Actor;
		}
	}

	return nullptr;
}
