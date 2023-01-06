#include "game_main.h"

#include "system.h"
#include "debug.h"
#include <stdlib.h>

void GameLoop()
{
	static int i = 0;

	SDL_SetRenderDrawColor(sys::mainRenderer, 0, 0, 0, 255);
	SDL_RenderClear(sys::mainRenderer);
	
	debug::DrawFrameRateDisplay(i);

	i++;
}
