// Events.hpp

#ifndef __SDL2_EVENTS_H__
#define __SDL2_EVENTS_H__

// SDL Includes
#include <SDL.h>
// Project Includes
#include <Delegate.hpp>

namespace SDL2
{
	class Events
	{
		public:
			Events();
			~Events();

			bool Poll();
			void Update();

			Delegate<void> OnQuit;
			Delegate<void> OnAppTerminating;
			Delegate<void> OnLowMemory;
			Delegate<void> OnWillEnterBackground;
			Delegate<void> OnDidEnterBackground;
			Delegate<void> OnWillEnterForeground;
			Delegate<void> OnDidEnterForeground;
			Delegate<void> OnWindowEvent;
			Delegate<void> OnSysWMEvent;
			Delegate<void, SDL_Keycode, Uint16, Uint8> OnKeyDown;
			Delegate<void, SDL_Keycode, Uint16, Uint8> OnKeyUp;
			Delegate<void> OnTextEditing;
			Delegate<void> OnTextInput;
			Delegate<void> OnMouseMotion;
			Delegate<void, Uint32, Sint32, Sint32> OnMouseButtonDown;
			Delegate<void, Uint32, Sint32, Sint32> OnMouseButtonUp;
			Delegate<void> OnMouseWheel;
			Delegate<void> OnJoyAxisMotion;
			Delegate<void> OnJoyBallMotion;
			Delegate<void> OnJoyHatMotion;
			Delegate<void> OnJoyBallButtonDown;
			Delegate<void> OnJoyBallButtonUp;
			Delegate<void> OnJoyDeviceAdded;
			Delegate<void> OnJoyDeviceRemoved;
			Delegate<void> OnControllerAxisMotion;
			Delegate<void> OnControllerBallButtonDown;
			Delegate<void> OnControllerBallButtonUp;
			Delegate<void> OnControllerDeviceAdded;
			Delegate<void> OnControllerDeviceRemoved;
			Delegate<void> OnControllerDeviceRemapped;
			Delegate<void> OnFingerDown;
			Delegate<void> OnFingerUp;
			Delegate<void> OnFingerMotion;
			Delegate<void> OnDollarGesture;
			Delegate<void> OnDollarRecord;
			Delegate<void> OnMultiGesture;
			Delegate<void> OnClipboardUpdate;
			Delegate<void> OnDropFile;
			Delegate<void> OnUserEvent;
			Delegate<void> OnUndefined;

		private:
			SDL_Event mEvent;
	};
}

#endif
