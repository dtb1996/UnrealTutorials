// Copyright 2025, Bit Gaming Studio. All Rights Reserved.

#include "TiledIconBackground.h"
#include "Components/Image.h"

void UTiledIconBackground::NativeConstruct()
{
    Super::NativeConstruct();

    if (BaseMaterial && BackgroundImage)
    {
        DynamicMaterial = UMaterialInstanceDynamic::Create(BaseMaterial, this);
        BackgroundImage->SetBrushFromMaterial(DynamicMaterial);
    }

    if (GEngine && GEngine->GameViewport)
    {
        GEngine->GameViewport->Viewport->ViewportResizedEvent.AddUObject(this, &UTiledIconBackground::OnViewportResized);
    }

    UpdateAspectRatio();
}

void UTiledIconBackground::NativeDestruct()
{
    if (GEngine && GEngine->GameViewport)
    {
        GEngine->GameViewport->Viewport->ViewportResizedEvent.RemoveAll(this);
    }

    Super::NativeDestruct();
}

void UTiledIconBackground::OnViewportResized(FViewport* Viewport, uint32 Val)
{
	UpdateAspectRatio();
}

void UTiledIconBackground::UpdateAspectRatio()
{
    if (!DynamicMaterial || !GEngine || !GEngine->GameViewport)
    {
        return;
    }

    FVector2D ViewportSize;
    GEngine->GameViewport->GetViewportSize(ViewportSize);

    if (ViewportSize.Y > 0)
    {
        float AspectRatio = ViewportSize.X / ViewportSize.Y;
        DynamicMaterial->SetScalarParameterValue(TEXT("AspectRatio"), AspectRatio);
    }
}
