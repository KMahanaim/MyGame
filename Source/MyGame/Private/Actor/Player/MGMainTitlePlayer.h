// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <GameFramework/Pawn.h>
#include "MGMainTitlePlayer.generated.h"

UCLASS()
class AMGMainTitlePlayer : public APawn
{
	GENERATED_BODY()

public:
	AMGMainTitlePlayer();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
