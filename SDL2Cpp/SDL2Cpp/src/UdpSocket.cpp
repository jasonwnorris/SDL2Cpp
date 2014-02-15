// UdpSocket.cpp

// Project Includes
#include <SDL2Cpp\Net\UdpSocket.hpp>

namespace SDL2
{
	namespace Net
	{
		UdpSocket::UdpSocket()
		{
			mSize = 0;
			mPacket = NULL;
			mSocket = NULL;
			mOpen = false;
		}

		UdpSocket::~UdpSocket()
		{
			SDLNet_FreePacket(mPacket);
			Close();
		}

		UDPsocket UdpSocket::GetC() const
		{
			return mSocket;
		}

		bool UdpSocket::Open(int pPort, int pSize)
		{
			if(!mOpen)
			{
				mSize = pSize;

				mPacket = SDLNet_AllocPacket(mSize);
				if(mPacket == NULL)
				{
					SDL_Log("[UdpSocket::Open] Failed to allocated UDP packet: %s", SDLNet_GetError());
					return false;
				}

				mSocket = SDLNet_UDP_Open(pPort);
				if(mSocket == NULL)
				{
					SDL_Log("[UdpSocket::Open] Failed to UDP socket: %s", SDLNet_GetError());
					return false;
				}

				mOpen = true;
			}

			return true;
		}

		void UdpSocket::Close()
		{
			if(mOpen)
			{
				SDLNet_UDP_Close(mSocket);
				mOpen = false;
			}
		}
		
		int UdpSocket::Resize(int pSize)
		{
			return mSize = SDLNet_ResizePacket(mPacket, pSize);
		}
		
		void UdpSocket::Bind()
		{
		}

		void UdpSocket::Unbind()
		{
		}

		int UdpSocket::Send(const std::string& pMessage, const Address& pAddress)
		{
			mPacket->data = (Uint8*)pMessage.c_str();
			mPacket->len = (int)pMessage.size();
			mPacket->address.host = pAddress.GetHost();
			mPacket->address.port = pAddress.GetPort();

			int code = SDLNet_UDP_Send(mSocket, -1, mPacket);

			if(code == 0)
				SDL_Log("[UdpSocket::Send] Failed to send packets: %s", SDLNet_GetError());

			return code;
		}

		// returns negative on error
		//         positive on success
		//         zero for nothing
		int UdpSocket::Receive(std::string& pMessage, Address& pAddress)
		{
			int code = SDLNet_UDP_Recv(mSocket, mPacket);

			if(code < 0)
			{
				SDL_Log("[UdpSocket::Receive] Failed to receive a packet: %s", SDLNet_GetError());
			}
			else if(code > 0)
			{
				pMessage = std::string((char*)mPacket->data, mPacket->len);
			}

			return code;
		}
	}
}
