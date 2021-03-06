#ifndef _H_CAMERAMANAGER_H_
#define _H_CAMERAMANAGER_H_

#include <OgreCamera.h>
#include <OgreSceneNode.h>
#include <Ogre.h>
#include <OgreRenderWindow.h>
#include "InputManager.h"




class CameraManager 
{
public:
	~CameraManager();

	void CreateCamera(Ogre::RenderWindow * window, Ogre::SceneManager * sceneMgr);

	static CameraManager& GetInstance();

	static void ResetInstance();
	
	
	///<sumary>
	///Movement methods to be called from a PlayerController
	///Moves a SceneNode different to _camNode
	///<sumary>


	///<sumary>
	///To be called from a PlayerController, rotates the camara SceneNode
	///<sumary>
	Ogre::Quaternion FPSrotation(float time, Ogre::Real mouseX, Ogre::Real mouseY);

	///<sumary>
	///To be called from a PlayerController, attaches the camera node to a node
	///<sumary>
	void AttachPlayer(std::string mesh, Ogre::SceneNode* playerNode);

	///<sumary>
	///To be called from a PlayerController, getter of the gun position
	///<sumary>
	Ogre::Vector3 GetGunPos();


private:

	CameraManager();

	static CameraManager* _instance;

	//Player node in case camera is attached to a player for the FPS camera functions
	Ogre::SceneNode* _player = nullptr;


	//attributes for FPSrotation
	Ogre::Real _rotX;
	Ogre::Real _rotY;
	Ogre::Real _rotSpeed = 5;
	Ogre::Real _maxPitch = 30;

	Ogre::Real _speed = 5.0;

	Ogre::SceneNode* _camNode = nullptr;
	Ogre::Camera* _camera = nullptr;
	Ogre::Viewport * _viewPort = nullptr;

	//gun mesh to attach to the player node and its position
	std::string _gunMesh;
	Ogre::Vector3 _gunPos;
	
};


#endif // 
