// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_Player.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputAction.h"
#include "Kismet/GameplayStatics.h"
#include "../../UI/PlayerInfoUI.h"
#include "../../Manager/Managers.h"
#include "../../Manager/UIManager.h"
#include "CPP_PlayerState.h"
#include "Camera/CameraComponent.h"
#include "DrawDebugHelpers.h"

#define PI 3.1415926535
#define Deg2Rad PI / 180
#define GetForwardVectorInYaw(angle) FVector(FMath::Cos(angle * Deg2Rad), FMath::Sin(angle * Deg2Rad), 0)
#define GetRightVectorInYaw(angle) FVector(-FMath::Sin(angle * Deg2Rad), FMath::Cos(angle * Deg2Rad), 0)

ACPP_Player::ACPP_Player()
{
 	PrimaryActorTick.bCanEverTick = true;
}

void ACPP_Player::BeginPlay()
{
	Super::BeginPlay();

	PlayerCamera = FindComponentByClass<UCameraComponent>();

	if (auto PlayerController = Cast<APlayerController>(GetController())) {
		if (auto SubSystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer())) {
			SubSystem->AddMappingContext(IMC_Default, 0);
		}
	}

	Cast<UManagers>(GetGameInstance())->UI()->ShowWidget(WidgetType::PlayerInfo);
}

void ACPP_Player::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	GetController()->GetPlayerState<ACPP_PlayerState>()->Tick(DeltaTime);

	ItemCheckRayCast();
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
	FVector f_dir = GetForwardVectorInYaw(GetControlRotation().Yaw);
	FVector r_dir = GetRightVectorInYaw(GetControlRotation().Yaw);
	AddMovementInput(f_dir, Value.Get<FVector2D>().X);
	AddMovementInput(r_dir, Value.Get<FVector2D>().Y);
}

void ACPP_Player::Camera(const FInputActionValue& Value)
{
	AddControllerYawInput(Value.Get<FVector2D>().X);
	AddControllerPitchInput(Value.Get<FVector2D>().Y);
}

void ACPP_Player::PickItem(const FInputActionValue& Value)
{
	if (SelectedItem) SelectedItem->Picked();
}

void ACPP_Player::ItemCheckRayCast()
{
	FHitResult Hit;

	FVector Forward = PlayerCamera->GetForwardVector();
	FVector Start = PlayerCamera->GetComponentLocation();
	FVector End = Start + Forward * RayLength;

	FCollisionQueryParams CQP;
	CQP.AddIgnoredActor(this->GetOwner());

	//DrawDebugLine(GetWorld(), Start, End, FColor::Green, false, 0.5f, 0, 1);

	if (GetWorld()->LineTraceSingleByChannel(Hit, Start, End, ECC_Visibility, CQP)) {
		auto Item = Cast<AItem>(Hit.GetActor());
		if (Item) Item->Selected();
		else if (SelectedItem) SelectedItem->NotSelected();
		SelectedItem = Item;
	}
	else if (SelectedItem) SelectedItem->NotSelected();
}
