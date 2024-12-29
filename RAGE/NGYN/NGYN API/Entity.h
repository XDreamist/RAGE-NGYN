// Copyright © 2024 XDreamist. All rights reserved.
#pragma once

#include "..\Components\Component.h"
#include "Transform.h"

namespace RAGE::Core {

	DEFINE_TYPED_ID(EntityID);

	class Entity
	{
	public:
		constexpr explicit Entity(EntityID id) : id{ id } {}
		constexpr Entity() : id{ ID::INVALID_ID } {}

		constexpr EntityID getID() const { return id; }
		constexpr bool isValid() const { return ID::isValid(id); }

		Transform::Component transform() const;

	private:
		EntityID id;
	};

}