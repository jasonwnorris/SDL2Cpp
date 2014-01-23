// Texture.cpp

// SDL Includes
#include <SDL_image.h>
// Project Includes
#include <SDL2Cpp\Texture.hpp>

namespace SDL2
{
	Texture::Texture()
	{
		mTexture = NULL;
	}

	Texture::Texture(const Renderer& pRenderer, Uint32 pFormat, int pAccess, int pWidth, int pHeight)
	{
		Create(pRenderer, pFormat, pAccess, pWidth, pHeight);
	}

	Texture::Texture(const Renderer& pRenderer, const Surface& pSurface)
	{
		Create(pRenderer, pSurface);
	}
	
	Texture::Texture(const Renderer& pRenderer, const char* pFilename)
	{
		Load(pRenderer, pFilename);
	}

	Texture::~Texture()
	{
		// Destroy the texture.
		SDL_DestroyTexture(mTexture);
	}

	SDL_Texture* Texture::GetC() const
	{
		// Return C structure.
		return mTexture;
	}

	Uint32 Texture::GetFormat() const
	{
		return mFormat;
	}

	int Texture::GetAccess() const
	{
		return mAccess;
	}

	int Texture::GetWidth() const
	{
		return mWidth;
	}

	int Texture::GetHeight() const
	{
		return mHeight;
	}
			
	bool Texture::Create(const Renderer& pRenderer, Uint32 pFormat, int pAccess, int pWidth, int pHeight)
	{
		// Create the texture.
		mTexture = SDL_CreateTexture(pRenderer.GetC(), pFormat, pAccess, pWidth, pHeight);

		return Query() == 0;
	}

	bool Texture::Create(const Renderer& pRenderer, const Surface& pSurface)
	{
		// Create the texture.
		mTexture = SDL_CreateTextureFromSurface(pRenderer.GetC(), pSurface.GetC());

		return Query() == 0;
	}

	bool Texture::Load(const Renderer& pRenderer, const char* pFilename)
	{
		// Create the texture from a loaded image file.
		mTexture = IMG_LoadTexture(pRenderer.GetC(), pFilename);

		return Query() == 0;
	}
	
	int Texture::Query()
	{
		// Query the texture.
		int code = SDL_QueryTexture(mTexture, &mFormat, &mAccess, &mWidth, &mHeight);

		// Check for errors.
		if(code < 0)
			SDL_Log("[Texture::Query] Failed to query texture: %s", SDL_GetError());

		return code;
	}
}
