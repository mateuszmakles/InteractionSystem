// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "InteractionHUD.generated.h"

UCLASS()
class AInteractionHUD : public AHUD
{
	GENERATED_BODY()

public:
	AInteractionHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};

