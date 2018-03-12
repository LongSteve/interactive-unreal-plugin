//*********************************************************
//
// Copyright (c) Microsoft. All rights reserved.
// THIS CODE IS PROVIDED *AS IS* WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING ANY
// IMPLIED WARRANTIES OF FITNESS FOR A PARTICULAR
// PURPOSE, MERCHANTABILITY, OR NON-INFRINGEMENT.
//
//*********************************************************
#pragma once

#include "UnrealString.h"
#include "Dom/JsonValue.h"
#include "Dom/JsonObject.h"
#include "MixerInteractivityLog.h"

namespace MixerStringConstants
{
	namespace MessageTypes
	{
		extern const FString Method;
		extern const FString Reply;
		extern const FString Event;
	}

	namespace MethodNames
	{
		extern const FString Auth;
		extern const FString Msg;
		extern const FString Whisper;
		extern const FString History;
		extern const FString VoteStart;
		extern const FString VoteChoose;
	}

	namespace EventTypes
	{
		extern const FString Welcome;
		extern const FString ChatMessage;
		extern const FString UserJoin;
		extern const FString UserLeave;
		extern const FString DeleteMessage;
		extern const FString ClearMessages;
		extern const FString PurgeMessage;
		extern const FString PollStart;
		extern const FString PollEnd;
	}

	namespace FieldNames
	{
		extern const FString Type;
		extern const FString Event;
		extern const FString Data;
		extern const FString Message;
		extern const FString UserNameNoUnderscore;
		extern const FString UserNameWithUnderscore;
		extern const FString Id;
		extern const FString Meta;
		extern const FString Me;
		extern const FString Whisper;
		extern const FString Method;
		extern const FString Arguments;
		extern const FString Params;
		extern const FString Error;
		extern const FString Text;
		extern const FString Endpoints;
		extern const FString AuthKey;
		extern const FString UserIdNoUnderscore;
		extern const FString UserIdWithUnderscore;
		extern const FString UserLevel;
		extern const FString Q;
		extern const FString EndsAt;
		extern const FString Voters;
		extern const FString Answers;
		extern const FString ResponsesByIndex;
		extern const FString Author;
		extern const FString Permissions;
		extern const FString Level;
		extern const FString LastInputAt;
		extern const FString ConnectedAt;
		extern const FString GroupId;
		extern const FString SessionId;
		extern const FString Participants;
		extern const FString IsReady;
	}

	namespace Permissions
	{
		extern const FString Connect;
		extern const FString Chat;
		extern const FString Whisper;
		extern const FString PollStart;
		extern const FString PollVote;
		extern const FString ClearMessages;
		extern const FString Purge;
		extern const FString GiveawayStart;
	}
}

#define GET_JSON_FIELD_RETURN_FAILURE(JsonType, JsonNameConstant, UEType, UEName) \
UEType UEName; \
if (!JsonObj->TryGet##JsonType##Field(MixerStringConstants::FieldNames::##JsonNameConstant, UEName)) \
{ \
	UE_LOG(LogMixerInteractivity, Error, TEXT("Missing required %s field in json payload"), *MixerStringConstants::FieldNames::##JsonNameConstant); \
	return false; \
}

#define GET_JSON_STRING_RETURN_FAILURE(JsonNameConstant, UEName)	GET_JSON_FIELD_RETURN_FAILURE(String, JsonNameConstant, FString, UEName)
#define GET_JSON_INT_RETURN_FAILURE(JsonNameConstant, UEName)		GET_JSON_FIELD_RETURN_FAILURE(Number, JsonNameConstant, int32, UEName)
#define GET_JSON_DOUBLE_RETURN_FAILURE(JsonNameConstant, UEName)	GET_JSON_FIELD_RETURN_FAILURE(Number, JsonNameConstant, double, UEName)
#define GET_JSON_OBJECT_RETURN_FAILURE(JsonNameConstant, UEName)	GET_JSON_FIELD_RETURN_FAILURE(Object, JsonNameConstant, const TSharedPtr<FJsonObject>*, UEName)
#define GET_JSON_ARRAY_RETURN_FAILURE(JsonNameConstant, UEName)		GET_JSON_FIELD_RETURN_FAILURE(Array, JsonNameConstant, const TArray<TSharedPtr<FJsonValue>> *, UEName)
#define GET_JSON_BOOL_RETURN_FAILURE(JsonNameConstant, UEName)		GET_JSON_FIELD_RETURN_FAILURE(Bool, JsonNameConstant, bool, UEName)
