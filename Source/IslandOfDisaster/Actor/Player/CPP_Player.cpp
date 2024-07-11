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

ACPP_Player::ACPP_Player()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ACPP_Player::BeginPlay()
{
	Super::BeginPlay();

	UManagers::Get(GetWorld())->SetPlayer(this);
	Inventory = NewObject<AInventory>();

	Inventory->SetWorld(GetWorld());
	Inventory->SetNoneItemTexture(NoneItemTexture);
	Inventory->SelectItem(0);

	PlayerCamera = FindComponentByClass<UCameraComponent>();

	if (auto PlayerController = Cast<APlayerController>(GetController())) {
		if (auto SubSystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer())) {
			SubSystem->AddMappingContext(IMC_Default, 0);
		}
	}

	Cast<UManagers>(GetGameInstance())->UI()->ShowWidget(EWidgetType::PlayerInfo);

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
		EIC->BindAction(IA_Pick, ETriggerEvent::Triggered, this, &ACPP_Player::PickItem);
		EIC->BindAction(IA_Drop, ETriggerEvent::Triggered, this, &ACPP_Player::DropItem);
		EIC->BindAction(IA_SelectItem, ETriggerEvent::Triggered, this, &ACPP_Player::SelectItem);
	}
}

void ACPP_Player::Move(const FInputActionValue& Value)
{
	FVector f_dir = GetForwardVector();
	FVector r_dir = GetForwardVector().Cross(FVector(0, 0, -1));
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
	if (FocusedItem) FocusedItem->Picked();
}

void ACPP_Player::DropItem(const FInputActionValue& Value)
{
	Inventory->DropItem();
}

void ACPP_Player::SelectItem(const FInputActionValue& Value)
{
	Inventory->SelectItem(Value.Get<float>());
}

void ACPP_Player::ItemCheckRayCast()
{
	FHitResult Hit;

	FVector Forward = GetForwardVector();
	FVector Start = PlayerCamera->GetComponentLocation();
	FVector End = Start + Forward * RayLength;

	FCollisionQueryParams CQP;
	CQP.AddIgnoredActor(this->GetOwner());

	//DrawDebugLine(GetWorld(), Start, End, FColor::Green, false, 0.5f, 0, 1);

	if (GetWorld()->LineTraceSingleByChannel(Hit, Start, End, ECC_Visibility, CQP)) {
		auto actor = Hit.GetActor();
		auto Item = Cast<AItem>(Hit.GetActor());
		if (Item) Item->Focused();
		if (FocusedItem && FocusedItem != Item) FocusedItem->NotFocused();
		FocusedItem = Item;
	}
	else if (FocusedItem) FocusedItem->NotFocused();
}

FVector ACPP_Player::GetForwardVector()
{
	return PlayerCamera->GetForwardVector();
}

TObjectPtr<UTexture2D> ACPP_Player::GetSelectedItemBG()
{
	return SelectedItemBGTexture;
}

TObjectPtr<UTexture2D> ACPP_Player::GetNotSelectedItemBG()
{
	return NotSelectedItemBGTexture;
}
