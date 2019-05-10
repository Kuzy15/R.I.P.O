#ifndef RENDER_COMPONENT_H
#define RENDER_COMPONENT_H

#include <Component.h>
#include "TransformComponent.h"

class RenderComponent :
	public Component
{
public:
	RenderComponent();
	~RenderComponent();

	void virtual Init(std::map<std::string, Arguments> arguments, Entity* e);
	void virtual OnEvent(int eventType, Event * e);
	void virtual Update(float deltaTime);

	//Ogre::SceneNode* GetNode();

private:

	//TransformComponent * _transform = nullptr;

	//Ogre::SceneNode* _entityNode = nullptr;
	Ogre::Entity * _entityOgre;


	bool _mustMove;

	float _auxPosX;
	float _auxPosY;
	float _auxPosZ;


};

#endif RENDER_COMPONENT_H
