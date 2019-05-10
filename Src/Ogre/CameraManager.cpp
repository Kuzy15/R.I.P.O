#include "CameraManager.h"
#include <iostream>
CameraManager* CameraManager::_instance = nullptr;

void CameraManager::AttachPlayer(Ogre::SceneNode * playerNode)
{

	playerNode->addChild(_camNode);
	_player = playerNode;
}

CameraManager::CameraManager()
{
}

CameraManager::~CameraManager()
{
	if (_mainCamera )
	{
		delete _mainCamera;
		_mainCamera = nullptr;
	}
	if (_camNode != nullptr)
	{
		delete _camNode;
		_camNode = nullptr;
	}
}

void CameraManager::CreateCamera(Ogre::RenderWindow * window, Ogre::SceneManager * sceneMgr)
{
	//TESTING creates a node for player
	_player = sceneMgr->getRootSceneNode()->createChildSceneNode();
	_player->setPosition(Ogre::Vector3(-80, 10, 5));

	//add a camera
	_camera = sceneMgr->createCamera("FPScam");
	_camNode = _player->createChildSceneNode();

	_camera->lookAt(Ogre::Vector3(0, 0, 0));
	_camera->setNearClipDistance(5);
	_camera->setFarClipDistance(10000);

	_camNode->attachObject(_camera);

	_player->pitch(Ogre::Radian(-1.573f));
	_player->roll(Ogre::Radian(3.14f));

	// add viewport
	_viewPort = window->addViewport(_camera);
	_viewPort->setAutoUpdated(true);
}



void CameraManager::FPSrotation(float time, Ogre::Real mouseX, Ogre::Real mouseY)
{
	//Y axis rotation on player
	_rotY = -mouseX;
	_player->yaw(Ogre::Degree(_rotY) * _rotSpeed * time);

	//X axis rotation on player
	_rotX = -mouseY;
	Ogre::Real nextPitch = _camNode->getOrientation().getPitch().valueDegrees() + _rotX;

	//check if max camera height has been reached
	if (nextPitch > -_maxPitch && nextPitch < _maxPitch)
		_camNode->pitch(Ogre::Degree(_rotX) * _rotSpeed* time);

}

CameraManager & CameraManager::GetInstance()
{
	if (_instance == nullptr)
		_instance = new CameraManager();
	return *CameraManager::_instance;

}

void CameraManager::ResetInstance()
{
	if (_instance != nullptr)
	{
		delete _instance;
		_instance = nullptr;
	}
}

/*void CameraManager::MoveForward(Ogre::Real time)
{

	Ogre::Vector3 vt(0, 0, 0);

	vt += Ogre::Vector3(0, 0, -1);

	_player->translate(vt * time * _speed, Ogre::Node::TS_LOCAL);

}

void CameraManager::MoveBack(Ogre::Real time)
{

	Ogre::Vector3 vt(0, 0, 0);

	vt += Ogre::Vector3(0, 0, 1);

	_player->translate(vt * time * _speed, Ogre::Node::TS_LOCAL);

}

void CameraManager::MoveRight(Ogre::Real time)
{

	Ogre::Vector3 vt(0, 0, 0);

	vt += Ogre::Vector3(1, 0, 0);

	_player->translate(vt * time * _speed, Ogre::Node::TS_LOCAL);

}

void CameraManager::MoveLeft(Ogre::Real time)
{

	Ogre::Vector3 vt(0, 0, 0);

	vt += Ogre::Vector3(-1, 0, 0);

	_player->translate(vt * time * _speed, Ogre::Node::TS_LOCAL);

}*/

void CameraManager::CameraMove(Ogre::Vector3 pos)
{
	_player->setPosition(pos);
}

