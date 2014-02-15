// Mouse.hpp

#ifndef __SDL2_MOUSE_H__
#define __SDL2_MOUSE_H__

// Project Includes
#include <SDL2Cpp\Events.hpp>

namespace SDL2
{
	class Mouse
	{
		friend class Events;

		public:
			static void GetPosition(int& pX, int& pY);
            static void GetMovement(int& pX, int& pY);
            static bool IsButtonDown(int pButton);
            static bool IsButtonUp(int pButton);
            static bool IsButtonClicked(int pButton);
            static bool IsButtonReleased(int pButton);
            static bool IsScrolledUp();
            static bool IsScrolledDown();
			static void Show();
			static void Hide();

		private:
			Mouse();
			~Mouse();

			static void Clear();
			static void SetPosition(int pX, int pY);
			static void SetScroll(int pX, int pY);

            static int sPreviousX;
            static int sCurrentX;
            static int sPreviousY;
            static int sCurrentY;
            static Uint32 sPreviousState;
            static Uint32 sCurrentState;
            static bool sScrollUp;
            static bool sScrollDown;
	};
}

#endif
