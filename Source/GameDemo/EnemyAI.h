// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"

#include "GameDemoCharacter.h"
#include "EnemyAI.generated.h"

/**
 * 
 */
UCLASS()
class GAMEDEMO_API AEnemyAI : public AAIController
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	APawn* PlayerPawn;

	UPROPERTY(EditAnywhere)
	UBehaviorTree* EnemyAIBehaviorTree;

	AGameDemoCharacter* PlayerCharacter;
	AGameDemoCharacter* EnemyCharacter;
	void StartBehaviorTree(AGameDemoCharacter* Player);
};
