﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NakamaStorageTypes.h"
#include "nakama-cpp/Nakama.h"

#include "NakamaStorageObject.generated.h"

using namespace Nakama;

// An object within the storage engine.
USTRUCT(BlueprintType)
struct NAKAMA_API FNakamaStoreObjectData
{
	GENERATED_BODY()

	// The collection which stores the object.
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Nakama|Storage")
	FString Collection;

	// The key of the object within the collection.
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Nakama|Storage")
	FString Key;

	// The user owner of the object.
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Nakama|Storage")
	FString UserId;

	// The value of the object.
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Nakama|Storage")
	FString Value;

	// The version hash of the object.
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Nakama|Storage")
	FString Version;

	// The read access permissions for the object.
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Nakama|Storage") //BlueprintReadOnly
	ENakamaStoragePermissionRead PermissionRead; //NO_READ

	// The write access permissions for the object.
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Nakama|Storage") //BlueprintReadOnly
	ENakamaStoragePermissionWrite PermissionWrite; //NO_WRITE

	// The UNIX time when the object was created.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Nakama|Storage")
	FDateTime CreateTime = 0;

	// The UNIX time when the object was last updated.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Nakama|Storage")
	FDateTime UpdateTime = 0;

	FNakamaStoreObjectData(const NStorageObject& NakamaNativeStorageObject);
	FNakamaStoreObjectData();
};

// The object to store.
USTRUCT(BlueprintType)
struct NAKAMA_API FNakamaStoreObjectWrite
{
	GENERATED_BODY()

	// The collection which stores the object.
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Nakama|Storage")
	FString Collection;

	// The key of the object within the collection.
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Nakama|Storage")
	FString Key;

	// The value of the object. Must be JSON
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Nakama|Storage")
	FString Value;

	// The version hash of the object to check. Possible values are: ["", "*", "#hash#"].
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Nakama|Storage")
	FString Version;

	// The read access permissions for the object.
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Nakama|Storage") //BlueprintReadOnly
	ENakamaStoragePermissionRead PermissionRead; //NO_READ

	// The write access permissions for the object.
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Nakama|Storage") //BlueprintReadOnly
	ENakamaStoragePermissionWrite PermissionWrite; //NO_WRITE


	FNakamaStoreObjectWrite(const NStorageObjectWrite& NakamaNativeStorageWrite);
	FNakamaStoreObjectWrite();
};





// Storage objects to get (from reading)
USTRUCT(BlueprintType)
struct NAKAMA_API FNakamaReadStorageObjectId
{
	GENERATED_BODY()

	// The collection which stores the object.
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Nakama|Storage")
	FString Collection;

	// The key of the object within the collection.
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Nakama|Storage")
	FString Key;

	// The user owner of the object.
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Nakama|Storage")
	FString UserId;

	FNakamaReadStorageObjectId(const NReadStorageObjectId& NakamaNativeReadStorageObjectId);
	FNakamaReadStorageObjectId();
};


// Storage objects to delete.
USTRUCT(BlueprintType) // For deleting from storage
struct NAKAMA_API FNakamaDeleteStorageObjectId
{
	GENERATED_BODY()

	// The collection which stores the object.
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Nakama|Storage")
	FString Collection;

	// The key of the object within the collection.
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Nakama|Storage")
	FString Key;

	// The version hash of the object.
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Nakama|Storage")
	FString Version;

	FNakamaDeleteStorageObjectId(const NDeleteStorageObjectId& NakamaNativeDeleteStorageObjectId);
	FNakamaDeleteStorageObjectId();
};


// A storage acknowledgement.
USTRUCT(BlueprintType)
struct NAKAMA_API FNakamaStoreObjectAck
{
	GENERATED_BODY()

	// The collection which stores the object.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Nakama|Storage")
	FString Collection;

	// The key of the object within the collection.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Nakama|Storage")
	FString Key;

	// The version hash of the object.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Nakama|Storage")
	FString Version;

	// The owner of the object.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Nakama|Storage")
	FString UserId;

	FNakamaStoreObjectAck(const NStorageObjectAck& NakamaNativeStorageObjectAck);
	FNakamaStoreObjectAck();

};

// Batch of acknowledgements.
USTRUCT(BlueprintType)
struct NAKAMA_API FNakamaStoreObjectAcks
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Nakama|Storage")
	TArray<FNakamaStoreObjectAck> StorageObjects;

	FNakamaStoreObjectAcks(const NStorageObjectAcks& NakamaNativeStorageObjectAcks);
	FNakamaStoreObjectAcks();

};

// List of storage objects.
USTRUCT(BlueprintType)
struct NAKAMA_API FNakamaStorageObjectList
{
	GENERATED_BODY()

	// The list of storage objects.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Nakama|Storage")
	TArray<FNakamaStoreObjectData> Objects;

	// For the next page results, if any.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Nakama|Storage")
	FString Cursor;

	FNakamaStorageObjectList(const NStorageObjectList& NakamaNativeStorageObjectList);
	FNakamaStorageObjectList();

};