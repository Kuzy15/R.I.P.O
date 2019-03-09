#include "Entity.h"

Entity::Entity(std::string id)
{
	_id = id;
}

Entity::~Entity() 
{
	// delete each pointer
	for (std::vector<Component *>::iterator it = _components.begin(); it != _components.end(); ++it)
		delete (*it);
	// clear the vector
	_components.clear();
}

void Entity::AddComponent(Component * c)
{
	// push a new component into the vector
	_components.emplace_back(c);
}

void Entity::DeleteComponent(Component * c)
{
	int i = 0;
	bool found = false;
	// search for the component c
	while (!found && i < _components.size()) 
	{
		// when it's found,
		if (_components.at(i) == c) 
		{
			Component* aux = _components.at(i);
			// delete the reference from the vector
			_components.erase(_components.begin() + i);
			// delete the pointer
			delete aux;
			// update flag
			found = true;
		}
		else
		// keep searching
			i++;
	}
}

void Entity::Update() 
{
	// update each component of the entity
	for (int i = 0; i < _components.size(); i++)
		_components.at(i)->Update();
}