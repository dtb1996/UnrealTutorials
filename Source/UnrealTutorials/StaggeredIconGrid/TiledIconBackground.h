// Copyright 2025, Bit Gaming Studio. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TiledIconBackground.generated.h"

UCLASS(Abstract)
class UNREALTUTORIALS_API UTiledIconBackground : public UUserWidget
{
	GENERATED_BODY()
	
public:
	virtual void NativeConstruct() override;

	virtual void NativeDestruct() override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UI")
	UMaterialInterface* BaseMaterial;

	UPROPERTY(Transient, BlueprintReadOnly, Category = "UI")
	UMaterialInstanceDynamic* DynamicMaterial;

	UPROPERTY(meta = (BindWidget))
	class UImage* BackgroundImage;

private:
	void OnViewportResized(FViewport* Viewport, uint32 Val);

	void UpdateAspectRatio();
};
