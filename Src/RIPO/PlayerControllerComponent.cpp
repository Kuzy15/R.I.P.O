#include "PlayerControllerComponent.h"

// singleton
#include <EntityManager.h>

// events from ripo
#include "RIPOEvent.h"
#include "../Ogre/CameraManager.h"
//Constructors
PlayerControllerComponent::PlayerControllerComponent() : Component() { }

PlayerControllerComponent::~PlayerControllerComponent(){}

void PlayerControllerComponent::Init(std::map<std::string, Arguments> arguments, Entity * e)
{

	_ownerEntity = e;
	_id = "PlayerController";

	_velocity = arguments["vel"].f;

	_transform = dynamic_cast<TransformComponent*>(_ownerEntity->GetComponent("Transform")); 
	
	_posX = _transform->GetPosX();
	_orPosX = _posX;
	_posY = _transform->GetPosY();
	_orPosY = _posY;
	_posZ = _transform->GetPosZ();
	_orPosZ = _posZ;
}

void PlayerControllerComponent::OnEvent(int eventType, Event e)
{

	if ("DeathEvent" == typeid(e).name()) 
	{
		ResetPosition();
		_death = true;

	}

	else if (EventType::EVENT_W == eventType)
	{
		//ForwardMovement();
		_forward = true;
	}

	else if (EventType::EVENT_A == eventType)
	{
		//LeftMovement();
		_left = true;
	}

	else if (EventType::EVENT_S == eventType)
	{
		//BackMovement();
		_back = true;
	}

	else if (EventType::EVENT_D == eventType)
	{
		//RightMovement();
		_right = true;
	}

	else if ("MouseMoveEvent" == typeid(e).name()) 
	{
		CameraMovement();
	}
	
}

void PlayerControllerComponent::Update(float deltaTime)
{

	if (_forward) ForwardMovement(deltaTime);
	if (_back) BackMovement(deltaTime);
	if (_right) RightMovement(deltaTime);
	if (_left) LeftMovement(deltaTime);
}


void PlayerControllerComponent::ForwardMovement(float deltaTime)
{
	//_posZ -= _velocity;
	_posZ -= deltaTime * _velocity;
	_transform->SetPosition(_posX, _posY, _posZ);
	CameraManager::GetInstance().MoveForward(deltaTime);
	_forward = false;

}

void PlayerControllerComponent::LeftMovement(float deltaTime)
{
	//_posX += _velocity;
	_posX += deltaTime * _velocity;
	_transform->SetPosition(_posX, _posY, _posZ);
	CameraManager::GetInstance().MoveLeft(deltaTime);
	_left = false;
}

void PlayerControllerComponent::BackMovement(float deltaTime)
{
	//_posZ += _velocity;
	_posZ += deltaTime * _velocity;
	_transform->SetPosition(_posX, _posY, _posZ);
	CameraManager::GetInstance().MoveBack(deltaTime);
	_back = false;
}

void PlayerControllerComponent::RightMovement(float deltaTime)
{
	//_posX -= _velocity;
	_posX -= deltaTime * _velocity;
	_transform->SetPosition(_posX, _posY, _posZ);
	CameraManager::GetInstance().MoveRight(deltaTime);
	_right = false;
}

void PlayerControllerComponent::CameraMovement()
{
	//TODO
}

void PlayerControllerComponent::ResetPosition()
{
	_posX = _orPosX;
	_posY = _orPosY;
	_posZ = _orPosZ;

	_transform->SetPosition(_posX, _posY, _posZ);
}

