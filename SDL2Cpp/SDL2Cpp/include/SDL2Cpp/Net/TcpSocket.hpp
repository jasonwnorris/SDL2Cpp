// TcpSocket.hpp

#ifndef __SDL2_NET_TCPSOCKET_H__
#define __SDL2_NET_TCPSOCKET_H__

// SDL Includes
#include <SDL_net.h>

namespace SDL2
{
	namespace Net
	{
		class TcpSocket
		{
			public:
				TcpSocket();
				~TcpSocket();
				
				TCPsocket GetC() const;

				bool Open(const char* pAddress, int pPort);
				void Close();
				bool Accept();
				bool Send(const void* pData, int pLength);
				bool Receive(void* pData, int pLength);
				void GetPeerAddress(const TcpSocket& pSocket);

			private:
				TCPsocket mSocket;
		};
	}
}

#endif
