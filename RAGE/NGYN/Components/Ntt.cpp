// Copyright © 2024 XDreamist. All rights reserved.
#include "Ntt.h"
#include "Transform.h"

namespace RAGE::Core {
	namespace {

		Util::vector<Transform::Component> transforms;

		Util::vector<ID::GenType> generations;
		Util::deque<EntityID> free_ids;
	}

	Entity createEntity(const EntityInfo& info) {
		assert(info.Transform);
		if (!info.Transform) return Entity{};

		EntityID id;

		if (free_ids.size() > ID::MIN_DETECTED_ELEMENTS) {
			id = free_ids.front();
			assert(!isAlive(Entity{ id }));
			free_ids.pop_front();
			id = EntityID{ ID::newGeneration(id) };
			++generations[ ID::index(id) ];
		}
		else {
			id = EntityID{ (ID::IdType)generations.size() };
			generations.push_back(0);

			transforms.resize(generations.size());
			transforms.emplace_back();
		}

		const Entity newEntity{ id };
		const ID::IdType index( ID::index(id) );

		assert(!transforms[index].isValid());
		transforms[index] = Transform::createTransform(*info.Transform, newEntity);

		if (!transforms[index].isValid()) return {};

		return newEntity;
	}

	void removeEntity(Entity entity) {
		const EntityID id{ entity.getID() };
		const ID::IdType index{ ID::index(id) };
		assert(isAlive(entity));

		if (isAlive(entity)) {
			Transform::removeTransform(transforms[index]);
			transforms[index] = {};
			free_ids.push_back(id);
		}
	}

	bool isAlive(Entity entity) {
		assert(entity.isValid());
		const EntityID id{ entity.getID() };
		const ID::IdType index{ ID::index(id)};
		assert(index < generations.size());
		assert(generations[index] == ID::generation(id));

		return (generations[index] == ID::generation(id) && transforms[index].isValid());
	}

	Transform::Component Entity::transform() const {
		assert(isAlive(*this));
		const ID::IdType index{ ID::index(id) };
		return transforms[index];
	}
}