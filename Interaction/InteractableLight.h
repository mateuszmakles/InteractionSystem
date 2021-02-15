// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interactable.h"
#include "Components/SpotLightComponent.h"
#include "InteractableLight.generated.h"

/**
 * 
 */
UCLASS()
class INTERACTION_API AInteractableLight : public AInteractable
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

public:
	UPROPERTY()
	bool On;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Intensity;

	UPROPERTY(EditAnywhere)
	USpotLightComponent* Light;

	AInteractableLight();

	virtual void Interact() override;
};
