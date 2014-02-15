// Events.cpp

// Project Includes
#include <SDL2Cpp\Events.hpp>
#include <SDL2Cpp\GamePad.hpp>
#include <SDL2Cpp\Joystick.hpp>
#include <SDL2Cpp\Keyboard.hpp>
#include <SDL2Cpp\Mouse.hpp>

namespace SDL2
{
	Events::Events()
	{
	}

	Events::~Events()
	{
	}

	void Events::Poll()
	{
		GamePad::Clear();
		Joystick::Clear();
		Keyboard::Clear();
		Mouse::Clear();

		while (SDL_PollEvent(&mEvent))
		{
			switch (mEvent.type)
			{
				case SDL_QUIT:
					OnQuit();
					break;
				case SDL_APP_TERMINATING:
					OnAppTerminating();
					break;
				case SDL_APP_LOWMEMORY:
					OnAppLowMemory();
					break;
				case SDL_APP_WILLENTERBACKGROUND:
					OnAppWillEnterBackground();
					break;
				case SDL_APP_DIDENTERBACKGROUND:
					OnAppDidEnterBackground();
					break;
				case SDL_APP_WILLENTERFOREGROUND:
					OnAppWillEnterForeground();
					break;
				case SDL_APP_DIDENTERFOREGROUND:
					OnAppDidEnterForeground();
					break;
				case SDL_WINDOWEVENT:
					OnWindowEvent();
					break;
				case SDL_SYSWMEVENT:
					OnSysWMEvent();
					break;
				case SDL_KEYDOWN:
					OnKeyDown(mEvent.key.keysym.sym, mEvent.key.keysym.mod, mEvent.key.repeat);
					Keyboard::SetKey(mEvent.key.keysym.sym, true);
					break;
				case SDL_KEYUP:
					OnKeyUp(mEvent.key.keysym.sym, mEvent.key.keysym.mod, mEvent.key.repeat);
					Keyboard::SetKey(mEvent.key.keysym.sym, false);
					break;
				case SDL_TEXTEDITING:
					OnTextEditing();
					break;
				case SDL_TEXTINPUT:
					OnTextInput();
					break;
				case SDL_MOUSEMOTION:
					OnMouseMotion(mEvent.motion.x, mEvent.motion.y, mEvent.motion.xrel, mEvent.motion.yrel);
					Mouse::SetPosition(mEvent.motion.x, mEvent.motion.y);
					break;
				case SDL_MOUSEBUTTONDOWN:
					switch(mEvent.button.button)
					{
						case SDL_BUTTON_LEFT:
							OnMouseLeftButtonDown(mEvent.button.x, mEvent.button.y);
							break;
						case SDL_BUTTON_RIGHT:
							OnMouseRightButtonDown(mEvent.button.x, mEvent.button.y);
							break;
						case SDL_BUTTON_MIDDLE:
							OnMouseMiddleButtonDown(mEvent.button.x, mEvent.button.y);
							break;
						case SDL_BUTTON_X1:
							OnMouseLeftButtonDown(mEvent.button.x, mEvent.button.y);
							break;
						case SDL_BUTTON_X2:
							OnMouseLeftButtonDown(mEvent.button.x, mEvent.button.y);
							break;
					}
					break;
				case SDL_MOUSEBUTTONUP:
					switch(mEvent.button.button)
					{
						case SDL_BUTTON_LEFT:
							OnMouseLeftButtonUp(mEvent.button.x, mEvent.button.y);
							break;
						case SDL_BUTTON_RIGHT:
							OnMouseRightButtonUp(mEvent.button.x, mEvent.button.y);
							break;
						case SDL_BUTTON_MIDDLE:
							OnMouseMiddleButtonUp(mEvent.button.x, mEvent.button.y);
							break;
						case SDL_BUTTON_X1:
							OnMouseLeftButtonUp(mEvent.button.x, mEvent.button.y);
							break;
						case SDL_BUTTON_X2:
							OnMouseLeftButtonUp(mEvent.button.x, mEvent.button.y);
							break;
					}
					break;
				case SDL_MOUSEWHEEL:
					OnMouseWheel(mEvent.wheel.x, mEvent.wheel.y);
					Mouse::SetScroll(mEvent.wheel.x, mEvent.wheel.y);
					break;
				case SDL_JOYAXISMOTION:
					OnJoyAxisMotion();
					break;
				case SDL_JOYBALLMOTION:
					OnJoyBallMotion();
					break;
				case SDL_JOYHATMOTION:
					OnJoyHatMotion();
					break;
				case SDL_JOYBUTTONDOWN:
					OnJoyBallButtonDown();
					break;
				case SDL_JOYBUTTONUP:
					OnJoyBallButtonUp();
					break;
				case SDL_JOYDEVICEADDED:
					OnJoyDeviceAdded();
					break;
				case SDL_JOYDEVICEREMOVED:
					OnJoyDeviceRemoved();
					break;
				case SDL_CONTROLLERAXISMOTION:
					OnControllerAxisMotion(mEvent.caxis.axis, mEvent.caxis.value, mEvent.caxis.which);
					GamePad::SetAxis(mEvent.caxis.axis, mEvent.caxis.value, mEvent.caxis.which);
					break;
				case SDL_CONTROLLERBUTTONDOWN:
					OnControllerButtonDown(mEvent.cbutton.button, mEvent.cbutton.which);
					GamePad::SetButton(mEvent.cbutton.button, true, mEvent.cbutton.which);
					break;
				case SDL_CONTROLLERBUTTONUP:
					OnControllerButtonUp(mEvent.cbutton.button, mEvent.cbutton.which);
					GamePad::SetButton(mEvent.cbutton.button, false, mEvent.cbutton.which);
					break;
				case SDL_CONTROLLERDEVICEADDED:
					OnControllerDeviceAdded(mEvent.cdevice.which);
					GamePad::Add(mEvent.cdevice.which);
					break;
				case SDL_CONTROLLERDEVICEREMOVED:
					OnControllerDeviceRemoved(mEvent.cdevice.which);
					GamePad::Remove(mEvent.cdevice.which);
					break;
				case SDL_CONTROLLERDEVICEREMAPPED:
					OnControllerDeviceRemapped(mEvent.cdevice.which);
					break;
				case SDL_FINGERDOWN:
					OnFingerDown();
					break;
				case SDL_FINGERUP:
					OnFingerUp();
					break;
				case SDL_FINGERMOTION:
					OnFingerMotion();
					break;
				case SDL_DOLLARGESTURE:
					OnDollarGesture();
					break;
				case SDL_DOLLARRECORD:
					OnDollarRecord();
					break;
				case SDL_MULTIGESTURE:
					OnMultiGesture();
					break;
				case SDL_CLIPBOARDUPDATE:
					OnClipboardUpdate();
					break;
				case SDL_DROPFILE:
					OnDropFile();
					break;
				case SDL_USEREVENT:
					OnUserEvent();
					break;
				default:
					OnUndefined();
					break;
			}
		}
	}

	void Events::OnQuit() { }
	void Events::OnAppTerminating() { }
	void Events::OnAppLowMemory() { }
	void Events::OnAppWillEnterBackground() { }
	void Events::OnAppDidEnterBackground() { }
	void Events::OnAppWillEnterForeground() { }
	void Events::OnAppDidEnterForeground() { }
	void Events::OnWindowEvent() { }
	void Events::OnSysWMEvent() { }
	void Events::OnKeyDown(SDL_Keycode pKey, Uint16 pMod, Uint8 pRepeat) { }
	void Events::OnKeyUp(SDL_Keycode pKey, Uint16 pMod, Uint8 pRepeat) { }
	void Events::OnTextEditing() { }
	void Events::OnTextInput() { }
	void Events::OnMouseMotion(Sint32 pX, Sint32 pY, Sint32 pRelativeX, Sint32 pRelativeY) { }
	void Events::OnMouseLeftButtonDown(Sint32 pX, Sint32 pY) { }
	void Events::OnMouseLeftButtonUp(Sint32 pX, Sint32 pY) { }
	void Events::OnMouseRightButtonDown(Sint32 pX, Sint32 pY) { }
	void Events::OnMouseRightButtonUp(Sint32 pX, Sint32 pY) { }
	void Events::OnMouseMiddleButtonDown(Sint32 pX, Sint32 pY) { }
	void Events::OnMouseMiddleButtonUp(Sint32 pX, Sint32 pY) { }
	void Events::OnMouseExtra1ButtonDown(Sint32 pX, Sint32 pY) { }
	void Events::OnMouseExtra1ButtonUp(Sint32 pX, Sint32 pY) { }
	void Events::OnMouseExtra2ButtonDown(Sint32 pX, Sint32 pY) { }
	void Events::OnMouseExtra2ButtonUp(Sint32 pX, Sint32 pY) { }
	void Events::OnMouseWheel(Sint32 pX, Sint32 pY) { }
	void Events::OnJoyAxisMotion() { }
	void Events::OnJoyBallMotion() { }
	void Events::OnJoyHatMotion() { }
	void Events::OnJoyBallButtonDown() { }
	void Events::OnJoyBallButtonUp() { }
	void Events::OnJoyDeviceAdded() { }
	void Events::OnJoyDeviceRemoved() { }
	void Events::OnControllerAxisMotion(Uint8 pAxis, Sint16 pValue, SDL_JoystickID pWhich) { }
	void Events::OnControllerButtonDown(Uint8 pButton, SDL_JoystickID pWhich) { }
	void Events::OnControllerButtonUp(Uint8 pButton, SDL_JoystickID pWhich) { }
	void Events::OnControllerDeviceAdded(SDL_JoystickID pWhich) { }
	void Events::OnControllerDeviceRemoved(SDL_JoystickID pWhich) { }
	void Events::OnControllerDeviceRemapped(SDL_JoystickID pWhich) { }
	void Events::OnFingerDown() { }
	void Events::OnFingerUp() { }
	void Events::OnFingerMotion() { }
	void Events::OnDollarGesture() { }
	void Events::OnDollarRecord() { }
	void Events::OnMultiGesture() { }
	void Events::OnClipboardUpdate() { }
	void Events::OnDropFile() { }
	void Events::OnUserEvent() { }
	void Events::OnUndefined() { }
}
