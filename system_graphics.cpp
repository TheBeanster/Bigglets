#include "system.h"

#include <iostream>

namespace sys
{

SDL_Window*		mainWindow		= nullptr;
SDL_Renderer*	mainRenderer	= nullptr;
SDL_Texture*	mainTexture		= nullptr;

int mainWindow_width = 0;
int mainWindow_height = 0;
int screenWidth = 0;
int screenHeight = 0;



bool CreateMainWindow(
	const char* const title,
	int width,
	int height
)
{
	std::clog << "Creating main window\n";

	mainWindow = SDL_CreateWindow(
		title, 
		SDL_WINDOWPOS_CENTERED, 
		SDL_WINDOWPOS_CENTERED, 
		width, 
		height, 
		SDL_WINDOW_SHOWN
	);

	if (mainWindow == nullptr)
	{
		LogSDLError("Main window failed to initialize!");
		return false;
	}

	mainWindow_width = width;
	mainWindow_height = height;

	return true;
}



bool CreateMainRenderer()
{
	std::clog << "Creating main renderer\n";

	mainRenderer = SDL_CreateRenderer(
		mainWindow, 
		-1, 
		SDL_RENDERER_ACCELERATED | 
		SDL_RENDERER_PRESENTVSYNC | 
		SDL_RENDERER_TARGETTEXTURE
	);

	if (mainRenderer == nullptr)
	{
		LogSDLError("Main renderer failed to initialize!");
		return false;
	}

	return true;
}



bool CreateMainTexture(int width, int height)
{
	std::clog << "Creating main texture\n";

	mainTexture = SDL_CreateTexture(
		mainRenderer,
		SDL_PIXELFORMAT_RGB888,
		SDL_TEXTUREACCESS_TARGET,
		width,
		height
	);

	std::clog << "Dimensions of the texture : " << width << ", " << height << '\n';

	if (mainTexture == nullptr)
	{
		LogSDLError("Main texture failed to initialize!");
		return false;
	}

	screenWidth = width;
	screenHeight = height;

	return true;
}





bool InitGraphics()
{
	if (SDL_InitSubSystem(SDL_INIT_VIDEO) < 0) goto onerror;
	if (!CreateMainWindow("Bigglets", 640, 480)) goto onerror;
	if (!CreateMainRenderer()) goto onerror;
	if (!CreateMainTexture(320, 240)) goto onerror;

	return true;

onerror:

	return false;
}



void QuitGraphics()
{

}



}