// Copyright 2023 Hathora, Inc.
#pragma once

#include "CoreMinimal.h"
#include "Delegates/Delegate.h"
#include "DiscoveredPingEndpoint.h"
#include "HathoraPing.generated.h"

UCLASS()
class HATHORASDK_API UHathoraPing : public UObject
{
	GENERATED_BODY()
public:
	// TODO - Why won't DECLARE_DELEGATE_OneParam expand out properly to this?
	typedef TDelegate<void(const TMap<FString, int32>&)> FOnGetRegionalPingsDelegate;

	// Get ping times to all available Hathora Cloud regions
	// pings are returned in milliseconds
	static void GetRegionalPings(const FOnGetRegionalPingsDelegate& OnComplete) ;

private:
	static void PingUrlsAndAggregateTimes(const TArray<FDiscoveredPingEndpoint>& PingEndpoints, const FOnGetRegionalPingsDelegate& OnComplete) ;
};