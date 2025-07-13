// Copyright 2025, Bit Gaming Studio. All Rights Reserved.

#include "ContainerDemoComponent.h"

UContainerDemoComponent::UContainerDemoComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}


void UContainerDemoComponent::BeginPlay()
{
	Super::BeginPlay();

	// Initialize with example data
	AddMessage(TEXT("Welcome!"));
	AddMessage(TEXT("Now starting the tutorial mission!"));

	SetScore(TEXT("Alice"), 100);
	SetScore(TEXT("Bob"), 75);

	CollectQuestTag(TEXT("Tutorial_Started"));
}

void UContainerDemoComponent::AddMessage(const FString& NewMessage)
{
	Messages.Add(NewMessage);
}

void UContainerDemoComponent::SetScore(const FString& Player, int32 Score)
{
	PlayerScores.Add(Player, Score);
}

void UContainerDemoComponent::CollectQuestTag(FName Tag)
{
	if (CollectedQuestTags.Contains(Tag))
	{
		UE_LOG(LogTemp, Warning, TEXT("Already collected quest tag: %s"), *Tag.ToString());
	}
	else
	{
		CollectedQuestTags.Add(Tag);
		UE_LOG(LogTemp, Log, TEXT("Collected quest tag: %s"), *Tag.ToString());
	}
}

void UContainerDemoComponent::PrintAll()
{
	UE_LOG(LogTemp, Log, TEXT("--- Messages ---"));
	for (const FString& Msg : Messages)
	{
		UE_LOG(LogTemp, Log, TEXT("%s"), *Msg);
	}

	UE_LOG(LogTemp, Log, TEXT("--- Scores ---"));
	for (const auto& Pair : PlayerScores)
	{
		UE_LOG(LogTemp, Log, TEXT("%s: %d"), *Pair.Key, Pair.Value);
	}

	UE_LOG(LogTemp, Log, TEXT("--- Collected Tags ---"));
	for (const FName& Tag : CollectedQuestTags)
	{
		UE_LOG(LogTemp, Log, TEXT("%s"), *Tag.ToString());
	}
}
