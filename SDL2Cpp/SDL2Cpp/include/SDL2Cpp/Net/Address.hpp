// Address.hpp

#ifndef __SDL2_NET_ADDRESS_H__
#define __SDL2_NET_ADDRESS_H__

// Project Includes
#include <SDL_net.h>

namespace SDL2
{
	namespace Net
	{
		class Address
		{
			public:
				Address();
				Address(Uint16 pPort);
				Address(const char* pHost, Uint16 pPort);
				~Address();

				Uint32 GetHost() const;
				Uint16 GetPort() const;
				const char* GetName() const;
				void Set(IPaddress pAddress);

			private:
				IPaddress mAddress;
		};
	}
}

#endif
