// Copyright 2025, Bit Gaming Studio. All Rights Reserved.

#include "InteractableActor.h"

void AInteractableActor::Interact_Implementation(AActor* Caller)
{
	UE_LOG(LogTemp, Warning, TEXT("%s interacted with %s"), *Caller->GetName(), *GetName());
}
