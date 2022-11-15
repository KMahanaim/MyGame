// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <GameFramework/PlayerController.h>
#include "MGPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class AMGPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	AMGPlayerController(const FObjectInitializer& ObjectInitializer);
};
