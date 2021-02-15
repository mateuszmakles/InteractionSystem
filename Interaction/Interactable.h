// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
//#include "Components/SceneComponent.h"
#include "Interactable.generated.h"

UCLASS()
class INTERACTION_API AInteractable : public AActor
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	AInteractable();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	USceneComponent* _RootComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* Mesh;

	virtual void Interact() PURE_VIRTUAL(AInteractable::Interact, );
};
