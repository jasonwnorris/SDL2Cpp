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

			static bool Poll();
			static void Update();

			static Delegate<void> OnQuit;
			static Delegate<void> OnAppTerminating;
			static Delegate<void> OnLowMemory;
			static Delegate<void> OnWillEnterBackground;
			static Delegate<void> OnDidEnterBackground;
			static Delegate<void> OnWillEnterForeground;
			static Delegate<void> OnDidEnterForeground;
			static Delegate<void> OnWindowEvent;
			static Delegate<void> OnSysWMEvent;
			static Delegate<void, SDL_Keycode, Uint16, Uint8> OnKeyDown;
			static Delegate<void, SDL_Keycode, Uint16, Uint8> OnKeyUp;
			static Delegate<void> OnTextEditing;
			static Delegate<void> OnTextInput;
			static Delegate<void> OnMouseMotion;
			static Delegate<void, Uint32, Sint32, Sint32> OnMouseButtonDown;
			static Delegate<void, Uint32, Sint32, Sint32> OnMouseButtonUp;
			static Delegate<void> OnMouseWheel;
			static Delegate<void> OnJoyAxisMotion;
			static Delegate<void> OnJoyBallMotion;
			static Delegate<void> OnJoyHatMotion;
			static Delegate<void> OnJoyBallButtonDown;
			static Delegate<void> OnJoyBallButtonUp;
			static Delegate<void> OnJoyDeviceAdded;
			static Delegate<void> OnJoyDeviceRemoved;
			static Delegate<void> OnControllerAxisMotion;
			static Delegate<void> OnControllerBallButtonDown;
			static Delegate<void> OnControllerBallButtonUp;
			static Delegate<void> OnControllerDeviceAdded;
			static Delegate<void> OnControllerDeviceRemoved;
			static Delegate<void> OnControllerDeviceRemapped;
			static Delegate<void> OnFingerDown;
			static Delegate<void> OnFingerUp;
			static Delegate<void> OnFingerMotion;
			static Delegate<void> OnDollarGesture;
			static Delegate<void> OnDollarRecord;
			static Delegate<void> OnMultiGesture;
			static Delegate<void> OnClipboardUpdate;
			static Delegate<void> OnDropFile;
			static Delegate<void> OnUserEvent;
			static Delegate<void> OnUndefined;

		private:
			static SDL_Event mEvent;
	};
}

#endif
