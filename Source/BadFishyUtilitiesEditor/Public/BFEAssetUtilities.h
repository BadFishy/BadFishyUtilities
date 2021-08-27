// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BFEAssetUtilities.generated.h"

/**
 * 
 */
UCLASS()
class BADFISHYUTILITIESEDITOR_API UBFEAssetUtilities : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	
	// 通过路径和类型获取资产软引用
	UFUNCTION(BlueprintCallable)
	static void GetAllAssetSoftByClassAndPath(TArray<FName> PackagePaths, TArray<FName> ClassNames,
	                                          TArray<TSoftObjectPtr<UObject>>& ArrayAssetsSoft);
};
