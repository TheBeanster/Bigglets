#include "system.h"

#include <iostream>



namespace sys
{



bool InitSystem()
{
	
	if (!InitGraphics()) return false;

	return true;
}

void QuitSystem()
{
}



void LogSDLError(const char* const msg)
{
	if (msg)
	{
		std::cerr << "ERROR! : " << msg << '\n';
	}

	const char* sdlerror = SDL_GetError();
	if (sdlerror)
	{
		std::cerr << "SDL Error : " << sdlerror << '\n';
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "SDL Error", msg, NULL);
	} else
	{
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "SDL Error", msg, NULL);
	}
}



}