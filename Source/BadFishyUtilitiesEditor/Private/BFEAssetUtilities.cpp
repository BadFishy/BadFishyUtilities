// Fill out your copyright notice in the Description page of Project Settings.


#include "BFEAssetUtilities.h"
#include "Engine/AssetManager.h"

void UBFEAssetUtilities::GetAllAssetSoftByClassAndPath(TArray<FName> PackagePaths, TArray<FName> ClassNames,
	TArray<TSoftObjectPtr<>>& ArrayAssetsSoft)
{
	FARFilter Filter;
	Filter.PackagePaths = PackagePaths;
	Filter.ClassNames = ClassNames;
	Filter.bRecursivePaths = true;
	Filter.bRecursiveClasses = true;
	TArray<FAssetData> OutAssetData;
	UAssetManager::Get().GetAssetRegistry().GetAssets(Filter, OutAssetData);
	for (const auto CurrentAssetData : OutAssetData)
	{
		FSoftObjectPath AssetPath = FSoftObjectPath(CurrentAssetData.ObjectPath);
		ArrayAssetsSoft.Add(TSoftObjectPtr<>(AssetPath));
	}
	return;
}
