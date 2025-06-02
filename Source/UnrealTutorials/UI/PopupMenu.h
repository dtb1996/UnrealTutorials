// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PopupMenu.generated.h"

UCLASS()
class UNREALTUTORIALS_API UPopupMenu : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UButton* TestButton;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UTextBlock* TitleText;

	UFUNCTION()
	void OnTestButtonClicked();

protected:
	virtual void NativeConstruct() override;

	virtual void NativeDestruct() override;
};
