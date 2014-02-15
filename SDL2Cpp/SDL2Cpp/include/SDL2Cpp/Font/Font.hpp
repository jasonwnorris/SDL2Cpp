// Font.hpp

#ifndef __SDL2_TTF_FONT_H__
#define __SDL2_TTF_FONT_H__

// SDL Includes
#include <SDL_ttf.h>

namespace SDL2
{
	namespace Font
	{		
		bool Initialize()
		{
			int code = TTF_Init();
			if(code < 0)
				SDL_Log("Failed initialize SDL2_Ttf: %s", TTF_GetError());

			return code == 0;
		}

		void Finalize()
		{
			TTF_Quit();
		}
	}
}

#endif
