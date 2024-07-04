// Fill out your copyright notice in the Description page of Project Settings.


#include "UIManager.h"
#include "../UI/PlayerInfoUI.h"

#define CreateOrSetWidget(Object, Type) \
	if (!Type##Object) Type##Object = CreateWidget<U##Type##UI>(GetWorld(), Type##Widget); \
	Object = Type##Object; \

UUserWidget* UUIManager::GetWidget(WidgetType Type) {
	UUserWidget* Object = nullptr;

	switch (Type) {
	case WidgetType::PlayerInfo:
		CreateOrSetWidget(Object, PlayerInfo);
		break;
	}

	return Object;
}

void UUIManager::ShowWidget(WidgetType Type)
{
	UUserWidget* Object = GetWidget(Type);
	if (Object) Object->AddToViewport();
}

void UUIManager::HideWidget(WidgetType Type)
{
	UUserWidget* Object = GetWidget(Type);
	if (Object) Object->RemoveFromViewport();
}
