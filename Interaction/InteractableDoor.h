// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interactable.h"
#include "Components/TimelineComponent.h"
#include "InteractableDoor.generated.h"

/**
 * 
 */
UCLASS()
class INTERACTION_API AInteractableDoor : public AInteractable
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

private:
	bool Closed;

public:
	AInteractableDoor();

	virtual void Interact() override;

	UFUNCTION()
	void OnFinish();

	UFUNCTION()
	void InterpReturn(float val);
	
	FOnTimelineFloat InterpFunction{};
	FOnTimelineEvent TimelineFinish{};

	UPROPERTY()
	UTimelineComponent* DoorTimeline;
	
	UPROPERTY(EditAnywhere)
	UCurveFloat* CurveFloat;
};
