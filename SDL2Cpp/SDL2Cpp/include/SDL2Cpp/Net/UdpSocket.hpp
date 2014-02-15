// UdpSocket.hpp

#ifndef __SDL2_NET_UDPSOCKET_H__
#define __SDL2_NET_UDPSOCKET_H__

// STD Includes
#include <string>
// Project Includes
#include <SDL2Cpp\Net\Address.hpp>

namespace SDL2
{
	namespace Net
	{
		class UdpSocket
		{
			public:
				UdpSocket();
				~UdpSocket();
				
				UDPsocket GetC() const;

				bool Open(int pPort, int pSize);
				void Close();
				int Resize(int pSize);
				void Bind();
				void Unbind();
				int Send(const std::string& pMessage, const Address& pAddress);
				int Receive(std::string& pMessage, Address& pAddress);

			private:
				int mSize;
				UDPpacket* mPacket;
				UDPsocket mSocket;
				bool mOpen;
		};
	}
}

#endif
