// SocketSet.cpp

// Project Includes
#include <SDL2Cpp\Net\SocketSet.hpp>

namespace SDL2
{
	namespace Net
	{
		SocketSet::SocketSet(int pSize)
		{
			mCount = 0;
			mSize = pSize;
			mSet = SDLNet_AllocSocketSet(mSize);
		}

		SocketSet::~SocketSet()
		{
			SDLNet_FreeSocketSet(mSet);
		}

		SDLNet_SocketSet SocketSet::GetC() const
		{
			return mSet;
		}

		bool SocketSet::Add(const TcpSocket& pSocket)
		{
			if(mCount >= mSize)
				return false;

			SDLNet_TCP_AddSocket(mSet, pSocket.GetC());

			++mCount;

			return true;
		}

		bool SocketSet::Add(const UdpSocket& pSocket)
		{
			if(mCount >= mSize)
				return false;

			SDLNet_UDP_AddSocket(mSet, pSocket.GetC());

			++mCount;

			return true;
		}

		bool SocketSet::Remove(const TcpSocket& pSocket)
		{
			if(mCount == 0)
				return false;

			SDLNet_TCP_DelSocket(mSet, pSocket.GetC());

			--mCount;

			return true;
		}

		bool SocketSet::Remove(const UdpSocket& pSocket)
		{
			if(mCount == 0)
				return false;

			SDLNet_UDP_DelSocket(mSet, pSocket.GetC());

			--mCount;

			return true;
		}

		int SocketSet::Check(Uint32 pTimeout)
		{
			return SDLNet_CheckSockets(mSet, pTimeout);
		}

		bool SocketSet::IsReady(const TcpSocket& pSocket)
		{
			return SDLNet_SocketReady(pSocket.GetC()) != 0;
		}

		bool SocketSet::IsReady(const UdpSocket& pSocket)
		{
			return SDLNet_SocketReady(pSocket.GetC()) != 0;
		}
	}
}
