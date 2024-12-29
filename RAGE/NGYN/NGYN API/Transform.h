// Copyright © 2024 XDreamist. All rights reserved.
#pragma once

#include "..\Components\Component.h"

namespace RAGE::Transform 
{
	DEFINE_TYPED_ID(TransformID);

	class Component final
	{
	public:
		constexpr explicit Component(TransformID id) : id{ id } {};
		constexpr Component() : id{ ID::INVALID_ID } {};
		constexpr TransformID getID() const { return id; }
		constexpr bool isValid() const { return ID::isValid(id); }

		Math::Vec4 Rotation() const;
		Math::Vec3 Position() const;
		Math::Vec3 Scale() const;

	private:
		TransformID id;
	};
}