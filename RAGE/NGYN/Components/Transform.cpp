#include "Transform.h"
#include "Ntt.h"

namespace RAGE::Transform
{
	namespace
	{
		Util::vector<Math::Vec4> Rotations;
		Util::vector<Math::Vec3> Positions;
		Util::vector<Math::Vec3> Scales;
	}

	Component createTransform(const InitInfo& info, Core::Entity entity)
	{
		assert(entity.isValid());
		const ID::IdType EntityIndex{ ID::index(entity.getID()) };

		if (Positions.size() > EntityIndex)
		{
			Rotations[EntityIndex] = Math::Vec4(info.Rotation);
			Positions[EntityIndex] = Math::Vec3(info.Position);
			Scales[EntityIndex] = Math::Vec3(info.Scale);
		}
		else
		{
			assert(Positions.size() == EntityIndex);
			Rotations.emplace_back(info.Rotation);
			Positions.emplace_back(info.Position);
			Scales.emplace_back(info.Scale);
		}

		return Component(TransformID{ (ID::IdType)Positions.size() - 1 });
	}

	void removeTransform(Component transform)
	{
		assert(transform.isValid());
	}

	Math::Vec4 Component::Rotation() const
	{
		assert(isValid());
		return Rotations[ID::index(id)];
	}

	Math::Vec3 Component::Position() const
	{
		assert(isValid());
		return Positions[ID::index(id)];
	}

	Math::Vec3 Component::Scale() const
	{
		assert(isValid());
		return Scales[ID::index(id)];
	}
}