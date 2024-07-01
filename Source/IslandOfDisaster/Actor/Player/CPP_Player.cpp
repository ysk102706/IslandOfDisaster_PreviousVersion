// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_Player.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputAction.h"
#include "Kismet/GameplayStatics.h"
#include "../../UI/PlayerInfoUI.h"

#define PI 3.1415926535
#define Deg2Rad PI / 180
#define GetForwardVector(angle) FVector(FMath::Cos(angle * Deg2Rad), FMath::Sin(angle * Deg2Rad), 0)
#define GetRightVector(angle) FVector(-FMath::Sin(angle * Deg2Rad), FMath::Cos(angle * Deg2Rad), 0)

ACPP_Player::ACPP_Player()
{
 	PrimaryActorTick.bCanEverTick = true;
}

void ACPP_Player::BeginPlay()
{
	Super::BeginPlay();

	if (auto PlayerController = Cast<APlayerController>(GetController())) {
		if (auto SubSystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer())) {
			SubSystem->AddMappingContext(IMC_Default, 0);
		}
	}

	PlayerInfoWidget = CreateWidget<UPlayerInfoUI>(GetWorld(), PlayerInfoUI);
	PlayerInfoWidget->AddToViewport();
}

void ACPP_Player::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACPP_Player::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	auto EIC = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	if (EIC) {
		EIC->BindAction(IA_Move, ETriggerEvent::Triggered, this, &ACPP_Player::Move);
		EIC->BindAction(IA_Camera, ETriggerEvent::Triggered, this, &ACPP_Player::Camera);
	}
}

void ACPP_Player::Move(const FInputActionValue& Value)
{
	FVector f_dir = GetForwardVector(GetControlRotation().Yaw);
	FVector r_dir = GetRightVector(GetControlRotation().Yaw);
	AddMovementInput(f_dir, Value.Get<FVector2D>().X);
	AddMovementInput(r_dir, Value.Get<FVector2D>().Y);
}

void ACPP_Player::Camera(const FInputActionValue& Value)
{
	AddControllerYawInput(Value.Get<FVector2D>().X);
	AddControllerPitchInput(Value.Get<FVector2D>().Y);
}