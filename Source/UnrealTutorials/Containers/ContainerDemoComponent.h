// Copyright 2025, Bit Gaming Studio. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ContainerDemoComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UNREALTUTORIALS_API UContainerDemoComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UContainerDemoComponent();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Container Demo")
	TArray<FString> Messages;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Container Demo")
	TMap<FString, int32> PlayerScores;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Container Demo")
	TSet<FName> CollectedQuestTags;

public:	
	UFUNCTION(BlueprintCallable, Category = "Container Demo")
	void AddMessage(const FString& NewMessage);

	UFUNCTION(BlueprintCallable, Category = "Container Demo")
	void SetScore(const FString& Player, int32 Score);

	UFUNCTION(BlueprintCallable, Category = "Container Demo")
	void CollectQuestTag(FName Tag);

	UFUNCTION(BlueprintCallable, Category = "Container Demo")
	void PrintAll();
};
