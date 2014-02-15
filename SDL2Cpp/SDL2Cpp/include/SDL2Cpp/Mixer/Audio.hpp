// Font.hpp

#ifndef __SDL2_AUDIO_AUDIO_H__
#define __SDL2_AUDIO_AUDIO_H__

// SDL Includes
#include <SDL.h>
// Project Includes
#include <SDL2Cpp\Mixer\Music.hpp>
#include <SDL2Cpp\Mixer\SoundEffect.hpp>

namespace SDL2
{
	namespace Mixer
	{
		class Audio
		{
			public:
				static bool Initialize();
				static void Finalize();
				static bool Open(int pFrequency = MIX_DEFAULT_FREQUENCY, Uint16 pFormat = MIX_DEFAULT_FORMAT, int pChannels = 2, int pChuckSize = 1024);
				static void Close();

			private:
				static bool sInitialized;
				static bool sOpened;
		};
	}
}

#endif
