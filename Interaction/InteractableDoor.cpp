// Fill out your copyright notice in the Description page of Project Settings.

#include "InteractableDoor.h"
#include "Kismet/KismetMathLibrary.h"

void AInteractableDoor::BeginPlay()
{
	Super::BeginPlay();

	if (CurveFloat)
	{
		DoorTimeline->AddInterpFloat(CurveFloat, InterpFunction, FName("Alpha"));
		DoorTimeline->SetTimelineFinishedFunc(TimelineFinish);
		DoorTimeline->SetLooping(false);
	}
}

AInteractableDoor::AInteractableDoor()
{
	Closed = true;

	DoorTimeline = CreateDefaultSubobject<UTimelineComponent>(TEXT("Timeline"));
	InterpFunction.BindUFunction(this, FName("InterpReturn"));
	TimelineFinish.BindUFunction(this, FName("OnFinish"));
}

void AInteractableDoor::Interact()
{
	if (Closed)
	{
		DoorTimeline->Play();
	}
	else
	{
		DoorTimeline->Reverse();
	}

	Closed = !Closed;

	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("Interacted"));
}

void AInteractableDoor::OnFinish()
{

}

void AInteractableDoor::InterpReturn(float val)
{
	Mesh->SetRelativeRotation(FRotator(0, UKismetMathLibrary::Ease(0, -110, val, EEasingFunc::SinusoidalInOut), 0));
}