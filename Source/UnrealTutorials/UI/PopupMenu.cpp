// Fill out your copyright notice in the Description page of Project Settings.


#include "PopupMenu.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"

void UPopupMenu::OnTestButtonClicked()
{
	if (TitleText)
	{
		TitleText->SetText(FText::FromString(TEXT("Button has been clicked")));
	}
}

void UPopupMenu::NativeConstruct()
{
	if (TestButton)
	{
		TestButton->OnClicked.AddDynamic(this, &UPopupMenu::OnTestButtonClicked);
	}
}

void UPopupMenu::NativeDestruct()
{
	if (TestButton)
	{
		TestButton->OnClicked.RemoveDynamic(this, &UPopupMenu::OnTestButtonClicked);
	}
}
