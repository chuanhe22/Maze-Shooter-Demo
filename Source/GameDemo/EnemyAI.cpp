// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyAI.h"

#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"

void AEnemyAI::BeginPlay()
{
	Super::BeginPlay();

	
	
	
}

void AEnemyAI::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	/*if (PlayerPawn)
	{
		if (LineOfSightTo(PlayerPawn))
		{
			MoveToActor(PlayerPawn, 400.0f);
			SetFocus(PlayerPawn);
		}
		else
		{
			StopMovement();
			ClearFocus(EAIFocusPriority::Gameplay);
		}
	}*/
	
	
}

void AEnemyAI::StartBehaviorTree(AGameDemoCharacter* Player)
{
	if (EnemyAIBehaviorTree)
	{
		EnemyCharacter = Cast<AGameDemoCharacter>(GetPawn());
		if (Player)
		{
			PlayerCharacter = Player;
		}

		RunBehaviorTree(EnemyAIBehaviorTree);
	}
	
	UBlackboardComponent* EnemyAIBlackboard = GetBlackboardComponent();
	if (EnemyAIBlackboard && PlayerCharacter && EnemyCharacter)
	{
		EnemyAIBlackboard->SetValueAsVector("PlayerLocation", PlayerCharacter->GetActorLocation());
		EnemyAIBlackboard->SetValueAsVector("StartLocation", EnemyCharacter->GetActorLocation());
	}

}
