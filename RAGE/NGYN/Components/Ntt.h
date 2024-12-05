// Copyright © 2024 XDreamist. All rights reserved.
#pragma once

#include "Component.h"


namespace RAGE {

#define INIT_INFO(component) namespace component { struct InitInfo; }

	INIT_INFO(Transform);

#undef INIT_INFO

	namespace Core {
		struct EntityInfo
		{
			Transform::InitInfo* Transform{ nullptr };
		};

		Entity createEntity(const EntityInfo& info);
		void removeEntity(Entity entity);
		bool isAlive(Entity entity);
	}
}