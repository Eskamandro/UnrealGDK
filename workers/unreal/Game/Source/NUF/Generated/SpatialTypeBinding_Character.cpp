// Copyright (c) Improbable Worlds Ltd, All Rights Reserved
// Note that this file has been generated automatically

#include "SpatialTypeBinding_Character.h"
#include "SpatialOS.h"
#include "Engine.h"
#include "SpatialActorChannel.h"
#include "EntityBuilder.h"
#include "SpatialPackageMapClient.h"
#include "Utils/BunchReader.h"
#include "SpatialNetDriver.h"
#include "SpatialUpdateInterop.h"

namespace {

void ApplyUpdateToSpatial_SingleClient_Character(const uint8* RESTRICT Data, int32 Handle, UProperty* Property, UPackageMap* PackageMap, improbable::unreal::UnrealCharacterSingleClientReplicatedData::Update& Update)
{
}

void ReceiveUpdateFromSpatial_SingleClient_Character(USpatialUpdateInterop* UpdateInterop, UPackageMap* PackageMap, const worker::ComponentUpdateOp<improbable::unreal::UnrealCharacterSingleClientReplicatedData>& Op)
{
	FNetBitWriter OutputWriter(nullptr, 0); 
	auto& HandleToPropertyMap = USpatialTypeBinding_Character::GetHandlePropertyMap();
	USpatialActorChannel* ActorChannel = UpdateInterop->GetClientActorChannel(Op.EntityId);
	if (!ActorChannel)
	{
		return;
	}
	USpatialPackageMapClient* SpatialPMC = Cast<USpatialPackageMapClient>(PackageMap);
	check(SpatialPMC);
	ConditionMapFilter ConditionMap(ActorChannel);
	UpdateInterop->ReceiveSpatialUpdate(ActorChannel, OutputWriter);
}

void ApplyUpdateToSpatial_MultiClient_Character(const uint8* RESTRICT Data, int32 Handle, UProperty* Property, UPackageMap* PackageMap, improbable::unreal::UnrealCharacterMultiClientReplicatedData::Update& Update)
{
	USpatialPackageMapClient* SpatialPMC = Cast<USpatialPackageMapClient>(PackageMap);
	check(SpatialPMC);
	switch (Handle)
	{
		case 1: // field_bhidden
		{
			uint8 Value;
			Value = *(reinterpret_cast<const uint8*>(Data));

			Update.set_field_bhidden(Value != 0);
			break;
		}
		case 2: // field_breplicatemovement
		{
			uint8 Value;
			Value = *(reinterpret_cast<const uint8*>(Data));

			Update.set_field_breplicatemovement(Value != 0);
			break;
		}
		case 3: // field_btearoff
		{
			uint8 Value;
			Value = *(reinterpret_cast<const uint8*>(Data));

			Update.set_field_btearoff(Value != 0);
			break;
		}
		case 4: // field_remoterole
		{
			TEnumAsByte<ENetRole> Value;
			Value = *(reinterpret_cast<const TEnumAsByte<ENetRole>*>(Data));

			Update.set_field_remoterole(uint32_t(Value));
			break;
		}
		case 5: // field_owner
		{
			AActor* Value;
			Value = *(reinterpret_cast<AActor* const*>(Data));

			{
				FNetworkGUID NetGUID = SpatialPMC->GetNetGUIDFromObject(Value);
				improbable::unreal::UnrealObjectRef UObjectRef = SpatialPMC->GetUnrealObjectRefFromNetGUID(NetGUID);
				Update.set_field_owner(UObjectRef);
			}
			break;
		}
		case 6: // field_replicatedmovement
		{
			FRepMovement Value;
			Value = *(reinterpret_cast<const FRepMovement*>(Data));

			{
				TArray<uint8> ValueData;
				FMemoryWriter ValueDataWriter(ValueData);
				bool Success;
				Value.NetSerialize(ValueDataWriter, nullptr, Success);
				Update.set_field_replicatedmovement(std::string((char*)ValueData.GetData(), ValueData.Num()));
			}
			break;
		}
		case 7: // field_attachmentreplication_attachparent
		{
			AActor* Value;
			Value = *(reinterpret_cast<AActor* const*>(Data));

			{
				FNetworkGUID NetGUID = SpatialPMC->GetNetGUIDFromObject(Value);
				improbable::unreal::UnrealObjectRef UObjectRef = SpatialPMC->GetUnrealObjectRefFromNetGUID(NetGUID);
				Update.set_field_attachmentreplication_attachparent(UObjectRef);
			}
			break;
		}
		case 8: // field_attachmentreplication_locationoffset
		{
			FVector_NetQuantize100 Value;
			Value = *(reinterpret_cast<const FVector_NetQuantize100*>(Data));

			Update.set_field_attachmentreplication_locationoffset(improbable::Vector3f(Value.X, Value.Y, Value.Z));
			break;
		}
		case 9: // field_attachmentreplication_relativescale3d
		{
			FVector_NetQuantize100 Value;
			Value = *(reinterpret_cast<const FVector_NetQuantize100*>(Data));

			Update.set_field_attachmentreplication_relativescale3d(improbable::Vector3f(Value.X, Value.Y, Value.Z));
			break;
		}
		case 10: // field_attachmentreplication_rotationoffset
		{
			FRotator Value;
			Value = *(reinterpret_cast<const FRotator*>(Data));

			Update.set_field_attachmentreplication_rotationoffset(improbable::unreal::UnrealFRotator(Value.Yaw, Value.Pitch, Value.Roll));
			break;
		}
		case 11: // field_attachmentreplication_attachsocket
		{
			FName Value;
			Value = *(reinterpret_cast<const FName*>(Data));

			Update.set_field_attachmentreplication_attachsocket(TCHAR_TO_UTF8(*Value.ToString()));
			break;
		}
		case 12: // field_attachmentreplication_attachcomponent
		{
			USceneComponent* Value;
			Value = *(reinterpret_cast<USceneComponent* const*>(Data));

			{
				FNetworkGUID NetGUID = SpatialPMC->GetNetGUIDFromObject(Value);
				improbable::unreal::UnrealObjectRef UObjectRef = SpatialPMC->GetUnrealObjectRefFromNetGUID(NetGUID);
				Update.set_field_attachmentreplication_attachcomponent(UObjectRef);
			}
			break;
		}
		case 13: // field_role
		{
			TEnumAsByte<ENetRole> Value;
			Value = *(reinterpret_cast<const TEnumAsByte<ENetRole>*>(Data));

			Update.set_field_role(uint32_t(Value));
			break;
		}
		case 14: // field_bcanbedamaged
		{
			uint8 Value;
			Value = *(reinterpret_cast<const uint8*>(Data));

			Update.set_field_bcanbedamaged(Value != 0);
			break;
		}
		case 15: // field_instigator
		{
			APawn* Value;
			Value = *(reinterpret_cast<APawn* const*>(Data));

			{
				FNetworkGUID NetGUID = SpatialPMC->GetNetGUIDFromObject(Value);
				improbable::unreal::UnrealObjectRef UObjectRef = SpatialPMC->GetUnrealObjectRefFromNetGUID(NetGUID);
				Update.set_field_instigator(UObjectRef);
			}
			break;
		}
		case 16: // field_playerstate
		{
			APlayerState* Value;
			Value = *(reinterpret_cast<APlayerState* const*>(Data));

			{
				FNetworkGUID NetGUID = SpatialPMC->GetNetGUIDFromObject(Value);
				improbable::unreal::UnrealObjectRef UObjectRef = SpatialPMC->GetUnrealObjectRefFromNetGUID(NetGUID);
				Update.set_field_playerstate(UObjectRef);
			}
			break;
		}
		case 17: // field_remoteviewpitch
		{
			uint8 Value;
			Value = *(reinterpret_cast<const uint8*>(Data));

			Update.set_field_remoteviewpitch(uint32_t(Value));
			break;
		}
		case 18: // field_controller
		{
			AController* Value;
			Value = *(reinterpret_cast<AController* const*>(Data));

			{
				FNetworkGUID NetGUID = SpatialPMC->GetNetGUIDFromObject(Value);
				improbable::unreal::UnrealObjectRef UObjectRef = SpatialPMC->GetUnrealObjectRefFromNetGUID(NetGUID);
				Update.set_field_controller(UObjectRef);
			}
			break;
		}
		case 19: // field_replicatedbasedmovement_movementbase
		{
			UPrimitiveComponent* Value;
			Value = *(reinterpret_cast<UPrimitiveComponent* const*>(Data));

			{
				FNetworkGUID NetGUID = SpatialPMC->GetNetGUIDFromObject(Value);
				improbable::unreal::UnrealObjectRef UObjectRef = SpatialPMC->GetUnrealObjectRefFromNetGUID(NetGUID);
				Update.set_field_replicatedbasedmovement_movementbase(UObjectRef);
			}
			break;
		}
		case 20: // field_replicatedbasedmovement_bonename
		{
			FName Value;
			Value = *(reinterpret_cast<const FName*>(Data));

			Update.set_field_replicatedbasedmovement_bonename(TCHAR_TO_UTF8(*Value.ToString()));
			break;
		}
		case 21: // field_replicatedbasedmovement_location
		{
			FVector_NetQuantize100 Value;
			Value = *(reinterpret_cast<const FVector_NetQuantize100*>(Data));

			Update.set_field_replicatedbasedmovement_location(improbable::Vector3f(Value.X, Value.Y, Value.Z));
			break;
		}
		case 22: // field_replicatedbasedmovement_rotation
		{
			FRotator Value;
			Value = *(reinterpret_cast<const FRotator*>(Data));

			Update.set_field_replicatedbasedmovement_rotation(improbable::unreal::UnrealFRotator(Value.Yaw, Value.Pitch, Value.Roll));
			break;
		}
		case 23: // field_replicatedbasedmovement_bserverhasbasecomponent
		{
			bool Value;
			Value = *(reinterpret_cast<const bool*>(Data));

			Update.set_field_replicatedbasedmovement_bserverhasbasecomponent(Value != 0);
			break;
		}
		case 24: // field_replicatedbasedmovement_brelativerotation
		{
			bool Value;
			Value = *(reinterpret_cast<const bool*>(Data));

			Update.set_field_replicatedbasedmovement_brelativerotation(Value != 0);
			break;
		}
		case 25: // field_replicatedbasedmovement_bserverhasvelocity
		{
			bool Value;
			Value = *(reinterpret_cast<const bool*>(Data));

			Update.set_field_replicatedbasedmovement_bserverhasvelocity(Value != 0);
			break;
		}
		case 26: // field_animrootmotiontranslationscale
		{
			float Value;
			Value = *(reinterpret_cast<const float*>(Data));

			Update.set_field_animrootmotiontranslationscale(Value);
			break;
		}
		case 27: // field_replicatedserverlasttransformupdatetimestamp
		{
			float Value;
			Value = *(reinterpret_cast<const float*>(Data));

			Update.set_field_replicatedserverlasttransformupdatetimestamp(Value);
			break;
		}
		case 28: // field_replicatedmovementmode
		{
			uint8 Value;
			Value = *(reinterpret_cast<const uint8*>(Data));

			Update.set_field_replicatedmovementmode(uint32_t(Value));
			break;
		}
		case 29: // field_biscrouched
		{
			uint8 Value;
			Value = *(reinterpret_cast<const uint8*>(Data));

			Update.set_field_biscrouched(Value != 0);
			break;
		}
		case 30: // field_jumpmaxholdtime
		{
			float Value;
			Value = *(reinterpret_cast<const float*>(Data));

			Update.set_field_jumpmaxholdtime(Value);
			break;
		}
		case 31: // field_jumpmaxcount
		{
			int32 Value;
			Value = *(reinterpret_cast<const int32*>(Data));

			Update.set_field_jumpmaxcount(Value);
			break;
		}
		case 32: // field_reprootmotion_bisactive
		{
			bool Value;
			Value = *(reinterpret_cast<const bool*>(Data));

			Update.set_field_reprootmotion_bisactive(Value != 0);
			break;
		}
		case 33: // field_reprootmotion_animmontage
		{
			UAnimMontage* Value;
			Value = *(reinterpret_cast<UAnimMontage* const*>(Data));

			{
				FNetworkGUID NetGUID = SpatialPMC->GetNetGUIDFromObject(Value);
				improbable::unreal::UnrealObjectRef UObjectRef = SpatialPMC->GetUnrealObjectRefFromNetGUID(NetGUID);
				Update.set_field_reprootmotion_animmontage(UObjectRef);
			}
			break;
		}
		case 34: // field_reprootmotion_position
		{
			float Value;
			Value = *(reinterpret_cast<const float*>(Data));

			Update.set_field_reprootmotion_position(Value);
			break;
		}
		case 35: // field_reprootmotion_location
		{
			FVector_NetQuantize100 Value;
			Value = *(reinterpret_cast<const FVector_NetQuantize100*>(Data));

			Update.set_field_reprootmotion_location(improbable::Vector3f(Value.X, Value.Y, Value.Z));
			break;
		}
		case 36: // field_reprootmotion_rotation
		{
			FRotator Value;
			Value = *(reinterpret_cast<const FRotator*>(Data));

			Update.set_field_reprootmotion_rotation(improbable::unreal::UnrealFRotator(Value.Yaw, Value.Pitch, Value.Roll));
			break;
		}
		case 37: // field_reprootmotion_movementbase
		{
			UPrimitiveComponent* Value;
			Value = *(reinterpret_cast<UPrimitiveComponent* const*>(Data));

			{
				FNetworkGUID NetGUID = SpatialPMC->GetNetGUIDFromObject(Value);
				improbable::unreal::UnrealObjectRef UObjectRef = SpatialPMC->GetUnrealObjectRefFromNetGUID(NetGUID);
				Update.set_field_reprootmotion_movementbase(UObjectRef);
			}
			break;
		}
		case 38: // field_reprootmotion_movementbasebonename
		{
			FName Value;
			Value = *(reinterpret_cast<const FName*>(Data));

			Update.set_field_reprootmotion_movementbasebonename(TCHAR_TO_UTF8(*Value.ToString()));
			break;
		}
		case 39: // field_reprootmotion_brelativeposition
		{
			bool Value;
			Value = *(reinterpret_cast<const bool*>(Data));

			Update.set_field_reprootmotion_brelativeposition(Value != 0);
			break;
		}
		case 40: // field_reprootmotion_brelativerotation
		{
			bool Value;
			Value = *(reinterpret_cast<const bool*>(Data));

			Update.set_field_reprootmotion_brelativerotation(Value != 0);
			break;
		}
		case 41: // field_reprootmotion_authoritativerootmotion
		{
			FRootMotionSourceGroup Value;
			Value = *(reinterpret_cast<const FRootMotionSourceGroup*>(Data));

			Update.set_field_reprootmotion_authoritativerootmotion_bhasadditivesources(Value.bHasAdditiveSources != 0);
			Update.set_field_reprootmotion_authoritativerootmotion_bhasoverridesources(Value.bHasOverrideSources != 0);
			Update.set_field_reprootmotion_authoritativerootmotion_lastpreadditivevelocity(improbable::Vector3f(Value.LastPreAdditiveVelocity.X, Value.LastPreAdditiveVelocity.Y, Value.LastPreAdditiveVelocity.Z));
			Update.set_field_reprootmotion_authoritativerootmotion_bisadditivevelocityapplied(Value.bIsAdditiveVelocityApplied != 0);
			Update.set_field_reprootmotion_authoritativerootmotion_lastaccumulatedsettings_flags(uint32_t(Value.LastAccumulatedSettings.Flags));
			break;
		}
		case 42: // field_reprootmotion_acceleration
		{
			FVector_NetQuantize10 Value;
			Value = *(reinterpret_cast<const FVector_NetQuantize10*>(Data));

			Update.set_field_reprootmotion_acceleration(improbable::Vector3f(Value.X, Value.Y, Value.Z));
			break;
		}
		case 43: // field_reprootmotion_linearvelocity
		{
			FVector_NetQuantize10 Value;
			Value = *(reinterpret_cast<const FVector_NetQuantize10*>(Data));

			Update.set_field_reprootmotion_linearvelocity(improbable::Vector3f(Value.X, Value.Y, Value.Z));
			break;
		}
	default:
		checkf(false, TEXT("Unknown replication handle %d encountered when creating a SpatialOS update."));
		break;
	}
}

void ReceiveUpdateFromSpatial_MultiClient_Character(USpatialUpdateInterop* UpdateInterop, UPackageMap* PackageMap, const worker::ComponentUpdateOp<improbable::unreal::UnrealCharacterMultiClientReplicatedData>& Op)
{
	FNetBitWriter OutputWriter(nullptr, 0); 
	auto& HandleToPropertyMap = USpatialTypeBinding_Character::GetHandlePropertyMap();
	USpatialActorChannel* ActorChannel = UpdateInterop->GetClientActorChannel(Op.EntityId);
	if (!ActorChannel)
	{
		return;
	}
	USpatialPackageMapClient* SpatialPMC = Cast<USpatialPackageMapClient>(PackageMap);
	check(SpatialPMC);
	ConditionMapFilter ConditionMap(ActorChannel);
	if (!Op.Update.field_bhidden().empty())
	{
		// field_bhidden
		uint32 Handle = 1;
		const FRepHandleData& Data = HandleToPropertyMap[Handle];
		if (ConditionMap.IsRelevant(Data.Condition))
		{
			OutputWriter.SerializeIntPacked(Handle);

			uint8 Value;

			Value = *(Op.Update.field_bhidden().data());

			Data.Property->NetSerializeItem(OutputWriter, PackageMap, &Value);
			UE_LOG(LogTemp, Log, TEXT("<- Handle: %d Property %s"), Handle, *Data.Property->GetName());
		}
	}
	if (!Op.Update.field_breplicatemovement().empty())
	{
		// field_breplicatemovement
		uint32 Handle = 2;
		const FRepHandleData& Data = HandleToPropertyMap[Handle];
		if (ConditionMap.IsRelevant(Data.Condition))
		{
			OutputWriter.SerializeIntPacked(Handle);

			uint8 Value;

			Value = *(Op.Update.field_breplicatemovement().data());

			Data.Property->NetSerializeItem(OutputWriter, PackageMap, &Value);
			UE_LOG(LogTemp, Log, TEXT("<- Handle: %d Property %s"), Handle, *Data.Property->GetName());
		}
	}
	if (!Op.Update.field_btearoff().empty())
	{
		// field_btearoff
		uint32 Handle = 3;
		const FRepHandleData& Data = HandleToPropertyMap[Handle];
		if (ConditionMap.IsRelevant(Data.Condition))
		{
			OutputWriter.SerializeIntPacked(Handle);

			uint8 Value;

			Value = *(Op.Update.field_btearoff().data());

			Data.Property->NetSerializeItem(OutputWriter, PackageMap, &Value);
			UE_LOG(LogTemp, Log, TEXT("<- Handle: %d Property %s"), Handle, *Data.Property->GetName());
		}
	}
	if (!Op.Update.field_remoterole().empty())
	{
		// field_remoterole
		uint32 Handle = 4;
		const FRepHandleData& Data = HandleToPropertyMap[Handle];
		if (ConditionMap.IsRelevant(Data.Condition))
		{
			OutputWriter.SerializeIntPacked(Handle);

			TEnumAsByte<ENetRole> Value;

			Value = TEnumAsByte<ENetRole>(uint8(*(Op.Update.field_remoterole().data())));

			Data.Property->NetSerializeItem(OutputWriter, PackageMap, &Value);
			UE_LOG(LogTemp, Log, TEXT("<- Handle: %d Property %s"), Handle, *Data.Property->GetName());
		}
	}
	if (!Op.Update.field_owner().empty())
	{
		// field_owner
		uint32 Handle = 5;
		const FRepHandleData& Data = HandleToPropertyMap[Handle];
		if (ConditionMap.IsRelevant(Data.Condition))
		{
			OutputWriter.SerializeIntPacked(Handle);

			AActor* Value;

			{
				improbable::unreal::UnrealObjectRef TargetObject = *(Op.Update.field_owner().data());
				FNetworkGUID NetGUID = SpatialPMC->GetNetGUIDFromUnrealObjectRef(TargetObject);
				Value = static_cast<AActor*>(SpatialPMC->GetObjectFromNetGUID(NetGUID, true));
			}

			Data.Property->NetSerializeItem(OutputWriter, PackageMap, &Value);
			UE_LOG(LogTemp, Log, TEXT("<- Handle: %d Property %s"), Handle, *Data.Property->GetName());
		}
	}
	if (!Op.Update.field_replicatedmovement().empty())
	{
		// field_replicatedmovement
		uint32 Handle = 6;
		const FRepHandleData& Data = HandleToPropertyMap[Handle];
		if (ConditionMap.IsRelevant(Data.Condition))
		{
			OutputWriter.SerializeIntPacked(Handle);

			FRepMovement Value;

			{
				auto& ValueDataStr = *(Op.Update.field_replicatedmovement().data());
				TArray<uint8> ValueData;
				ValueData.Append((uint8*)ValueDataStr.data(), ValueDataStr.size());
				FMemoryReader ValueDataReader(ValueData);
				bool bSuccess;
				Value.NetSerialize(ValueDataReader, nullptr, bSuccess);
			}

			Data.Property->NetSerializeItem(OutputWriter, PackageMap, &Value);
			UE_LOG(LogTemp, Log, TEXT("<- Handle: %d Property %s"), Handle, *Data.Property->GetName());
		}
	}
	if (!Op.Update.field_attachmentreplication_attachparent().empty())
	{
		// field_attachmentreplication_attachparent
		uint32 Handle = 7;
		const FRepHandleData& Data = HandleToPropertyMap[Handle];
		if (ConditionMap.IsRelevant(Data.Condition))
		{
			OutputWriter.SerializeIntPacked(Handle);

			AActor* Value;

			{
				improbable::unreal::UnrealObjectRef TargetObject = *(Op.Update.field_attachmentreplication_attachparent().data());
				FNetworkGUID NetGUID = SpatialPMC->GetNetGUIDFromUnrealObjectRef(TargetObject);
				Value = static_cast<AActor*>(SpatialPMC->GetObjectFromNetGUID(NetGUID, true));
			}

			Data.Property->NetSerializeItem(OutputWriter, PackageMap, &Value);
			UE_LOG(LogTemp, Log, TEXT("<- Handle: %d Property %s"), Handle, *Data.Property->GetName());
		}
	}
	if (!Op.Update.field_attachmentreplication_locationoffset().empty())
	{
		// field_attachmentreplication_locationoffset
		uint32 Handle = 8;
		const FRepHandleData& Data = HandleToPropertyMap[Handle];
		if (ConditionMap.IsRelevant(Data.Condition))
		{
			OutputWriter.SerializeIntPacked(Handle);

			FVector_NetQuantize100 Value;

			{
				auto& Vector = *(Op.Update.field_attachmentreplication_locationoffset().data());
				Value.X = Vector.x();
				Value.Y = Vector.y();
				Value.Z = Vector.z();
			}

			Data.Property->NetSerializeItem(OutputWriter, PackageMap, &Value);
			UE_LOG(LogTemp, Log, TEXT("<- Handle: %d Property %s"), Handle, *Data.Property->GetName());
		}
	}
	if (!Op.Update.field_attachmentreplication_relativescale3d().empty())
	{
		// field_attachmentreplication_relativescale3d
		uint32 Handle = 9;
		const FRepHandleData& Data = HandleToPropertyMap[Handle];
		if (ConditionMap.IsRelevant(Data.Condition))
		{
			OutputWriter.SerializeIntPacked(Handle);

			FVector_NetQuantize100 Value;

			{
				auto& Vector = *(Op.Update.field_attachmentreplication_relativescale3d().data());
				Value.X = Vector.x();
				Value.Y = Vector.y();
				Value.Z = Vector.z();
			}

			Data.Property->NetSerializeItem(OutputWriter, PackageMap, &Value);
			UE_LOG(LogTemp, Log, TEXT("<- Handle: %d Property %s"), Handle, *Data.Property->GetName());
		}
	}
	if (!Op.Update.field_attachmentreplication_rotationoffset().empty())
	{
		// field_attachmentreplication_rotationoffset
		uint32 Handle = 10;
		const FRepHandleData& Data = HandleToPropertyMap[Handle];
		if (ConditionMap.IsRelevant(Data.Condition))
		{
			OutputWriter.SerializeIntPacked(Handle);

			FRotator Value;

			{
				auto& Rotator = *(Op.Update.field_attachmentreplication_rotationoffset().data());
				Value.Yaw = Rotator.yaw();
				Value.Pitch = Rotator.pitch();
				Value.Roll = Rotator.roll();
			}

			Data.Property->NetSerializeItem(OutputWriter, PackageMap, &Value);
			UE_LOG(LogTemp, Log, TEXT("<- Handle: %d Property %s"), Handle, *Data.Property->GetName());
		}
	}
	if (!Op.Update.field_attachmentreplication_attachsocket().empty())
	{
		// field_attachmentreplication_attachsocket
		uint32 Handle = 11;
		const FRepHandleData& Data = HandleToPropertyMap[Handle];
		if (ConditionMap.IsRelevant(Data.Condition))
		{
			OutputWriter.SerializeIntPacked(Handle);

			FName Value;

			Value = FName((*(Op.Update.field_attachmentreplication_attachsocket().data())).data());

			Data.Property->NetSerializeItem(OutputWriter, PackageMap, &Value);
			UE_LOG(LogTemp, Log, TEXT("<- Handle: %d Property %s"), Handle, *Data.Property->GetName());
		}
	}
	if (!Op.Update.field_attachmentreplication_attachcomponent().empty())
	{
		// field_attachmentreplication_attachcomponent
		uint32 Handle = 12;
		const FRepHandleData& Data = HandleToPropertyMap[Handle];
		if (ConditionMap.IsRelevant(Data.Condition))
		{
			OutputWriter.SerializeIntPacked(Handle);

			USceneComponent* Value;

			{
				improbable::unreal::UnrealObjectRef TargetObject = *(Op.Update.field_attachmentreplication_attachcomponent().data());
				FNetworkGUID NetGUID = SpatialPMC->GetNetGUIDFromUnrealObjectRef(TargetObject);
				Value = static_cast<USceneComponent*>(SpatialPMC->GetObjectFromNetGUID(NetGUID, true));
			}

			Data.Property->NetSerializeItem(OutputWriter, PackageMap, &Value);
			UE_LOG(LogTemp, Log, TEXT("<- Handle: %d Property %s"), Handle, *Data.Property->GetName());
		}
	}
	if (!Op.Update.field_role().empty())
	{
		// field_role
		uint32 Handle = 13;
		const FRepHandleData& Data = HandleToPropertyMap[Handle];
		if (ConditionMap.IsRelevant(Data.Condition))
		{
			OutputWriter.SerializeIntPacked(Handle);

			TEnumAsByte<ENetRole> Value;

			Value = TEnumAsByte<ENetRole>(uint8(*(Op.Update.field_role().data())));

			Data.Property->NetSerializeItem(OutputWriter, PackageMap, &Value);
			UE_LOG(LogTemp, Log, TEXT("<- Handle: %d Property %s"), Handle, *Data.Property->GetName());
		}
	}
	if (!Op.Update.field_bcanbedamaged().empty())
	{
		// field_bcanbedamaged
		uint32 Handle = 14;
		const FRepHandleData& Data = HandleToPropertyMap[Handle];
		if (ConditionMap.IsRelevant(Data.Condition))
		{
			OutputWriter.SerializeIntPacked(Handle);

			uint8 Value;

			Value = *(Op.Update.field_bcanbedamaged().data());

			Data.Property->NetSerializeItem(OutputWriter, PackageMap, &Value);
			UE_LOG(LogTemp, Log, TEXT("<- Handle: %d Property %s"), Handle, *Data.Property->GetName());
		}
	}
	if (!Op.Update.field_instigator().empty())
	{
		// field_instigator
		uint32 Handle = 15;
		const FRepHandleData& Data = HandleToPropertyMap[Handle];
		if (ConditionMap.IsRelevant(Data.Condition))
		{
			OutputWriter.SerializeIntPacked(Handle);

			APawn* Value;

			{
				improbable::unreal::UnrealObjectRef TargetObject = *(Op.Update.field_instigator().data());
				FNetworkGUID NetGUID = SpatialPMC->GetNetGUIDFromUnrealObjectRef(TargetObject);
				Value = static_cast<APawn*>(SpatialPMC->GetObjectFromNetGUID(NetGUID, true));
			}

			Data.Property->NetSerializeItem(OutputWriter, PackageMap, &Value);
			UE_LOG(LogTemp, Log, TEXT("<- Handle: %d Property %s"), Handle, *Data.Property->GetName());
		}
	}
	if (!Op.Update.field_playerstate().empty())
	{
		// field_playerstate
		uint32 Handle = 16;
		const FRepHandleData& Data = HandleToPropertyMap[Handle];
		if (ConditionMap.IsRelevant(Data.Condition))
		{
			OutputWriter.SerializeIntPacked(Handle);

			APlayerState* Value;

			{
				improbable::unreal::UnrealObjectRef TargetObject = *(Op.Update.field_playerstate().data());
				FNetworkGUID NetGUID = SpatialPMC->GetNetGUIDFromUnrealObjectRef(TargetObject);
				Value = static_cast<APlayerState*>(SpatialPMC->GetObjectFromNetGUID(NetGUID, true));
			}

			Data.Property->NetSerializeItem(OutputWriter, PackageMap, &Value);
			UE_LOG(LogTemp, Log, TEXT("<- Handle: %d Property %s"), Handle, *Data.Property->GetName());
		}
	}
	if (!Op.Update.field_remoteviewpitch().empty())
	{
		// field_remoteviewpitch
		uint32 Handle = 17;
		const FRepHandleData& Data = HandleToPropertyMap[Handle];
		if (ConditionMap.IsRelevant(Data.Condition))
		{
			OutputWriter.SerializeIntPacked(Handle);

			uint8 Value;

			Value = uint8(uint8(*(Op.Update.field_remoteviewpitch().data())));

			Data.Property->NetSerializeItem(OutputWriter, PackageMap, &Value);
			UE_LOG(LogTemp, Log, TEXT("<- Handle: %d Property %s"), Handle, *Data.Property->GetName());
		}
	}
	if (!Op.Update.field_controller().empty())
	{
		// field_controller
		uint32 Handle = 18;
		const FRepHandleData& Data = HandleToPropertyMap[Handle];
		if (ConditionMap.IsRelevant(Data.Condition))
		{
			OutputWriter.SerializeIntPacked(Handle);

			AController* Value;

			{
				improbable::unreal::UnrealObjectRef TargetObject = *(Op.Update.field_controller().data());
				FNetworkGUID NetGUID = SpatialPMC->GetNetGUIDFromUnrealObjectRef(TargetObject);
				Value = static_cast<AController*>(SpatialPMC->GetObjectFromNetGUID(NetGUID, true));
			}

			Data.Property->NetSerializeItem(OutputWriter, PackageMap, &Value);
			UE_LOG(LogTemp, Log, TEXT("<- Handle: %d Property %s"), Handle, *Data.Property->GetName());
		}
	}
	if (!Op.Update.field_replicatedbasedmovement_movementbase().empty())
	{
		// field_replicatedbasedmovement_movementbase
		uint32 Handle = 19;
		const FRepHandleData& Data = HandleToPropertyMap[Handle];
		if (ConditionMap.IsRelevant(Data.Condition))
		{
			OutputWriter.SerializeIntPacked(Handle);

			UPrimitiveComponent* Value;

			{
				improbable::unreal::UnrealObjectRef TargetObject = *(Op.Update.field_replicatedbasedmovement_movementbase().data());
				FNetworkGUID NetGUID = SpatialPMC->GetNetGUIDFromUnrealObjectRef(TargetObject);
				Value = static_cast<UPrimitiveComponent*>(SpatialPMC->GetObjectFromNetGUID(NetGUID, true));
			}

			Data.Property->NetSerializeItem(OutputWriter, PackageMap, &Value);
			UE_LOG(LogTemp, Log, TEXT("<- Handle: %d Property %s"), Handle, *Data.Property->GetName());
		}
	}
	if (!Op.Update.field_replicatedbasedmovement_bonename().empty())
	{
		// field_replicatedbasedmovement_bonename
		uint32 Handle = 20;
		const FRepHandleData& Data = HandleToPropertyMap[Handle];
		if (ConditionMap.IsRelevant(Data.Condition))
		{
			OutputWriter.SerializeIntPacked(Handle);

			FName Value;

			Value = FName((*(Op.Update.field_replicatedbasedmovement_bonename().data())).data());

			Data.Property->NetSerializeItem(OutputWriter, PackageMap, &Value);
			UE_LOG(LogTemp, Log, TEXT("<- Handle: %d Property %s"), Handle, *Data.Property->GetName());
		}
	}
	if (!Op.Update.field_replicatedbasedmovement_location().empty())
	{
		// field_replicatedbasedmovement_location
		uint32 Handle = 21;
		const FRepHandleData& Data = HandleToPropertyMap[Handle];
		if (ConditionMap.IsRelevant(Data.Condition))
		{
			OutputWriter.SerializeIntPacked(Handle);

			FVector_NetQuantize100 Value;

			{
				auto& Vector = *(Op.Update.field_replicatedbasedmovement_location().data());
				Value.X = Vector.x();
				Value.Y = Vector.y();
				Value.Z = Vector.z();
			}

			Data.Property->NetSerializeItem(OutputWriter, PackageMap, &Value);
			UE_LOG(LogTemp, Log, TEXT("<- Handle: %d Property %s"), Handle, *Data.Property->GetName());
		}
	}
	if (!Op.Update.field_replicatedbasedmovement_rotation().empty())
	{
		// field_replicatedbasedmovement_rotation
		uint32 Handle = 22;
		const FRepHandleData& Data = HandleToPropertyMap[Handle];
		if (ConditionMap.IsRelevant(Data.Condition))
		{
			OutputWriter.SerializeIntPacked(Handle);

			FRotator Value;

			{
				auto& Rotator = *(Op.Update.field_replicatedbasedmovement_rotation().data());
				Value.Yaw = Rotator.yaw();
				Value.Pitch = Rotator.pitch();
				Value.Roll = Rotator.roll();
			}

			Data.Property->NetSerializeItem(OutputWriter, PackageMap, &Value);
			UE_LOG(LogTemp, Log, TEXT("<- Handle: %d Property %s"), Handle, *Data.Property->GetName());
		}
	}
	if (!Op.Update.field_replicatedbasedmovement_bserverhasbasecomponent().empty())
	{
		// field_replicatedbasedmovement_bserverhasbasecomponent
		uint32 Handle = 23;
		const FRepHandleData& Data = HandleToPropertyMap[Handle];
		if (ConditionMap.IsRelevant(Data.Condition))
		{
			OutputWriter.SerializeIntPacked(Handle);

			bool Value;

			Value = *(Op.Update.field_replicatedbasedmovement_bserverhasbasecomponent().data());

			Data.Property->NetSerializeItem(OutputWriter, PackageMap, &Value);
			UE_LOG(LogTemp, Log, TEXT("<- Handle: %d Property %s"), Handle, *Data.Property->GetName());
		}
	}
	if (!Op.Update.field_replicatedbasedmovement_brelativerotation().empty())
	{
		// field_replicatedbasedmovement_brelativerotation
		uint32 Handle = 24;
		const FRepHandleData& Data = HandleToPropertyMap[Handle];
		if (ConditionMap.IsRelevant(Data.Condition))
		{
			OutputWriter.SerializeIntPacked(Handle);

			bool Value;

			Value = *(Op.Update.field_replicatedbasedmovement_brelativerotation().data());

			Data.Property->NetSerializeItem(OutputWriter, PackageMap, &Value);
			UE_LOG(LogTemp, Log, TEXT("<- Handle: %d Property %s"), Handle, *Data.Property->GetName());
		}
	}
	if (!Op.Update.field_replicatedbasedmovement_bserverhasvelocity().empty())
	{
		// field_replicatedbasedmovement_bserverhasvelocity
		uint32 Handle = 25;
		const FRepHandleData& Data = HandleToPropertyMap[Handle];
		if (ConditionMap.IsRelevant(Data.Condition))
		{
			OutputWriter.SerializeIntPacked(Handle);

			bool Value;

			Value = *(Op.Update.field_replicatedbasedmovement_bserverhasvelocity().data());

			Data.Property->NetSerializeItem(OutputWriter, PackageMap, &Value);
			UE_LOG(LogTemp, Log, TEXT("<- Handle: %d Property %s"), Handle, *Data.Property->GetName());
		}
	}
	if (!Op.Update.field_animrootmotiontranslationscale().empty())
	{
		// field_animrootmotiontranslationscale
		uint32 Handle = 26;
		const FRepHandleData& Data = HandleToPropertyMap[Handle];
		if (ConditionMap.IsRelevant(Data.Condition))
		{
			OutputWriter.SerializeIntPacked(Handle);

			float Value;

			Value = *(Op.Update.field_animrootmotiontranslationscale().data());

			Data.Property->NetSerializeItem(OutputWriter, PackageMap, &Value);
			UE_LOG(LogTemp, Log, TEXT("<- Handle: %d Property %s"), Handle, *Data.Property->GetName());
		}
	}
	if (!Op.Update.field_replicatedserverlasttransformupdatetimestamp().empty())
	{
		// field_replicatedserverlasttransformupdatetimestamp
		uint32 Handle = 27;
		const FRepHandleData& Data = HandleToPropertyMap[Handle];
		if (ConditionMap.IsRelevant(Data.Condition))
		{
			OutputWriter.SerializeIntPacked(Handle);

			float Value;

			Value = *(Op.Update.field_replicatedserverlasttransformupdatetimestamp().data());

			Data.Property->NetSerializeItem(OutputWriter, PackageMap, &Value);
			UE_LOG(LogTemp, Log, TEXT("<- Handle: %d Property %s"), Handle, *Data.Property->GetName());
		}
	}
	if (!Op.Update.field_replicatedmovementmode().empty())
	{
		// field_replicatedmovementmode
		uint32 Handle = 28;
		const FRepHandleData& Data = HandleToPropertyMap[Handle];
		if (ConditionMap.IsRelevant(Data.Condition))
		{
			OutputWriter.SerializeIntPacked(Handle);

			uint8 Value;

			Value = uint8(uint8(*(Op.Update.field_replicatedmovementmode().data())));

			Data.Property->NetSerializeItem(OutputWriter, PackageMap, &Value);
			UE_LOG(LogTemp, Log, TEXT("<- Handle: %d Property %s"), Handle, *Data.Property->GetName());
		}
	}
	if (!Op.Update.field_biscrouched().empty())
	{
		// field_biscrouched
		uint32 Handle = 29;
		const FRepHandleData& Data = HandleToPropertyMap[Handle];
		if (ConditionMap.IsRelevant(Data.Condition))
		{
			OutputWriter.SerializeIntPacked(Handle);

			uint8 Value;

			Value = *(Op.Update.field_biscrouched().data());

			Data.Property->NetSerializeItem(OutputWriter, PackageMap, &Value);
			UE_LOG(LogTemp, Log, TEXT("<- Handle: %d Property %s"), Handle, *Data.Property->GetName());
		}
	}
	if (!Op.Update.field_jumpmaxholdtime().empty())
	{
		// field_jumpmaxholdtime
		uint32 Handle = 30;
		const FRepHandleData& Data = HandleToPropertyMap[Handle];
		if (ConditionMap.IsRelevant(Data.Condition))
		{
			OutputWriter.SerializeIntPacked(Handle);

			float Value;

			Value = *(Op.Update.field_jumpmaxholdtime().data());

			Data.Property->NetSerializeItem(OutputWriter, PackageMap, &Value);
			UE_LOG(LogTemp, Log, TEXT("<- Handle: %d Property %s"), Handle, *Data.Property->GetName());
		}
	}
	if (!Op.Update.field_jumpmaxcount().empty())
	{
		// field_jumpmaxcount
		uint32 Handle = 31;
		const FRepHandleData& Data = HandleToPropertyMap[Handle];
		if (ConditionMap.IsRelevant(Data.Condition))
		{
			OutputWriter.SerializeIntPacked(Handle);

			int32 Value;

			Value = *(Op.Update.field_jumpmaxcount().data());

			Data.Property->NetSerializeItem(OutputWriter, PackageMap, &Value);
			UE_LOG(LogTemp, Log, TEXT("<- Handle: %d Property %s"), Handle, *Data.Property->GetName());
		}
	}
	if (!Op.Update.field_reprootmotion_bisactive().empty())
	{
		// field_reprootmotion_bisactive
		uint32 Handle = 32;
		const FRepHandleData& Data = HandleToPropertyMap[Handle];
		if (ConditionMap.IsRelevant(Data.Condition))
		{
			OutputWriter.SerializeIntPacked(Handle);

			bool Value;

			Value = *(Op.Update.field_reprootmotion_bisactive().data());

			Data.Property->NetSerializeItem(OutputWriter, PackageMap, &Value);
			UE_LOG(LogTemp, Log, TEXT("<- Handle: %d Property %s"), Handle, *Data.Property->GetName());
		}
	}
	if (!Op.Update.field_reprootmotion_animmontage().empty())
	{
		// field_reprootmotion_animmontage
		uint32 Handle = 33;
		const FRepHandleData& Data = HandleToPropertyMap[Handle];
		if (ConditionMap.IsRelevant(Data.Condition))
		{
			OutputWriter.SerializeIntPacked(Handle);

			UAnimMontage* Value;

			{
				improbable::unreal::UnrealObjectRef TargetObject = *(Op.Update.field_reprootmotion_animmontage().data());
				FNetworkGUID NetGUID = SpatialPMC->GetNetGUIDFromUnrealObjectRef(TargetObject);
				Value = static_cast<UAnimMontage*>(SpatialPMC->GetObjectFromNetGUID(NetGUID, true));
			}

			Data.Property->NetSerializeItem(OutputWriter, PackageMap, &Value);
			UE_LOG(LogTemp, Log, TEXT("<- Handle: %d Property %s"), Handle, *Data.Property->GetName());
		}
	}
	if (!Op.Update.field_reprootmotion_position().empty())
	{
		// field_reprootmotion_position
		uint32 Handle = 34;
		const FRepHandleData& Data = HandleToPropertyMap[Handle];
		if (ConditionMap.IsRelevant(Data.Condition))
		{
			OutputWriter.SerializeIntPacked(Handle);

			float Value;

			Value = *(Op.Update.field_reprootmotion_position().data());

			Data.Property->NetSerializeItem(OutputWriter, PackageMap, &Value);
			UE_LOG(LogTemp, Log, TEXT("<- Handle: %d Property %s"), Handle, *Data.Property->GetName());
		}
	}
	if (!Op.Update.field_reprootmotion_location().empty())
	{
		// field_reprootmotion_location
		uint32 Handle = 35;
		const FRepHandleData& Data = HandleToPropertyMap[Handle];
		if (ConditionMap.IsRelevant(Data.Condition))
		{
			OutputWriter.SerializeIntPacked(Handle);

			FVector_NetQuantize100 Value;

			{
				auto& Vector = *(Op.Update.field_reprootmotion_location().data());
				Value.X = Vector.x();
				Value.Y = Vector.y();
				Value.Z = Vector.z();
			}

			Data.Property->NetSerializeItem(OutputWriter, PackageMap, &Value);
			UE_LOG(LogTemp, Log, TEXT("<- Handle: %d Property %s"), Handle, *Data.Property->GetName());
		}
	}
	if (!Op.Update.field_reprootmotion_rotation().empty())
	{
		// field_reprootmotion_rotation
		uint32 Handle = 36;
		const FRepHandleData& Data = HandleToPropertyMap[Handle];
		if (ConditionMap.IsRelevant(Data.Condition))
		{
			OutputWriter.SerializeIntPacked(Handle);

			FRotator Value;

			{
				auto& Rotator = *(Op.Update.field_reprootmotion_rotation().data());
				Value.Yaw = Rotator.yaw();
				Value.Pitch = Rotator.pitch();
				Value.Roll = Rotator.roll();
			}

			Data.Property->NetSerializeItem(OutputWriter, PackageMap, &Value);
			UE_LOG(LogTemp, Log, TEXT("<- Handle: %d Property %s"), Handle, *Data.Property->GetName());
		}
	}
	if (!Op.Update.field_reprootmotion_movementbase().empty())
	{
		// field_reprootmotion_movementbase
		uint32 Handle = 37;
		const FRepHandleData& Data = HandleToPropertyMap[Handle];
		if (ConditionMap.IsRelevant(Data.Condition))
		{
			OutputWriter.SerializeIntPacked(Handle);

			UPrimitiveComponent* Value;

			{
				improbable::unreal::UnrealObjectRef TargetObject = *(Op.Update.field_reprootmotion_movementbase().data());
				FNetworkGUID NetGUID = SpatialPMC->GetNetGUIDFromUnrealObjectRef(TargetObject);
				Value = static_cast<UPrimitiveComponent*>(SpatialPMC->GetObjectFromNetGUID(NetGUID, true));
			}

			Data.Property->NetSerializeItem(OutputWriter, PackageMap, &Value);
			UE_LOG(LogTemp, Log, TEXT("<- Handle: %d Property %s"), Handle, *Data.Property->GetName());
		}
	}
	if (!Op.Update.field_reprootmotion_movementbasebonename().empty())
	{
		// field_reprootmotion_movementbasebonename
		uint32 Handle = 38;
		const FRepHandleData& Data = HandleToPropertyMap[Handle];
		if (ConditionMap.IsRelevant(Data.Condition))
		{
			OutputWriter.SerializeIntPacked(Handle);

			FName Value;

			Value = FName((*(Op.Update.field_reprootmotion_movementbasebonename().data())).data());

			Data.Property->NetSerializeItem(OutputWriter, PackageMap, &Value);
			UE_LOG(LogTemp, Log, TEXT("<- Handle: %d Property %s"), Handle, *Data.Property->GetName());
		}
	}
	if (!Op.Update.field_reprootmotion_brelativeposition().empty())
	{
		// field_reprootmotion_brelativeposition
		uint32 Handle = 39;
		const FRepHandleData& Data = HandleToPropertyMap[Handle];
		if (ConditionMap.IsRelevant(Data.Condition))
		{
			OutputWriter.SerializeIntPacked(Handle);

			bool Value;

			Value = *(Op.Update.field_reprootmotion_brelativeposition().data());

			Data.Property->NetSerializeItem(OutputWriter, PackageMap, &Value);
			UE_LOG(LogTemp, Log, TEXT("<- Handle: %d Property %s"), Handle, *Data.Property->GetName());
		}
	}
	if (!Op.Update.field_reprootmotion_brelativerotation().empty())
	{
		// field_reprootmotion_brelativerotation
		uint32 Handle = 40;
		const FRepHandleData& Data = HandleToPropertyMap[Handle];
		if (ConditionMap.IsRelevant(Data.Condition))
		{
			OutputWriter.SerializeIntPacked(Handle);

			bool Value;

			Value = *(Op.Update.field_reprootmotion_brelativerotation().data());

			Data.Property->NetSerializeItem(OutputWriter, PackageMap, &Value);
			UE_LOG(LogTemp, Log, TEXT("<- Handle: %d Property %s"), Handle, *Data.Property->GetName());
		}
	}
	if (!Op.Update.field_reprootmotion_authoritativerootmotion_bhasadditivesources().empty())
	{
		// field_reprootmotion_authoritativerootmotion
		uint32 Handle = 41;
		const FRepHandleData& Data = HandleToPropertyMap[Handle];
		if (ConditionMap.IsRelevant(Data.Condition))
		{
			OutputWriter.SerializeIntPacked(Handle);

			FRootMotionSourceGroup Value;

			Value.bHasAdditiveSources = *(Op.Update.field_reprootmotion_authoritativerootmotion_bhasadditivesources().data());
			Value.bHasOverrideSources = *(Op.Update.field_reprootmotion_authoritativerootmotion_bhasoverridesources().data());
			{
				auto& Vector = *(Op.Update.field_reprootmotion_authoritativerootmotion_lastpreadditivevelocity().data());
				Value.LastPreAdditiveVelocity.X = Vector.x();
				Value.LastPreAdditiveVelocity.Y = Vector.y();
				Value.LastPreAdditiveVelocity.Z = Vector.z();
			}
			Value.bIsAdditiveVelocityApplied = *(Op.Update.field_reprootmotion_authoritativerootmotion_bisadditivevelocityapplied().data());
			Value.LastAccumulatedSettings.Flags = uint8(uint8(*(Op.Update.field_reprootmotion_authoritativerootmotion_lastaccumulatedsettings_flags().data())));

			Data.Property->NetSerializeItem(OutputWriter, PackageMap, &Value);
			UE_LOG(LogTemp, Log, TEXT("<- Handle: %d Property %s"), Handle, *Data.Property->GetName());
		}
	}
	if (!Op.Update.field_reprootmotion_acceleration().empty())
	{
		// field_reprootmotion_acceleration
		uint32 Handle = 42;
		const FRepHandleData& Data = HandleToPropertyMap[Handle];
		if (ConditionMap.IsRelevant(Data.Condition))
		{
			OutputWriter.SerializeIntPacked(Handle);

			FVector_NetQuantize10 Value;

			{
				auto& Vector = *(Op.Update.field_reprootmotion_acceleration().data());
				Value.X = Vector.x();
				Value.Y = Vector.y();
				Value.Z = Vector.z();
			}

			Data.Property->NetSerializeItem(OutputWriter, PackageMap, &Value);
			UE_LOG(LogTemp, Log, TEXT("<- Handle: %d Property %s"), Handle, *Data.Property->GetName());
		}
	}
	if (!Op.Update.field_reprootmotion_linearvelocity().empty())
	{
		// field_reprootmotion_linearvelocity
		uint32 Handle = 43;
		const FRepHandleData& Data = HandleToPropertyMap[Handle];
		if (ConditionMap.IsRelevant(Data.Condition))
		{
			OutputWriter.SerializeIntPacked(Handle);

			FVector_NetQuantize10 Value;

			{
				auto& Vector = *(Op.Update.field_reprootmotion_linearvelocity().data());
				Value.X = Vector.x();
				Value.Y = Vector.y();
				Value.Z = Vector.z();
			}

			Data.Property->NetSerializeItem(OutputWriter, PackageMap, &Value);
			UE_LOG(LogTemp, Log, TEXT("<- Handle: %d Property %s"), Handle, *Data.Property->GetName());
		}
	}
	UpdateInterop->ReceiveSpatialUpdate(ActorChannel, OutputWriter);
}

// RPC sender functions

void ClientCheatWalkSender(worker::Connection* const Connection, struct FFrame* const RPCFrame, const worker::EntityId& Target, USpatialPackageMapClient* SpatialPMC)
{
	improbable::unreal::UnrealClientCheatWalkRequest Request;

	Connection->SendCommandRequest<improbable::unreal::UnrealCharacterClientRPCs::Commands::Clientcheatwalk>(Target, Request, 0);
}

void ClientCheatGhostSender(worker::Connection* const Connection, struct FFrame* const RPCFrame, const worker::EntityId& Target, USpatialPackageMapClient* SpatialPMC)
{
	improbable::unreal::UnrealClientCheatGhostRequest Request;

	Connection->SendCommandRequest<improbable::unreal::UnrealCharacterClientRPCs::Commands::Clientcheatghost>(Target, Request, 0);
}

void ClientCheatFlySender(worker::Connection* const Connection, struct FFrame* const RPCFrame, const worker::EntityId& Target, USpatialPackageMapClient* SpatialPMC)
{
	improbable::unreal::UnrealClientCheatFlyRequest Request;

	Connection->SendCommandRequest<improbable::unreal::UnrealCharacterClientRPCs::Commands::Clientcheatfly>(Target, Request, 0);
}

void BuildSpatialComponentUpdate(const FPropertyChangeState& Changes,
		improbable::unreal::UnrealCharacterSingleClientReplicatedData::Update& SingleClientUpdate,
		bool& bSingleClientUpdateChanged,
		improbable::unreal::UnrealCharacterMultiClientReplicatedData::Update& MultiClientUpdate,
		bool& bMultiClientUpdateChanged,
		UPackageMap* PackageMap)
{
	// Build up SpatialOS component updates.
	auto& PropertyMap = USpatialTypeBinding_Character::GetHandlePropertyMap();
	FChangelistIterator ChangelistIterator(Changes.Changed, 0);
	FRepHandleIterator HandleIterator(ChangelistIterator, Changes.Cmds, Changes.BaseHandleToCmdIndex, 0, 1, 0, Changes.Cmds.Num() - 1);
	while (HandleIterator.NextHandle())
	{
		const FRepLayoutCmd& Cmd = Changes.Cmds[HandleIterator.CmdIndex];
		const uint8* Data = Changes.SourceData + HandleIterator.ArrayOffset + Cmd.Offset;
		auto& PropertyMapData = PropertyMap[HandleIterator.Handle];
		UE_LOG(LogTemp, Log, TEXT("-> Handle: %d Property %s"), HandleIterator.Handle, *Cmd.Property->GetName());
		switch (GetGroupFromCondition(PropertyMapData.Condition))
		{
		case GROUP_SingleClient:
			ApplyUpdateToSpatial_SingleClient_Character(Data, HandleIterator.Handle, Cmd.Property, PackageMap, SingleClientUpdate);
			bSingleClientUpdateChanged = true;
			break;
		case GROUP_MultiClient:
			ApplyUpdateToSpatial_MultiClient_Character(Data, HandleIterator.Handle, Cmd.Property, PackageMap, MultiClientUpdate);
			bMultiClientUpdateChanged = true;
			break;
		}
	}
}
} // ::

const FRepHandlePropertyMap& USpatialTypeBinding_Character::GetHandlePropertyMap()
{
	static FRepHandlePropertyMap* HandleToPropertyMapData = nullptr;
	if (HandleToPropertyMapData == nullptr)
	{
		UClass* Class = FindObject<UClass>(ANY_PACKAGE, TEXT("Character"));
		HandleToPropertyMapData = new FRepHandlePropertyMap();
		auto& HandleToPropertyMap = *HandleToPropertyMapData;
		HandleToPropertyMap.Add(1, FRepHandleData{nullptr, Class->FindPropertyByName("bHidden"), COND_None});
		HandleToPropertyMap.Add(2, FRepHandleData{nullptr, Class->FindPropertyByName("bReplicateMovement"), COND_None});
		HandleToPropertyMap.Add(3, FRepHandleData{nullptr, Class->FindPropertyByName("bTearOff"), COND_None});
		HandleToPropertyMap.Add(4, FRepHandleData{nullptr, Class->FindPropertyByName("RemoteRole"), COND_None});
		HandleToPropertyMap.Add(5, FRepHandleData{nullptr, Class->FindPropertyByName("Owner"), COND_None});
		HandleToPropertyMap.Add(6, FRepHandleData{nullptr, Class->FindPropertyByName("ReplicatedMovement"), COND_SimulatedOrPhysicsNoReplay});
		HandleToPropertyMap.Add(7, FRepHandleData{Class->FindPropertyByName("AttachmentReplication"), nullptr, COND_Custom});
		HandleToPropertyMap[7].Property = Cast<UStructProperty>(HandleToPropertyMap[7].Parent)->Struct->FindPropertyByName("AttachParent");
		HandleToPropertyMap.Add(8, FRepHandleData{Class->FindPropertyByName("AttachmentReplication"), nullptr, COND_Custom});
		HandleToPropertyMap[8].Property = Cast<UStructProperty>(HandleToPropertyMap[8].Parent)->Struct->FindPropertyByName("LocationOffset");
		HandleToPropertyMap.Add(9, FRepHandleData{Class->FindPropertyByName("AttachmentReplication"), nullptr, COND_Custom});
		HandleToPropertyMap[9].Property = Cast<UStructProperty>(HandleToPropertyMap[9].Parent)->Struct->FindPropertyByName("RelativeScale3D");
		HandleToPropertyMap.Add(10, FRepHandleData{Class->FindPropertyByName("AttachmentReplication"), nullptr, COND_Custom});
		HandleToPropertyMap[10].Property = Cast<UStructProperty>(HandleToPropertyMap[10].Parent)->Struct->FindPropertyByName("RotationOffset");
		HandleToPropertyMap.Add(11, FRepHandleData{Class->FindPropertyByName("AttachmentReplication"), nullptr, COND_Custom});
		HandleToPropertyMap[11].Property = Cast<UStructProperty>(HandleToPropertyMap[11].Parent)->Struct->FindPropertyByName("AttachSocket");
		HandleToPropertyMap.Add(12, FRepHandleData{Class->FindPropertyByName("AttachmentReplication"), nullptr, COND_Custom});
		HandleToPropertyMap[12].Property = Cast<UStructProperty>(HandleToPropertyMap[12].Parent)->Struct->FindPropertyByName("AttachComponent");
		HandleToPropertyMap.Add(13, FRepHandleData{nullptr, Class->FindPropertyByName("Role"), COND_None});
		HandleToPropertyMap.Add(14, FRepHandleData{nullptr, Class->FindPropertyByName("bCanBeDamaged"), COND_None});
		HandleToPropertyMap.Add(15, FRepHandleData{nullptr, Class->FindPropertyByName("Instigator"), COND_None});
		HandleToPropertyMap.Add(16, FRepHandleData{nullptr, Class->FindPropertyByName("PlayerState"), COND_None});
		HandleToPropertyMap.Add(17, FRepHandleData{nullptr, Class->FindPropertyByName("RemoteViewPitch"), COND_SkipOwner});
		HandleToPropertyMap.Add(18, FRepHandleData{nullptr, Class->FindPropertyByName("Controller"), COND_None});
		HandleToPropertyMap.Add(19, FRepHandleData{Class->FindPropertyByName("ReplicatedBasedMovement"), nullptr, COND_SimulatedOnly});
		HandleToPropertyMap[19].Property = Cast<UStructProperty>(HandleToPropertyMap[19].Parent)->Struct->FindPropertyByName("MovementBase");
		HandleToPropertyMap.Add(20, FRepHandleData{Class->FindPropertyByName("ReplicatedBasedMovement"), nullptr, COND_SimulatedOnly});
		HandleToPropertyMap[20].Property = Cast<UStructProperty>(HandleToPropertyMap[20].Parent)->Struct->FindPropertyByName("BoneName");
		HandleToPropertyMap.Add(21, FRepHandleData{Class->FindPropertyByName("ReplicatedBasedMovement"), nullptr, COND_SimulatedOnly});
		HandleToPropertyMap[21].Property = Cast<UStructProperty>(HandleToPropertyMap[21].Parent)->Struct->FindPropertyByName("Location");
		HandleToPropertyMap.Add(22, FRepHandleData{Class->FindPropertyByName("ReplicatedBasedMovement"), nullptr, COND_SimulatedOnly});
		HandleToPropertyMap[22].Property = Cast<UStructProperty>(HandleToPropertyMap[22].Parent)->Struct->FindPropertyByName("Rotation");
		HandleToPropertyMap.Add(23, FRepHandleData{Class->FindPropertyByName("ReplicatedBasedMovement"), nullptr, COND_SimulatedOnly});
		HandleToPropertyMap[23].Property = Cast<UStructProperty>(HandleToPropertyMap[23].Parent)->Struct->FindPropertyByName("bServerHasBaseComponent");
		HandleToPropertyMap.Add(24, FRepHandleData{Class->FindPropertyByName("ReplicatedBasedMovement"), nullptr, COND_SimulatedOnly});
		HandleToPropertyMap[24].Property = Cast<UStructProperty>(HandleToPropertyMap[24].Parent)->Struct->FindPropertyByName("bRelativeRotation");
		HandleToPropertyMap.Add(25, FRepHandleData{Class->FindPropertyByName("ReplicatedBasedMovement"), nullptr, COND_SimulatedOnly});
		HandleToPropertyMap[25].Property = Cast<UStructProperty>(HandleToPropertyMap[25].Parent)->Struct->FindPropertyByName("bServerHasVelocity");
		HandleToPropertyMap.Add(26, FRepHandleData{nullptr, Class->FindPropertyByName("AnimRootMotionTranslationScale"), COND_SimulatedOnly});
		HandleToPropertyMap.Add(27, FRepHandleData{nullptr, Class->FindPropertyByName("ReplicatedServerLastTransformUpdateTimeStamp"), COND_SimulatedOnlyNoReplay});
		HandleToPropertyMap.Add(28, FRepHandleData{nullptr, Class->FindPropertyByName("ReplicatedMovementMode"), COND_SimulatedOnly});
		HandleToPropertyMap.Add(29, FRepHandleData{nullptr, Class->FindPropertyByName("bIsCrouched"), COND_SimulatedOnly});
		HandleToPropertyMap.Add(30, FRepHandleData{nullptr, Class->FindPropertyByName("JumpMaxHoldTime"), COND_None});
		HandleToPropertyMap.Add(31, FRepHandleData{nullptr, Class->FindPropertyByName("JumpMaxCount"), COND_None});
		HandleToPropertyMap.Add(32, FRepHandleData{Class->FindPropertyByName("RepRootMotion"), nullptr, COND_SimulatedOnlyNoReplay});
		HandleToPropertyMap[32].Property = Cast<UStructProperty>(HandleToPropertyMap[32].Parent)->Struct->FindPropertyByName("bIsActive");
		HandleToPropertyMap.Add(33, FRepHandleData{Class->FindPropertyByName("RepRootMotion"), nullptr, COND_SimulatedOnlyNoReplay});
		HandleToPropertyMap[33].Property = Cast<UStructProperty>(HandleToPropertyMap[33].Parent)->Struct->FindPropertyByName("AnimMontage");
		HandleToPropertyMap.Add(34, FRepHandleData{Class->FindPropertyByName("RepRootMotion"), nullptr, COND_SimulatedOnlyNoReplay});
		HandleToPropertyMap[34].Property = Cast<UStructProperty>(HandleToPropertyMap[34].Parent)->Struct->FindPropertyByName("Position");
		HandleToPropertyMap.Add(35, FRepHandleData{Class->FindPropertyByName("RepRootMotion"), nullptr, COND_SimulatedOnlyNoReplay});
		HandleToPropertyMap[35].Property = Cast<UStructProperty>(HandleToPropertyMap[35].Parent)->Struct->FindPropertyByName("Location");
		HandleToPropertyMap.Add(36, FRepHandleData{Class->FindPropertyByName("RepRootMotion"), nullptr, COND_SimulatedOnlyNoReplay});
		HandleToPropertyMap[36].Property = Cast<UStructProperty>(HandleToPropertyMap[36].Parent)->Struct->FindPropertyByName("Rotation");
		HandleToPropertyMap.Add(37, FRepHandleData{Class->FindPropertyByName("RepRootMotion"), nullptr, COND_SimulatedOnlyNoReplay});
		HandleToPropertyMap[37].Property = Cast<UStructProperty>(HandleToPropertyMap[37].Parent)->Struct->FindPropertyByName("MovementBase");
		HandleToPropertyMap.Add(38, FRepHandleData{Class->FindPropertyByName("RepRootMotion"), nullptr, COND_SimulatedOnlyNoReplay});
		HandleToPropertyMap[38].Property = Cast<UStructProperty>(HandleToPropertyMap[38].Parent)->Struct->FindPropertyByName("MovementBaseBoneName");
		HandleToPropertyMap.Add(39, FRepHandleData{Class->FindPropertyByName("RepRootMotion"), nullptr, COND_SimulatedOnlyNoReplay});
		HandleToPropertyMap[39].Property = Cast<UStructProperty>(HandleToPropertyMap[39].Parent)->Struct->FindPropertyByName("bRelativePosition");
		HandleToPropertyMap.Add(40, FRepHandleData{Class->FindPropertyByName("RepRootMotion"), nullptr, COND_SimulatedOnlyNoReplay});
		HandleToPropertyMap[40].Property = Cast<UStructProperty>(HandleToPropertyMap[40].Parent)->Struct->FindPropertyByName("bRelativeRotation");
		HandleToPropertyMap.Add(41, FRepHandleData{Class->FindPropertyByName("RepRootMotion"), nullptr, COND_SimulatedOnlyNoReplay});
		HandleToPropertyMap[41].Property = Cast<UStructProperty>(HandleToPropertyMap[41].Parent)->Struct->FindPropertyByName("AuthoritativeRootMotion");
		HandleToPropertyMap.Add(42, FRepHandleData{Class->FindPropertyByName("RepRootMotion"), nullptr, COND_SimulatedOnlyNoReplay});
		HandleToPropertyMap[42].Property = Cast<UStructProperty>(HandleToPropertyMap[42].Parent)->Struct->FindPropertyByName("Acceleration");
		HandleToPropertyMap.Add(43, FRepHandleData{Class->FindPropertyByName("RepRootMotion"), nullptr, COND_SimulatedOnlyNoReplay});
		HandleToPropertyMap[43].Property = Cast<UStructProperty>(HandleToPropertyMap[43].Parent)->Struct->FindPropertyByName("LinearVelocity");
	}
	return *HandleToPropertyMapData;
}

void USpatialTypeBinding_Character::Init(USpatialUpdateInterop* InUpdateInterop, UPackageMap* InPackageMap)
{
	UpdateInterop = InUpdateInterop;
	PackageMap = InPackageMap;
	RPCToSenderMap.Emplace("ClientCheatWalk", &ClientCheatWalkSender);
	RPCToSenderMap.Emplace("ClientCheatGhost", &ClientCheatGhostSender);
	RPCToSenderMap.Emplace("ClientCheatFly", &ClientCheatFlySender);
}

void USpatialTypeBinding_Character::BindToView()
{
	TSharedPtr<worker::View> View = UpdateInterop->GetSpatialOS()->GetView().Pin();
	SingleClientCallback = View->OnComponentUpdate<improbable::unreal::UnrealCharacterSingleClientReplicatedData>([this](
		const worker::ComponentUpdateOp<improbable::unreal::UnrealCharacterSingleClientReplicatedData>& Op)
	{
		ReceiveUpdateFromSpatial_SingleClient_Character(UpdateInterop, PackageMap, Op);
	});
	MultiClientCallback = View->OnComponentUpdate<improbable::unreal::UnrealCharacterMultiClientReplicatedData>([this](
		const worker::ComponentUpdateOp<improbable::unreal::UnrealCharacterMultiClientReplicatedData>& Op)
	{
		ReceiveUpdateFromSpatial_MultiClient_Character(UpdateInterop, PackageMap, Op);
	});
	using ClientRPCCommandTypes = improbable::unreal::UnrealCharacterClientRPCs::Commands;
	RPCReceiverCallbacks.AddUnique(View->OnCommandRequest<ClientRPCCommandTypes::Clientcheatwalk>(std::bind(&USpatialTypeBinding_Character::ClientCheatWalkReceiver, this, std::placeholders::_1)));
	RPCReceiverCallbacks.AddUnique(View->OnCommandRequest<ClientRPCCommandTypes::Clientcheatghost>(std::bind(&USpatialTypeBinding_Character::ClientCheatGhostReceiver, this, std::placeholders::_1)));
	RPCReceiverCallbacks.AddUnique(View->OnCommandRequest<ClientRPCCommandTypes::Clientcheatfly>(std::bind(&USpatialTypeBinding_Character::ClientCheatFlyReceiver, this, std::placeholders::_1)));
}

void USpatialTypeBinding_Character::UnbindFromView()
{
	TSharedPtr<worker::View> View = UpdateInterop->GetSpatialOS()->GetView().Pin();
	View->Remove(SingleClientCallback);
	View->Remove(MultiClientCallback);
	for (auto& Callback : RPCReceiverCallbacks)
	{
	View->Remove(Callback);
	}
}

worker::ComponentId USpatialTypeBinding_Character::GetReplicatedGroupComponentId(EReplicatedPropertyGroup Group) const
{
	switch (Group)
	{
	case GROUP_SingleClient:
		return improbable::unreal::UnrealCharacterSingleClientReplicatedData::ComponentId;
	case GROUP_MultiClient:
		return improbable::unreal::UnrealCharacterMultiClientReplicatedData::ComponentId;
	default:
		checkNoEntry();
		return 0;
	}
}

void USpatialTypeBinding_Character::SendComponentUpdates(const FPropertyChangeState& Changes, const worker::EntityId& EntityId) const
{
	// Build SpatialOS updates.
	improbable::unreal::UnrealCharacterSingleClientReplicatedData::Update SingleClientUpdate;
	bool SingleClientUpdateChanged = false;
	improbable::unreal::UnrealCharacterMultiClientReplicatedData::Update MultiClientUpdate;
	bool MultiClientUpdateChanged = false;
	BuildSpatialComponentUpdate(Changes,
		SingleClientUpdate, SingleClientUpdateChanged,
		MultiClientUpdate, MultiClientUpdateChanged,
		PackageMap);

	// Send SpatialOS updates if anything changed.
	TSharedPtr<worker::Connection> Connection = UpdateInterop->GetSpatialOS()->GetConnection().Pin();
	if (SingleClientUpdateChanged)
	{
		Connection->SendComponentUpdate<improbable::unreal::UnrealCharacterSingleClientReplicatedData>(EntityId, SingleClientUpdate);
	}
	if (MultiClientUpdateChanged)
	{
		Connection->SendComponentUpdate<improbable::unreal::UnrealCharacterMultiClientReplicatedData>(EntityId, MultiClientUpdate);
	}
}

worker::Entity USpatialTypeBinding_Character::CreateActorEntity(const FVector& Position, const FString& Metadata, const FPropertyChangeState& InitialChanges) const
{
	// Setup initial data.
	improbable::unreal::UnrealCharacterSingleClientReplicatedData::Data SingleClientData;
	improbable::unreal::UnrealCharacterSingleClientReplicatedData::Update SingleClientUpdate;
	bool bSingleClientUpdateChanged = false;
	improbable::unreal::UnrealCharacterMultiClientReplicatedData::Data MultiClientData;
	improbable::unreal::UnrealCharacterMultiClientReplicatedData::Update MultiClientUpdate;
	bool bMultiClientUpdateChanged = false;
	BuildSpatialComponentUpdate(InitialChanges,
		SingleClientUpdate, bSingleClientUpdateChanged,
		MultiClientUpdate, bMultiClientUpdateChanged,
		PackageMap);
	SingleClientUpdate.ApplyTo(SingleClientData);
	MultiClientUpdate.ApplyTo(MultiClientData);
	
	// Create entity.
	const improbable::Coordinates SpatialPosition = USpatialOSConversionFunctionLibrary::UnrealCoordinatesToSpatialOsCoordinatesCast(Position);
	improbable::WorkerAttributeSet UnrealWorkerAttributeSet{worker::List<std::string>{"UnrealWorker"}};
	improbable::WorkerAttributeSet UnrealClientAttributeSet{worker::List<std::string>{"UnrealClient"}};
	improbable::WorkerRequirementSet UnrealWorkerWritePermission{{UnrealWorkerAttributeSet}};
	improbable::WorkerRequirementSet UnrealClientWritePermission{{UnrealClientAttributeSet}};
	improbable::WorkerRequirementSet AnyWorkerReadPermission{{UnrealClientAttributeSet, UnrealWorkerAttributeSet}};
	
	return improbable::unreal::FEntityBuilder::Begin()
		.AddPositionComponent(improbable::Position::Data{SpatialPosition}, UnrealWorkerWritePermission)
		.AddMetadataComponent(improbable::Metadata::Data{TCHAR_TO_UTF8(*Metadata)})
		.SetPersistence(true)
		.SetReadAcl(AnyWorkerReadPermission)
		.AddComponent<improbable::unreal::UnrealCharacterSingleClientReplicatedData>(SingleClientData, UnrealWorkerWritePermission)
		.AddComponent<improbable::unreal::UnrealCharacterMultiClientReplicatedData>(MultiClientData, UnrealWorkerWritePermission)
		.AddComponent<improbable::unreal::UnrealCharacterCompleteData>(improbable::unreal::UnrealCharacterCompleteData::Data{}, UnrealWorkerWritePermission)
		.AddComponent<improbable::unreal::UnrealCharacterClientRPCs>(improbable::unreal::UnrealCharacterClientRPCs::Data{}, UnrealWorkerWritePermission)
		.AddComponent<improbable::unreal::UnrealCharacterServerRPCs>(improbable::unreal::UnrealCharacterServerRPCs::Data{}, UnrealClientWritePermission)
		.Build();
}

void USpatialTypeBinding_Character::SendRPCCommand(const UFunction* const Function, FFrame* const RPCFrame, const worker::EntityId& Target) const
{
	TSharedPtr<worker::Connection> Connection = UpdateInterop->GetSpatialOS()->GetConnection().Pin();
	auto Func = RPCToSenderMap.Find(Function->GetFName());
	checkf(*Func, TEXT("Sender for %s has not been registered with RPCToSenderMap."), *(Function->GetFName().ToString()));
	(*Func)(Connection.Get(), RPCFrame, Target, Cast<USpatialPackageMapClient>(PackageMap));
}

void USpatialTypeBinding_Character::ClientCheatWalkReceiver(const worker::CommandRequestOp<improbable::unreal::UnrealCharacterClientRPCs::Commands::Clientcheatwalk>& Op)
{
	USpatialPackageMapClient* SpatialPMC = Cast<USpatialPackageMapClient>(PackageMap);
	FNetworkGUID TargetNetGUID = SpatialPMC->GetNetGUIDFromEntityId(Op.EntityId);
	if (!TargetNetGUID.IsValid())
	{
		UE_LOG(LogSpatialUpdateInterop, Warning, TEXT("ClientCheatWalkReceiver: Entity ID %lld does not have a valid NetGUID."), Op.EntityId);
		return;
	}
	ACharacter* TargetObject = Cast<ACharacter>(SpatialPMC->GetObjectFromNetGUID(TargetNetGUID, false));
	checkf(TargetObject, TEXT("ClientCheatWalkReceiver: Entity ID %lld (NetGUID %s) does not correspond to a UObject."), Op.EntityId, *TargetNetGUID.ToString());

	// Call implementation and send command response.
	TargetObject->ClientCheatWalk_Implementation();
	SendRPCResponse<improbable::unreal::UnrealCharacterClientRPCs::Commands::Clientcheatwalk>(Op);
}

void USpatialTypeBinding_Character::ClientCheatGhostReceiver(const worker::CommandRequestOp<improbable::unreal::UnrealCharacterClientRPCs::Commands::Clientcheatghost>& Op)
{
	USpatialPackageMapClient* SpatialPMC = Cast<USpatialPackageMapClient>(PackageMap);
	FNetworkGUID TargetNetGUID = SpatialPMC->GetNetGUIDFromEntityId(Op.EntityId);
	if (!TargetNetGUID.IsValid())
	{
		UE_LOG(LogSpatialUpdateInterop, Warning, TEXT("ClientCheatGhostReceiver: Entity ID %lld does not have a valid NetGUID."), Op.EntityId);
		return;
	}
	ACharacter* TargetObject = Cast<ACharacter>(SpatialPMC->GetObjectFromNetGUID(TargetNetGUID, false));
	checkf(TargetObject, TEXT("ClientCheatGhostReceiver: Entity ID %lld (NetGUID %s) does not correspond to a UObject."), Op.EntityId, *TargetNetGUID.ToString());

	// Call implementation and send command response.
	TargetObject->ClientCheatGhost_Implementation();
	SendRPCResponse<improbable::unreal::UnrealCharacterClientRPCs::Commands::Clientcheatghost>(Op);
}

void USpatialTypeBinding_Character::ClientCheatFlyReceiver(const worker::CommandRequestOp<improbable::unreal::UnrealCharacterClientRPCs::Commands::Clientcheatfly>& Op)
{
	USpatialPackageMapClient* SpatialPMC = Cast<USpatialPackageMapClient>(PackageMap);
	FNetworkGUID TargetNetGUID = SpatialPMC->GetNetGUIDFromEntityId(Op.EntityId);
	if (!TargetNetGUID.IsValid())
	{
		UE_LOG(LogSpatialUpdateInterop, Warning, TEXT("ClientCheatFlyReceiver: Entity ID %lld does not have a valid NetGUID."), Op.EntityId);
		return;
	}
	ACharacter* TargetObject = Cast<ACharacter>(SpatialPMC->GetObjectFromNetGUID(TargetNetGUID, false));
	checkf(TargetObject, TEXT("ClientCheatFlyReceiver: Entity ID %lld (NetGUID %s) does not correspond to a UObject."), Op.EntityId, *TargetNetGUID.ToString());

	// Call implementation and send command response.
	TargetObject->ClientCheatFly_Implementation();
	SendRPCResponse<improbable::unreal::UnrealCharacterClientRPCs::Commands::Clientcheatfly>(Op);
}
