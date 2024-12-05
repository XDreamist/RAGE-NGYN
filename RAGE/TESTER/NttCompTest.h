// Copyright © 2024 XDreamist. All rights reserved.
#pragma once

#include "Test.h"

#include "..\NGYN\Components\Ntt.h"
#include "..\NGYN\Components\Transform.h"

#include <iostream>
#include <ctime>

using namespace RAGE;

class NGYN_Test : public Test
{
public:
	bool initialize() override
	{
		srand((U32)time(nullptr));
		return true; 
	}

	void run() override
	{
		do 
		{
			for (U32 i{ 0 }; i < 10000; i++)
			{
				createRandom();
				removeRandom();
				numEntities = (U32)entities.size();
			}
			printTest();
		} while (getchar() != 'q');
	}

	void shutDown() override {}

private:
	void createRandom()
	{
		U32 count = rand() % 20;

		if (entities.empty()) count = 1000;
		Transform::InitInfo transform_info{};
		Core::EntityInfo entity_info
		{
			&transform_info,
		};

		while (count > 0)
		{
			added++;

			Core::Entity entity{ Core::createEntity(entity_info) };
			assert(entity.isValid() && ID::isValid(entity.getID()));
			entities.push_back(entity);
			assert(Core::isAlive(entity));

			count--;
		}
	}

	void removeRandom()
	{
		U32 count = rand() % 20;

		if (entities.size() < 1000) return;

		while (count > 0)
		{
			const U32 index{ (U32)rand() % (U32)entities.size() };
			const Core::Entity entity{ entities[index] };
			assert(entity.isValid() && ID::isValid(entity.getID()));

			if (entity.isValid())
			{
				Core::removeEntity(entity);
				entities.erase(entities.begin() + index);
				assert(!Core::isAlive(entity));
				removed++;
			}

			count--;
		}
	}

	void printTest()
	{
		std::cout << "Entities created : " << added << std::endl;
		std::cout << "Entities removed : " << removed << std::endl;
	}

	Util::vector<Core::Entity> entities;

	U32 added{ 0 };
	U32 removed{ 0 };
	U32 numEntities{ 0 };
};