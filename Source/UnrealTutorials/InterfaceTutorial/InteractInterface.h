// Copyright 2025, Bit Gaming Studio. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "InteractInterface.generated.h"

UINTERFACE(MinimalAPI, Blueprintable)
class UInteractInterface : public UInterface
{
	GENERATED_BODY()
};

class IInteractInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interaction")
	void Interact(AActor* Caller);
};