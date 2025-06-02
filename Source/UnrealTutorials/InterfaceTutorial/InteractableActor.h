// Copyright 2025, Bit Gaming Studio. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InteractInterface.h"
#include "InteractableActor.generated.h"

UCLASS()
class UNREALTUTORIALS_API AInteractableActor : public AActor, public IInteractInterface
{
	GENERATED_BODY()
	
public:
	virtual void Interact_Implementation(AActor* Caller) override;
};
