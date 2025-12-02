// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_LastKnowPlayerLocation.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "EnemyAI.h"

UBTService_LastKnowPlayerLocation::UBTService_LastKnowPlayerLocation()
{
	NodeName = TEXT("PlayerLocation Is Know");
}

void UBTService_LastKnowPlayerLocation::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	AEnemyAI* OwnerController = Cast<AEnemyAI>(OwnerComp.GetAIOwner());
	AGameDemoCharacter* Player = OwnerController->PlayerCharacter;
	UBlackboardComponent* Blackboard = OwnerController->GetBlackboardComponent();

	if (OwnerController && Player && Blackboard)
	{
		if (OwnerController->LineOfSightTo(Player))
		{
			Blackboard->SetValueAsVector(GetSelectedBlackboardKey(), Player->GetActorLocation());
			OwnerController->SetFocus(Player);
		}
		else
		{
			Blackboard->ClearValue(GetSelectedBlackboardKey());
			OwnerController->ClearFocus(EAIFocusPriority::Gameplay);
		}
	}
}
