// Fill out your copyright notice in the Description page of Project Settings.


#include "BFActorTools.h"

#include "Kismet/KismetSystemLibrary.h"

bool UBFActorTools::IsListenServer(const UObject* WorldContextObject)
{
	return UKismetSystemLibrary::IsServer(WorldContextObject) && !UKismetSystemLibrary::IsDedicatedServer(
		WorldContextObject);
}
