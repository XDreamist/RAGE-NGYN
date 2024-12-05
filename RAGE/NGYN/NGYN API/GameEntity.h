// Copyright © 2024 XDreamist. All rights reserved.
#pragma once

#include "..\Components\Component.h"
#include "TransformComponent.h"

namespace RAGE::Core {

	DEFINE_TYPED_ID(EntityID);

	class Entity
	{
	public:
		// Constructors
		constexpr explicit Entity(EntityID id) : id{ id } {}
		constexpr Entity() : id{ ID::INVALID_ID } {}

		// Accessors
		constexpr EntityID getID() const { return id; }
		constexpr bool isValid() const { return ID::isValid(id); }

		// Retrieve the Transform component
		// Ensure implementation exists in the corresponding .cpp file
		Transform::Component transform() const;

	private:
		EntityID id;
	};

}