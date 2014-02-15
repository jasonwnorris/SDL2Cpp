// SocketSet.hpp

#ifndef __SDL2_NET_SOCKETSET_H__
#define __SDL2_NET_SOCKETSET_H__

// Project Includes
#include <SDL2Cpp\Net\TcpSocket.hpp>
#include <SDL2Cpp\Net\UdpSocket.hpp>

namespace SDL2
{
	namespace Net
	{
		class SocketSet
		{
			public:
				SocketSet(int pSize);
				~SocketSet();

				SDLNet_SocketSet GetC() const;
				
				bool Add(const TcpSocket& pSocket);
				bool Add(const UdpSocket& pSocket);
				bool Remove(const TcpSocket& pSocket);
				bool Remove(const UdpSocket& pSocket);
				int Check(Uint32 pTimeout = -1);
				bool IsReady(const TcpSocket& pSocket);
				bool IsReady(const UdpSocket& pSocket);

			private:
				int mCount;
				int mSize;
				SDLNet_SocketSet mSet;
		};
	}
}

#endif
