// Fill out your copyright notice in the Description page of Project Settings.


#include "TestActor.h"
#include "InteractableComponent.h"

// Sets default values
ATestActor::ATestActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Creating our component for interactions
	InteractableComponent = CreateDefaultSubobject<UInteractableComponent>(FName("Interactable Component"));
}

// Called when the game starts or when spawned
void ATestActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

