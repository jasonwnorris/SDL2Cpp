// GamePad.hpp

#ifndef __SDL2_GAMEPAD_H__
#define __SDL2_GAMEPAD_H__

// STL Includes
#include <map>
// Project Includes
#include <SDL2Cpp\Events.hpp>

namespace SDL2
{
	class GamePad
	{
		friend class Events;

		public:
			void Close();
			bool IsButtonDown();
			void GetAxis();
			bool RumbleStart(int pDuration, float pStrength = 1.0f);
			bool RumbleStop();
			bool RumblePause();
			bool RumbleResume();

		private:
			GamePad(int pIndex);
			~GamePad();

			static std::map<int, GamePad*> sGamePads;

			static void Clear();

			static void SetAxis(Uint8 pAxis, Sint16 pValue, int pIndex);
			static void SetButton(Uint8 pButton, bool pState, int pIndex);
			static void Add(int pIndex);
			static void Remove(int pIndex);

			int mIndex;
			SDL_GameController* mController;
			SDL_Haptic* mHaptic;
			std::map<Uint8, bool> sCurrentButtons;
			std::map<Uint8, bool> sPreviousButtons;
	};
}

#endif
