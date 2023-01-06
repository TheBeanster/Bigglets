#include "big.h"

#include <iostream>
#include "system.h"
#include "game_main.h"



int BigMain()
{
	using namespace sys;

	if (!InitSystem()) return 1;

	if (!GameInit()) return 2;
	
	std::clog << "Entering main loop\n";

	// Main program loop
	while (!(current_windowInput & WINDOWINPUT_QUIT))
	{
		UpdateInputs();

		SDL_SetRenderTarget(mainRenderer, mainTexture);

		GameLoop();

		GameRender();

		SDL_SetRenderTarget(mainRenderer, NULL);
		SDL_RenderCopy(mainRenderer, mainTexture, NULL, NULL);
		SDL_RenderPresent(mainRenderer);
	}

	GameQuit();

	sys::QuitSystem();



	return 0;
}
