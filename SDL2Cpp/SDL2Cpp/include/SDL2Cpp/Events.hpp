// Events.hpp

#ifndef __SDL2_EVENTS_H__
#define __SDL2_EVENTS_H__

// SDL Includes
#include <SDL.h>

namespace SDL2
{
	class Events
	{
		public:
			Events();
			~Events();

			void Poll();

			virtual void OnQuit();
			virtual void OnAppTerminating();
			virtual void OnAppLowMemory();
			virtual void OnAppWillEnterBackground();
			virtual void OnAppDidEnterBackground();
			virtual void OnAppWillEnterForeground();
			virtual void OnAppDidEnterForeground();
			virtual void OnWindowEvent();
			virtual void OnSysWMEvent();
			virtual void OnKeyDown(SDL_Keycode pKey, Uint16 pMod, Uint8 pRepeat);
			virtual void OnKeyUp(SDL_Keycode pKey, Uint16 pMod, Uint8 pRepeat);
			virtual void OnTextEditing();
			virtual void OnTextInput();
			virtual void OnMouseMotion(Sint32 pX, Sint32 pY, Sint32 pRelativeX, Sint32 pRelativeY);
			virtual void OnMouseLeftButtonDown(Sint32 pX, Sint32 pY);
			virtual void OnMouseLeftButtonUp(Sint32 pX, Sint32 pY);
			virtual void OnMouseRightButtonDown(Sint32 pX, Sint32 pY);
			virtual void OnMouseRightButtonUp(Sint32 pX, Sint32 pY);
			virtual void OnMouseMiddleButtonDown(Sint32 pX, Sint32 pY);
			virtual void OnMouseMiddleButtonUp(Sint32 pX, Sint32 pY);
			virtual void OnMouseExtra1ButtonDown(Sint32 pX, Sint32 pY);
			virtual void OnMouseExtra1ButtonUp(Sint32 pX, Sint32 pY);
			virtual void OnMouseExtra2ButtonDown(Sint32 pX, Sint32 pY);
			virtual void OnMouseExtra2ButtonUp(Sint32 pX, Sint32 pY);
			virtual void OnMouseWheel(Sint32 pX, Sint32 pY);
			virtual void OnJoyAxisMotion();
			virtual void OnJoyBallMotion();
			virtual void OnJoyHatMotion();
			virtual void OnJoyBallButtonDown();
			virtual void OnJoyBallButtonUp();
			virtual void OnJoyDeviceAdded();
			virtual void OnJoyDeviceRemoved();
			virtual void OnControllerAxisMotion(Uint8 pAxis, Sint16 pValue, SDL_JoystickID pWhich);
			virtual void OnControllerButtonDown(Uint8 pButton, SDL_JoystickID pWhich);
			virtual void OnControllerButtonUp(Uint8 pButton, SDL_JoystickID pWhich);
			virtual void OnControllerDeviceAdded(SDL_JoystickID pWhich);
			virtual void OnControllerDeviceRemoved(SDL_JoystickID pWhich);
			virtual void OnControllerDeviceRemapped(SDL_JoystickID pWhich);
			virtual void OnFingerDown();
			virtual void OnFingerUp();
			virtual void OnFingerMotion();
			virtual void OnDollarGesture();
			virtual void OnDollarRecord();
			virtual void OnMultiGesture();
			virtual void OnClipboardUpdate();
			virtual void OnDropFile();
			virtual void OnUserEvent();
			virtual void OnUndefined();

		private:
			SDL_Event mEvent;
	};
}

#endif
