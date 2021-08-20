// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BFActorTools.generated.h"

/**
 * Actor 工具
 */
UCLASS()
class BADFISHYUTILITIES_API UBFActorTools : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:

	/* --- 通过传入数组的类型查找对应类型的子Actor Start --- */
	template <class T, class AllocatorType>
	static void GetAttachActorsUsedArrayType(AActor* ParentActor,
	                                         TArray<T*, AllocatorType>& OutComponents,
	                                         bool bIncludeFromChildActors = false)
	{
		TArray<AActor*> AttachedActors;
		ParentActor->GetAttachedActors(AttachedActors);
		for (auto ThisActor : AttachedActors)
		{
			T* LocTypeActor = Cast<T>(ThisActor);
			if (LocTypeActor != nullptr)
			{
				OutComponents.Add(LocTypeActor);
			}
			if (bIncludeFromChildActors)
			{
				GetAttachActorsUsedArrayType(LocTypeActor, OutComponents, bIncludeFromChildActors);
			}
		}
	}
	/* --- 通过传入数组的类型查找对应类型的子Actor End --- */

	UFUNCTION(BlueprintPure, meta = (DefaultToSelf  = WorldContextObject))
	static bool IsListenServer(const UObject* WorldContextObject);
	
};
