// Copyright © 2024 XDreamist. All rights reserved.
#pragma once

#include "Component.h"

namespace RAGE::Transform {

	struct InitInfo
	{
		F32 Position[3]{};
		F32 Rotation[4]{};
		F32 Scale[3]{ 1.f, 1.f, 1.f };
	};

	Component createTransform(const InitInfo& info, Core::Entity entity);
	void removeTransform(Component transform);
}