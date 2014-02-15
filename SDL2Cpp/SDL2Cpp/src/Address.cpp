// Address.cpp

// Project Includes
#include <SDL2Cpp\Net\Address.hpp>

namespace SDL2
{
	namespace Net
	{
		Address::Address()
		{
			mAddress.host = 0;
			mAddress.port = 0;
		}

		Address::Address(Uint16 pPort)
		{
			if(SDLNet_ResolveHost(&mAddress, NULL, pPort) < 0)
			{
				SDL_Log("[Address::Address] Failed to resolve host: %s", SDLNet_GetError());
				mAddress.host = 0;
				mAddress.port = 0;
			}
		}

		Address::Address(const char* pHost, Uint16 pPort)
		{
			if(SDLNet_ResolveHost(&mAddress, pHost, pPort) < 0)
			{
				SDL_Log("[Address::Address] Failed to resolve host: %s", SDLNet_GetError());
				mAddress.host = 0;
				mAddress.port = 0;
			}
		}

		Address::~Address()
		{
		}

		Uint32 Address::GetHost() const
		{
			return mAddress.host;
		}

		Uint16 Address::GetPort() const
		{
			return mAddress.port;
		}
		
		const char* Address::GetName() const
		{
			return SDLNet_ResolveIP(&mAddress);
		}
		
		void Address::Set(IPaddress pAddress)
		{
			mAddress = pAddress;
		}
	}
}
