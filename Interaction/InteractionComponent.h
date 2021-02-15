// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InteractionComponent.generated.h"

class UInteractableComponent;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class INTERACTION_API UInteractionComponent final : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInteractionComponent();

private:
	// Called when the game starts
	virtual void BeginPlay() override;

	TArray<TWeakObjectPtr<UInteractableComponent>> ActorsToInteract;

	void SortActors();

	void ExecuteInteract(const TWeakObjectPtr<UInteractableComponent>& Actor);

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Category = "Interaction")
	void InteractWithInteractable();

	UFUNCTION(BlueprintCallable, Category = "Interaction")
	void AddActorToInteract(const AActor* Actor);

	UFUNCTION(BlueprintCallable, Category = "Interaction")
	void RemoveActorToInteract(const AActor* Actor);
};
