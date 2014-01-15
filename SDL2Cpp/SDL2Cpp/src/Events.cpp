// Events.cpp

// Project Includes
#include <SDL2Cpp\Events.hpp>
#include <SDL2Cpp\GamePad.hpp>
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

	bool Events::Poll()
	{
		return SDL_PollEvent(&mEvent);
	}

	void Events::Update()
	{
		while (SDL_PollEvent(&mEvent))
		{
			switch (mEvent.type)
			{
				case SDL_QUIT:
					OnQuit.Execute();
					break;
				case SDL_APP_TERMINATING:
					OnAppTerminating.Execute();
					break;
				case SDL_APP_LOWMEMORY:
					OnLowMemory.Execute();
					break;
				case SDL_APP_WILLENTERBACKGROUND:
					OnWillEnterBackground.Execute();
					break;
				case SDL_APP_DIDENTERBACKGROUND:
					OnDidEnterBackground.Execute();
					break;
				case SDL_APP_WILLENTERFOREGROUND:
					OnWillEnterForeground.Execute();
					break;
				case SDL_APP_DIDENTERFOREGROUND:
					OnDidEnterForeground.Execute();
					break;
				case SDL_WINDOWEVENT:
					OnWindowEvent.Execute();
					break;
				case SDL_SYSWMEVENT:
					OnSysWMEvent.Execute();
					break;
				case SDL_KEYDOWN:
					OnKeyDown.Execute(mEvent.key.keysym.sym, mEvent.key.keysym.mod, mEvent.key.repeat);
					Keyboard::SetKey(mEvent.key.keysym.sym, true);
					break;
				case SDL_KEYUP:
					OnKeyUp.Execute(mEvent.key.keysym.sym, mEvent.key.keysym.mod, mEvent.key.repeat);
					Keyboard::SetKey(mEvent.key.keysym.sym, false);
					break;
				case SDL_TEXTEDITING:
					OnTextEditing.Execute();
					break;
				case SDL_TEXTINPUT:
					OnTextInput.Execute();
					break;
				case SDL_MOUSEMOTION:
					OnMouseMotion.Execute();
					break;
				case SDL_MOUSEBUTTONDOWN:
					OnMouseButtonDown.Execute(mEvent.button.which, mEvent.button.x, mEvent.button.y);
					break;
				case SDL_MOUSEBUTTONUP:
					OnMouseButtonUp.Execute(mEvent.button.which, mEvent.button.x, mEvent.button.y);
					break;
				case SDL_MOUSEWHEEL:
					OnMouseWheel.Execute();
					break;
				case SDL_JOYAXISMOTION:
					OnJoyAxisMotion.Execute();
					break;
				case SDL_JOYBALLMOTION:
					OnJoyBallMotion.Execute();
					break;
				case SDL_JOYHATMOTION:
					OnJoyHatMotion.Execute();
					break;
				case SDL_JOYBUTTONDOWN:
					OnJoyBallButtonDown.Execute();
					break;
				case SDL_JOYBUTTONUP:
					OnJoyBallButtonUp.Execute();
					break;
				case SDL_JOYDEVICEADDED:
					OnJoyDeviceAdded.Execute();
					break;
				case SDL_JOYDEVICEREMOVED:
					OnJoyDeviceRemoved.Execute();
					break;
				case SDL_CONTROLLERAXISMOTION:
					OnControllerAxisMotion.Execute();
					break;
				case SDL_CONTROLLERBUTTONDOWN:
					OnControllerBallButtonDown.Execute();
					break;
				case SDL_CONTROLLERBUTTONUP:
					OnControllerBallButtonUp.Execute();
					break;
				case SDL_CONTROLLERDEVICEADDED:
					OnControllerDeviceAdded.Execute();
					break;
				case SDL_CONTROLLERDEVICEREMOVED:
					OnControllerDeviceRemoved.Execute();
					break;
				case SDL_CONTROLLERDEVICEREMAPPED:
					OnControllerDeviceRemapped.Execute();
					break;
				case SDL_FINGERDOWN:
					OnFingerDown.Execute();
					break;
				case SDL_FINGERUP:
					OnFingerUp.Execute();
					break;
				case SDL_FINGERMOTION:
					OnFingerMotion.Execute();
					break;
				case SDL_DOLLARGESTURE:
					OnDollarGesture.Execute();
					break;
				case SDL_DOLLARRECORD:
					OnDollarRecord.Execute();
					break;
				case SDL_MULTIGESTURE:
					OnMultiGesture.Execute();
					break;
				case SDL_CLIPBOARDUPDATE:
					OnClipboardUpdate.Execute();
					break;
				case SDL_DROPFILE:
					OnDropFile.Execute();
					break;
				case SDL_USEREVENT:
					OnUserEvent.Execute();
					break;
				default:
					OnUndefined.Execute();
					break;
			}
		}
	}
}
