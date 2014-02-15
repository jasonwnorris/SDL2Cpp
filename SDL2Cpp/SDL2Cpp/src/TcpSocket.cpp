// TcpSocket.cpp

// Project Includes
#include <SDL2Cpp\Net\TcpSocket.hpp>

namespace SDL2
{
	namespace Net
	{
		TcpSocket::TcpSocket()
		{
			mSocket = NULL;
		}

		TcpSocket::~TcpSocket()
		{
			Close();
		}

		TCPsocket TcpSocket::GetC() const
		{
			return mSocket;
		}

		bool TcpSocket::Open(const char* pAddress, int pPort)
		{
			IPaddress ip;
			SDLNet_ResolveHost(&ip, pAddress, pPort);

			mSocket = SDLNet_TCP_Open(&ip);

			return mSocket != NULL;
		}

		void TcpSocket::Close()
		{
			SDLNet_TCP_Close(mSocket);
		}

		bool TcpSocket::Accept()
		{
			TCPsocket socket = SDLNet_TCP_Accept(mSocket);

			return socket != NULL;
		}

		bool TcpSocket::Send(const void* pData, int pLength)
		{
			return SDLNet_TCP_Send(mSocket, pData, pLength) < pLength;
		}

		bool TcpSocket::Receive(void* pData, int pLength)
		{
			return SDLNet_TCP_Recv(mSocket, pData, pLength) > 0;
		}
		
		void TcpSocket::GetPeerAddress(const TcpSocket& pSocket)
		{
			IPaddress* remote = SDLNet_TCP_GetPeerAddress(pSocket.GetC());
		}
	}
}
