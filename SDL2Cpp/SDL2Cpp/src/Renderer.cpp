// Renderer.cpp

// Project Includes
#include <SDL2Cpp\Renderer.hpp>
#include <SDL2Cpp\Texture.hpp>

namespace SDL2
{
	Renderer::Renderer(const Window& pWindow, int pIndex, Uint32 pFlags)
	{
		// Create the renderer.
		mRenderer = SDL_CreateRenderer(pWindow.GetC(), pIndex, pFlags);
		// Grab current renderer info.
		SDL_GetRendererInfo(mRenderer, &mInfo);
	}

	Renderer::~Renderer()
	{
		// Destroy the renderer.
		SDL_DestroyRenderer(mRenderer);
	}

	SDL_Renderer* Renderer::GetC() const
	{
		// Return C structure.
		return mRenderer;
	}

	int Renderer::SetDrawColor(Uint8 pRed, Uint8 pGreen, Uint8 pBlue, Uint8 pAlpha)
	{
		// Set the draw color.
		int code = SDL_SetRenderDrawColor(mRenderer, pRed, pGreen, pBlue, pAlpha);

		// Check for errors.
		if(code < 0)
			SDL_Log("[Renderer::SetDrawColor] Failed to clear renderer: %s", SDL_GetError());

		return code;
	}

	int Renderer::SetBlendMode(SDL_BlendMode pMode)
	{
		// Set the blend mode.
		int code = SDL_SetRenderDrawBlendMode(mRenderer, pMode);

		// Check for errors.
		if(code < 0)
			SDL_Log("[Renderer::SetBlendMode] Failed to clear renderer: %s", SDL_GetError());

		return code;
	}

	int Renderer::Clear()
	{
		// Clear the renderer.
		int code = SDL_RenderClear(mRenderer);

		// Check for errors.
		if(code < 0)
			SDL_Log("[Renderer::Clear] Failed to clear renderer: %s", SDL_GetError());

		return code;
	}
	
	int Renderer::Draw(const Texture& pTexture, const Rectangle& pDestinationRectangle)
	{
		// Draw a texture.
		int code = SDL_RenderCopy(mRenderer, pTexture.GetC(), NULL, &pDestinationRectangle.GetC());

		// Check for errors.
		if(code < 0)
			SDL_Log("[Renderer::Draw] Failed to draw texture: %s", SDL_GetError());

		return code;
	}
	
	int Renderer::Draw(const Texture& pTexture, const Rectangle& pDestinationRectangle, const Rectangle& pSourceRectangle)
	{
		// Draw a texture.
		int code = SDL_RenderCopy(mRenderer, pTexture.GetC(), &pSourceRectangle.GetC(), &pDestinationRectangle.GetC());

		// Check for errors.
		if(code < 0)
			SDL_Log("[Renderer::Draw] Failed to draw texture: %s", SDL_GetError());

		return code;
	}

	int Renderer::DrawLine(int pX1, int pY1, int pX2, int pY2)
	{
		// Draw a line.
		int code = SDL_RenderDrawLine(mRenderer, pX1, pY1, pX2, pY2);

		// Check for errors.
		if(code < 0)
			SDL_Log("[Renderer::DrawLine] Failed to draw line: %s", SDL_GetError());

		return code;
	}

	int Renderer::DrawRectangle(const Rectangle& pRectangle, bool pFill)
	{
		int code = 0;

		// Draw a rectangle.
		if(pFill)
			code = SDL_RenderFillRect(mRenderer, &pRectangle.GetC());
		else
			code = SDL_RenderDrawRect(mRenderer, &pRectangle.GetC());

		// Check for errors.
		if(code < 0)
			SDL_Log("[Renderer::DrawRectangle] Failed to %s rectangle: %s", (pFill ? "fill" : "draw"), SDL_GetError());

		return code;
	}

	void Renderer::Show()
	{
		// Show renderer to the screen.
		SDL_RenderPresent(mRenderer);
	}
}
