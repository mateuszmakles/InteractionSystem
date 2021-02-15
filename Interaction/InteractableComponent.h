// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "InteractionComponent.h"
#include "InteractableComponent.generated.h"

class USphereComponent;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class INTERACTION_API UInteractableComponent : public USceneComponent
{
	GENERATED_BODY()

private:	
	// Sets default values for this component's properties
	UInteractableComponent();

	int32 Priority;
	int32 PriorityRangeMIN = 1;
	int32 PriorityRangeMAX = 100;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	int32 GetPriority() const { return Priority; }

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Interaction")
	USphereComponent* SphereComponent;

	UFUNCTION(BlueprintCallable, Category = "Interaction")
	virtual void Interact(UInteractionComponent* PIC); // override;

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

};
