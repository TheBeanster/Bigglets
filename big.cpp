#include "big.h"

#include <iostream>
#include "system.h"



int BigMain()
{
	using namespace sys;

	if (!InitSystem()) return 1;


	
	std::clog << "Entering main loop\n";

	// Main program loop
	while (!(current_windowInput & WINDOWINPUT_QUIT))
	{
		UpdateInputs();

		SDL_SetRenderTarget(mainRenderer, mainTexture);

		SDL_SetRenderDrawColor(mainRenderer, 0, 0, 0, 255);
		SDL_RenderClear(mainRenderer);

		SDL_SetRenderTarget(mainRenderer, NULL);
		SDL_RenderCopy(mainRenderer, mainTexture, NULL, NULL);
		SDL_RenderPresent(mainRenderer);
	}



	sys::QuitSystem();



	return 0;
}
