// Net.hpp

#ifndef __SDL2_NET_NET_H__
#define __SDL2_NET_NET_H__

// Project Includes
#include <SDL2Cpp\Net\Address.hpp>
#include <SDL2Cpp\Net\SocketSet.hpp>
#include <SDL2Cpp\Net\TcpSocket.hpp>
#include <SDL2Cpp\Net\UdpSocket.hpp>

namespace SDL2
{
	namespace Net
	{		
		bool Initialize()
		{
			int code = SDLNet_Init();
			if(code < 0)
				SDL_Log("Failed initialize SDL2_Net: %s", SDLNet_GetError());

			return code == 0;
		}

		void Finalize()
		{
			SDLNet_Quit();
		}
	}
}

#endif
