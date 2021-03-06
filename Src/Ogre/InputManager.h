#ifndef _H_INPUTMANAGER_H_
#define _H_INPUTMANAGER_H_

//#include "MyOgre.h"
#include <OISMouse.h>
#include <OISKeyboard.h>
#include <OISInputManager.h>
#include <OgreRenderWindow.h>

#include <vector>
//#include <OIS.h>

///<sumary>
//how to get input from another class
//InputManager::GetInstance()->GetKey(OIS::KeyCode::KC_A);
//InputManager::GetInstance()->GetMouseButton(OIS::MouseButtonID::MB_Right);
///<sumary>


	//mouse cursor coordinates
struct mouseCoordinates
{
	float mouseX, mouseY, mouseZ;

};

class InputManager : public OIS::KeyListener, public OIS::MouseListener
{
public:
	~InputManager();

	void CaptureInput();

	bool InitInput(Ogre::RenderWindow* rw); //InputManager initialisation

	static InputManager& GetInstance();

	void ResizeWindow(Ogre::RenderWindow* rw);

	static void ResetInstance();

	bool IsKeyDown(OIS::KeyCode);

	bool IsMouseButtonPressed(OIS::MouseButtonID);

	mouseCoordinates GetMouseCoords();

	bool GetMouseMove();

private:
	InputManager();

	///InputSystem
	static InputManager* _instance;

	OIS::InputManager* _inputSystem = nullptr;

	Ogre::RenderWindow* _renderWindow = nullptr;
	OIS::ParamList _pl;
	size_t windowHnd;
	std::ostringstream windowHndStr;

	///KEYBOARD
	OIS::Keyboard* _keyboard = nullptr;

	std::vector<bool> _keyboardKeys;
	bool keyPressed(const OIS::KeyEvent &e);
	bool keyReleased(const OIS::KeyEvent &e);


	///MOUSE
	OIS::Mouse* _mouse = nullptr;

	std::vector<bool> _mouseButtons;
	bool mousePressed(const OIS::MouseEvent &e, OIS::MouseButtonID id);
	bool mouseMoved(const OIS::MouseEvent &e);
	bool mouseReleased(const OIS::MouseEvent &e, OIS::MouseButtonID id);

	bool _mouseMove = false;

	//mouse cursor coordinates
	mouseCoordinates _mousePosition;
};

#endif