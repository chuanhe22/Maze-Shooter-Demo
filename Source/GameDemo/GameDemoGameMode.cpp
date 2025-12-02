// Copyright Epic Games, Inc. All Rights Reserved.

#include "GameDemoGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "GameDemoCharacter.h"
#include "EnemyAI.h"

AGameDemoGameMode::AGameDemoGameMode()
{
	// stub
}

void AGameDemoGameMode::BeginPlay()
{
	Super::BeginPlay();

	AGameDemoCharacter* Player = Cast<AGameDemoCharacter>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));

	TArray<AActor*> EnemyAIActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AEnemyAI::StaticClass(), EnemyAIActors);


	for (AActor* EnemyAIActor : EnemyAIActors)
	{
		AEnemyAI* EnemyAI = Cast<AEnemyAI>(EnemyAIActor);
		if (EnemyAI)
		{
			EnemyAI->StartBehaviorTree(Player);
			UE_LOG(LogTemp, Display, TEXT("%s"), *EnemyAI->GetActorNameOrLabel());
		}
	}
}
