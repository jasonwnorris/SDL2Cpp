// Window.hpp

#ifndef __SDL2_WINDOW_H__
#define __SDL2_WINDOW_H__

// Project Includes
#include <SDL2Cpp\Surface.hpp>

namespace SDL2
{
	class Window
	{
		public:
			Window(const char* pTitle, int pWidth, int pHeight, Uint32 pFlags);
			~Window();

			SDL_Window* GetC() const;

			void SetTitle(const char* pTitle);
			void SetIcon(const Surface& pSurface);
			void Resize(int pWidth, int pHeight);
			void Focus();
			void Restore();
			void Maximize();
			void Minimize();

		private:
			SDL_Window* mWindow;
	};
}

#endif
