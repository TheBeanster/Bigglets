#include "system.h"



namespace sys
{



char current_windowInput = 0;

unsigned char* current_keyboardInput = nullptr;

int mousePositionX = 0;
int mousePositionY = 0;
bool mouseButtonDownLeft = false;
bool mouseButtonDownRight = false;



void UpdateInputs()
{
	// SDL event handler
	SDL_Event e;

	// Reset input registers except the window shown flag
	current_windowInput &= WINDOWINPUT_WINDOWSHOWN;

	while (SDL_PollEvent(&e) != 0)
	{
		switch (e.type)
		{

		case SDL_QUIT:
			current_windowInput |= WINDOWINPUT_QUIT;
			break;

		case SDL_WINDOWEVENT:

			switch (e.window.event)
			{
			case SDL_WINDOWEVENT_SHOWN:
				current_windowInput |= WINDOWINPUT_WINDOWSHOWN;
				break;

			case SDL_WINDOWEVENT_HIDDEN:
				current_windowInput &= ~WINDOWINPUT_WINDOWSHOWN;
				break;
			}

			break;



		case SDL_MOUSEMOTION:
			SDL_GetMouseState(&mousePositionX, &mousePositionY);
			mousePositionX /= (mainWindow_width / (float)screenWidth);
			mousePositionY /= (mainWindow_height / (float)screenHeight);
			break;

		case SDL_MOUSEBUTTONDOWN:
			if (e.button.button == SDL_BUTTON_LEFT)
				mouseButtonDownLeft = true;
			if (e.button.button == SDL_BUTTON_RIGHT)
				mouseButtonDownRight = true;
			break;

		case SDL_MOUSEBUTTONUP:
			if (e.button.button == SDL_BUTTON_LEFT)
				mouseButtonDownLeft = false;
			if (e.button.button == SDL_BUTTON_RIGHT)
				mouseButtonDownRight = false;
			break;

		default:
			break;
		}
	}

	current_keyboardInput = (unsigned char*)SDL_GetKeyboardState(NULL);
}



}