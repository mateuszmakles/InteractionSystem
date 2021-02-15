// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractableLight.h"

AInteractableLight::AInteractableLight()
{
	On = true;
	Intensity = 100000.f;
	Light = CreateDefaultSubobject<USpotLightComponent>(TEXT("Light"));
	Light->SetupAttachment(GetRootComponent());
}

void AInteractableLight::BeginPlay()
{
	Super::BeginPlay();

	Light->SetIntensity(Intensity);
}

void AInteractableLight::Interact()
{
	if (On)
	{
		Light->SetIntensity(0);
	}
	else
	{
		Light->SetIntensity(Intensity);
	}

	On = !On;

	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("Interacted"));
}