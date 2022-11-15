#include "MGMainTitlePlayer.h"

AMGMainTitlePlayer::AMGMainTitlePlayer()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AMGMainTitlePlayer::BeginPlay()
{
	Super::BeginPlay();
}

void AMGMainTitlePlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AMGMainTitlePlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}