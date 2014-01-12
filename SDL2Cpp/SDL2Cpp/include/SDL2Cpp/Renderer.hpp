// Renderer.hpp

#ifndef __SDL2_RENDERER_H__
#define __SDL2_RENDERER_H__

// Project Includes
#include <SDL2Cpp\Rectangle.hpp>
#include <SDL2Cpp\Window.hpp>

namespace SDL2
{
	class Texture;

	class Renderer
	{
		public:
			Renderer(const Window& pWindow, int pIndex, Uint32 pFlags);
			~Renderer();

			SDL_Renderer* GetC() const;

			int SetDrawColor(Uint8 pRed, Uint8 pGreen, Uint8 pBlue, Uint8 pAlpha);
			int SetBlendMode(SDL_BlendMode pMode);

			int Clear();
			int Draw(const Texture& pTexture, const Rectangle& pDestinationRectangle);
			int Draw(const Texture& pTexture, const Rectangle& pDestinationRectangle, const Rectangle& pSourceRectangle);
			int DrawLine(int pX1, int pY1, int pX2, int pY2);
			int DrawRectangle(const Rectangle& pRectangle, bool pFill = false);
			void Show();

		private:
			SDL_Renderer* mRenderer;
			SDL_RendererInfo mInfo;
	};
}

#endif
