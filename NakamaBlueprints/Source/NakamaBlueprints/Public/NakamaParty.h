﻿#pragma once

#include "CoreMinimal.h"
#include "nakama-cpp/Nakama.h"
#include "NakamaPresence.h"
#include "NakamaParty.generated.h"

using namespace Nakama;



// Parties
USTRUCT(BlueprintType)
struct NAKAMABLUEPRINTS_API FNakamaParty
{
	GENERATED_BODY()

	// The unique party identifier.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Nakama|Parties")
	FString Id;

	// True, if the party is open to join.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Nakama|Parties")
	bool Open;

	// The maximum number of party members.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Nakama|Parties")
	int32 MaxSize;

	// The current user in this party. i.e. Yourself.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, DisplayName = "Self", Category = "Nakama|Parties")
	FNakamaUserPresence Me;

	// The current party leader.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Nakama|Parties")
	FNakamaUserPresence Leader;

	// All members currently in the party.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Nakama|Parties")
	TArray<FNakamaUserPresence> Presences;
	
	FNakamaParty(const NParty& NakamaNativeParty);
	FNakamaParty(); // Default Constructor

	
	
};

// Incoming notification for one or more new presences attempting to join the party.
USTRUCT(BlueprintType)
struct NAKAMABLUEPRINTS_API FNakamaPartyJoinRequest
{
	GENERATED_BODY()

	// The ID of the party to get a list of join requests for.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Nakama|Parties")
	FString PartyId;

	// Presences attempting to join, or who have joined.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Nakama|Parties")
	TArray<FNakamaUserPresence> Presences;

	FNakamaPartyJoinRequest(const NPartyJoinRequest& NakamaNativePartyJoinRequest);
	FNakamaPartyJoinRequest(); // Default Constructor
};

// Incoming notification for one or more new presences attempting to join the party.
USTRUCT(BlueprintType)
struct NAKAMABLUEPRINTS_API FNakamaPartyMatchmakerTicket
{
	GENERATED_BODY()

	// The ID of the party.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Nakama|Parties")
	FString PartyId;

	// The ticket that can be used to cancel matchmaking.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Nakama|Parties")
	FString Ticket;

	FNakamaPartyMatchmakerTicket(NPartyMatchmakerTicket NakamaNativePartyMatchmakerTicket);
	FNakamaPartyMatchmakerTicket();
};

// Information about a party close event.
USTRUCT(BlueprintType)
struct NAKAMABLUEPRINTS_API FNakamaPartyClose
{
	GENERATED_BODY()

	// The unique party identifier of the closing party.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Nakama|Parties")
	FString Id;
	
	FNakamaPartyClose(const NPartyClose& NakamaNativePartyClose);
	FNakamaPartyClose();
};

// Incoming party data delivered from the server.
USTRUCT(BlueprintType)
struct NAKAMABLUEPRINTS_API FNakamaPartyData
{
	GENERATED_BODY()

	// The unique party identifier of the closing party.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Nakama|Parties")
	FString PartyId;

	// A reference to the user presence that sent this data, if any.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Nakama|Parties")
	FNakamaUserPresence Presence;

	// A reference to the user presence that sent this data, if any.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Nakama|Parties")
	int64 OpCode;

	// A reference to the user presence that sent this data, if any.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Nakama|Parties")
	FString Data; // NBytes
	
	FNakamaPartyData(const NPartyData& NakamaNativePartyData);
	FNakamaPartyData();
};


// Announcement of a new party leader.
USTRUCT(BlueprintType)
struct NAKAMABLUEPRINTS_API FNakamaPartyLeader
{
	GENERATED_BODY()

	// The ID of the party to announce the new leader for.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Nakama|Parties")
	FString PartyId;

	// The presence of the new party leader.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Nakama|Parties")
	FNakamaUserPresence Presence;
	
	FNakamaPartyLeader(const NPartyLeader& NakamaNativePartyLeader);
	FNakamaPartyLeader();
};


// Presence update for a particular party.
USTRUCT(BlueprintType)
struct NAKAMABLUEPRINTS_API FNakamaPartyPresenceEvent
{
	GENERATED_BODY()

	// The ID of the party.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Nakama|Parties")
	FString PartyId;

	// The user presences that have just joined the party.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Nakama|Parties")
	TArray<FNakamaUserPresence> Joins;

	// The user presences that have just left the party.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Nakama|Parties")
	TArray<FNakamaUserPresence> Leaves;

	FNakamaPartyPresenceEvent(const NPartyPresenceEvent& NakamaNativePartyPresenceEvent);
	FNakamaPartyPresenceEvent();
};