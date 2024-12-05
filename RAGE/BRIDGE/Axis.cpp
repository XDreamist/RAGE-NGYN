#ifndef EDITOR_INTERFACE
#define EDITOR_INTERFACE extern "C" __declspec(dllexport)
#endif 

#include "Common.h"
#include "Id.h"
#include "..\NGYN\Components\Ntt.h"
#include "..\NGYN\Components\Transform.h"

using namespace RAGE;

namespace
{
	struct TransformComponent
	{
		F32 Position[3];
		F32 Rotation[4];
		F32 Scale[3];

		Transform::InitInfo toInitInfo()
		{
			using namespace DirectX;
			Transform::InitInfo info{};
			memcpy(&info.Position[0], &Position[0], sizeof(F32) * _countof(Position));
			memcpy(&info.Scale[0], &Scale[0], sizeof(F32) * _countof(Scale));
			XMFLOAT3A rot{ &Rotation[0] };
			XMVECTOR quat{ XMQuaternionRotationRollPitchYawFromVector(XMLoadFloat3A(&rot)) };

			XMFLOAT4A rot_quat{};
			XMStoreFloat4A(&rot_quat, quat);
			memcpy(&info.Rotation[0], &Rotation[0], sizeof(F32) * _countof(Rotation));

			return info;
 		}
	};

	struct EntityDescriptor
	{
		TransformComponent transform;
	};
}

Core::Entity getEntityFromID(ID::IdType id)
{
	return Core::Entity{ Core::EntityID{id} };
}

EDITOR_INTERFACE
ID::IdType createEntity(EntityDescriptor* entity_descriptor)
{
	assert(entity_descriptor);
	EntityDescriptor& descriptor{ *entity_descriptor };
	Transform::InitInfo transform_info{ descriptor.transform.toInitInfo() };

	Core::EntityInfo enitity_info
	{
		&transform_info,
	};

	return Core::createEntity(enitity_info).getID();
}

EDITOR_INTERFACE
void removeEntity(ID::IdType id)
{
	assert(ID::isValid(id));
	Core::removeEntity(getEntityFromID(id));
}