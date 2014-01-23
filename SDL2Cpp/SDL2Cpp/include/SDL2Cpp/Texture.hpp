// Texture.hpp

#ifndef __SDL2_TEXTURE_H__
#define __SDL2_TEXTURE_H__

// Project Includes
#include <SDL2Cpp\Renderer.hpp>
#include <SDL2Cpp\Surface.hpp>

namespace SDL2
{
	class Texture
	{
		public:
			Texture();
			Texture(const Renderer& pRenderer, Uint32 pFormat, int pAccess, int pWidth, int pHeight);
			Texture(const Renderer& pRenderer, const Surface& pSurface);
			Texture(const Renderer& pRenderer, const char* pFilename);
			~Texture();

			SDL_Texture* GetC() const;
			Uint32 GetFormat() const;
			int GetAccess() const;
			int GetWidth() const;
			int GetHeight() const;
			
			bool Create(const Renderer& pRenderer, Uint32 pFormat, int pAccess, int pWidth, int pHeight);
			bool Create(const Renderer& pRenderer, const Surface& pSurface);
			bool Load(const Renderer& pRenderer, const char* pFilename);

		private:
			int Query();

			SDL_Texture* mTexture;
			Uint32 mFormat;
			int mAccess;
			int mWidth;
			int mHeight;
	};
}

#endif
