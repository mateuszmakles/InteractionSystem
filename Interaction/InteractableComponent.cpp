// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractableComponent.h"
#include "Components/SphereComponent.h"

// Sets default values for this component's properties
UInteractableComponent::UInteractableComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	SphereComponent = CreateDefaultSubobject<USphereComponent>(FName("InteractionCollision"));

	if (GetOwner())
	{
		SphereComponent->AttachToComponent(GetOwner()->GetRootComponent(), FAttachmentTransformRules::KeepRelativeTransform);
		this->AttachToComponent(GetOwner()->GetRootComponent(), FAttachmentTransformRules::KeepRelativeTransform);
	}
}

void UInteractableComponent::Interact(UInteractionComponent* PIC)
{
	if (PIC)
	{
		// Interact
		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Green, TEXT("Interacted!"));
	}
}


void UInteractableComponent::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && OtherActor != GetOwner() && OtherComp && Cast<APawn>(OtherActor))
	{
		if (UInteractionComponent* PIC = OtherActor->FindComponentByClass<UInteractionComponent>())
		{
			PIC->AddActorToInteract(GetOwner());

			GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Orange, TEXT("InteractableComponent has been entered"));
		}
	}
}

void UInteractableComponent::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor && OtherActor != GetOwner() && OtherComp && Cast<APawn>(OtherActor))
	{
		if (UInteractionComponent* PIC = OtherActor->FindComponentByClass<UInteractionComponent>())
		{
			PIC->RemoveActorToInteract(GetOwner());

			GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red, TEXT("InteractableComponent has been left"));
		}
	}
}

// Called when the game starts
void UInteractableComponent::BeginPlay()
{
	Priority = FMath::RandRange(PriorityRangeMIN, PriorityRangeMAX);

	SetComponentTickEnabled(true);

	SphereComponent->OnComponentBeginOverlap.AddDynamic(this, &UInteractableComponent::OnOverlapBegin);
	SphereComponent->OnComponentEndOverlap.AddDynamic(this, &UInteractableComponent::OnOverlapEnd);

	Super::BeginPlay();

	GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Green, TEXT("InteractableComponent created"));
}


// Called every frame
void UInteractableComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

