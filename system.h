#pragma once

#include <SDL.h>

namespace sys
{

bool InitSystem();

void QuitSystem();



extern SDL_Window*		mainWindow;
extern SDL_Renderer*	mainRenderer;
extern SDL_Texture*		mainTexture;

extern int mainWindow_width;
extern int mainWindow_height;
extern int screenWidth;
extern int screenHeight;

bool InitGraphics();

void QuitGraphics();




// System input type enum
enum windowInput : char
{
	WINDOWINPUT_MINIMIZE	= 0b00000001,
	WINDOWINPUT_FULLSCREEN	= 0b00000010,
	WINDOWINPUT_WINDOWSHOWN = 0b00000100,
	WINDOWINPUT_QUIT		= 0b10000000,
};
extern char current_windowInput;

extern unsigned char* current_keyboardInput;

extern int mousePositionX;
extern int mousePositionY;
extern bool mouseButtonDownLeft;
extern bool mouseButtonDownRight;

void UpdateInputs();



void LogSDLError(const char* const msg);

}