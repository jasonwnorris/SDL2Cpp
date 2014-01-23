// Window.cpp

// Project Includes
#include <SDL2Cpp\Window.hpp>

namespace SDL2
{
	Window::Window()
	{
		mWindow = NULL;
	}

	Window::Window(const char* pTitle, int pWidth, int pHeight, Uint32 pFlags)
	{
		Initialize(pTitle, pWidth, pHeight, pFlags);
	}

	Window::~Window()
	{
		// Destroy the window.
		SDL_DestroyWindow(mWindow);
	}

	SDL_Window* Window::GetC() const
	{
		// Return C structure.
		return mWindow;
	}

	void Window::Initialize(const char* pTitle, int pWidth, int pHeight, Uint32 pFlags)
	{
		// Create the window.
		mWindow = SDL_CreateWindow(pTitle, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, pWidth, pHeight, pFlags);
	}

	void Window::SetTitle(const char* pTitle)
	{
		SDL_SetWindowTitle(mWindow, pTitle);
	}

	void Window::SetIcon(const Surface& pSurface)
	{
		SDL_SetWindowIcon(mWindow, pSurface.GetC());
	}

	void Window::Resize(int pWidth, int pHeight)
	{
		SDL_SetWindowSize(mWindow, pWidth, pHeight);
	}

	void Window::Show()
	{
		SDL_ShowWindow(mWindow);
	}
	
	void Window::Focus()
	{
		SDL_RaiseWindow(mWindow);
	}

	void Window::Restore()
	{
		SDL_RestoreWindow(mWindow);
	}

	void Window::Maximize()
	{
		SDL_MaximizeWindow(mWindow);
	}

	void Window::Minimize()
	{
		SDL_MinimizeWindow(mWindow);
	}
}
