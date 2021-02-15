// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractionComponent.h"
#include "InteractableComponent.h"

// Sets default values for this component's properties
UInteractionComponent::UInteractionComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UInteractionComponent::SortActors()
{
	ActorsToInteract.Sort([=](const TWeakObjectPtr<UInteractableComponent>& FirstElement, const TWeakObjectPtr<UInteractableComponent>& SecondElement)
		{
			return FirstElement.Get()->GetPriority() > SecondElement.Get()->GetPriority();
		});
}

void UInteractionComponent::InteractWithInteractable()
{
	if (ActorsToInteract.Num() > 0)
	{
		SortActors();

		for (const auto& ActorToInteract : ActorsToInteract)
		{
			ExecuteInteract(ActorToInteract);
			return;
		}
	}
}

void UInteractionComponent::ExecuteInteract(const TWeakObjectPtr<UInteractableComponent>& Actor)
{
	Actor.Get()->Interact(this);
}

void UInteractionComponent::AddActorToInteract(const AActor* Actor)
{
	UInteractableComponent* Component = Actor->FindComponentByClass<UInteractableComponent>();

	ActorsToInteract.Add(Component);
}

void UInteractionComponent::RemoveActorToInteract(const AActor* Actor)
{
	UInteractableComponent* Component = Actor->FindComponentByClass<UInteractableComponent>();

	ActorsToInteract.Remove(Component);
}

// Called when the game starts
void UInteractionComponent::BeginPlay()
{
	Super::BeginPlay();

	GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Green, TEXT("InteractionComponent created"));
	
}


// Called every frame
void UInteractionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

