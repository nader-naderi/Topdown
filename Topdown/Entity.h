#pragma once
#include <vector>
#include "Component.h"
class Entity
{
public:
	unsigned int id;
	std::vector<Component*> components;
	
	Entity() : id(generateId()) {}

	template<typename T>
	void AddComponent(T component)
	{
		components.push_back(component);
	}

private:
	unsigned int generateId()
	{
		static unsigned int currentId = 0;
		return ++currentId;
	}
};

