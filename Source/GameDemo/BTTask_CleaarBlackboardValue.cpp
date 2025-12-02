// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_CleaarBlackboardValue.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTask_CleaarBlackboardValue::UBTTask_CleaarBlackboardValue()
{
	NodeName = TEXT("Clear Blackboard Value");
}

EBTNodeResult::Type UBTTask_CleaarBlackboardValue::ExecuteTask(UBehaviorTreeComponent& OwnerComp,
	uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);
	UBlackboardComponent* Blackboard = OwnerComp.GetBlackboardComponent();
	if (Blackboard)
	{
		Blackboard->ClearValue(GetSelectedBlackboardKey());
	}
	return EBTNodeResult::Succeeded;
}
