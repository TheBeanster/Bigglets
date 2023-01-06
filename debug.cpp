#include "debug.h"

#include "system.h"
#include "camera.h"



namespace debug
{

using namespace sys;



void SetColor(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
{
	SDL_SetRenderDrawColor(mainRenderer, r, g, b, a);
}



void DrawRect(int x, int y, int w, int h)
{
	SDL_Rect rect = { x, y, w, h };
	SDL_RenderDrawRect(mainRenderer, &rect);
}



void FillRect(int x, int y, int w, int h)
{
	SDL_Rect rect = { x, y, w, h };
	SDL_RenderFillRect(mainRenderer, &rect);
}



void DrawRectInWorld(int x, int y, int w, int h)
{
	SDL_Rect rect = { x - cameraRenderPositionX, y - cameraRenderPositionY, w, h };
	SDL_RenderDrawRect(mainRenderer, &rect);
}



void FillRectInWorld(int x, int y, int w, int h)
{
	SDL_Rect rect = { x - cameraRenderPositionX, y - cameraRenderPositionY, w, h };
	SDL_RenderFillRect(mainRenderer, &rect);
}



void DrawFrameRateDisplay(int frame)
{
	SDL_SetRenderTarget(mainRenderer, mainTexture);
	
	// Frame display
	SetColor(255, 0, 255, 255);
	if ((frame & 0b11) == 0) FillRect(screenWidth - 19, 1, 8, 8);
	if ((frame & 0b11) == 1) FillRect(screenWidth - 9, 1, 8, 8);
	if ((frame & 0b11) == 2) FillRect(screenWidth - 9, 11, 8, 8);
	if ((frame & 0b11) == 3) FillRect(screenWidth - 19, 11, 8, 8);

	// Second display
	SetColor(0, 255, 255, 255);
	if ((frame % (144 * 2)) < 144) FillRect(screenWidth - 19, 21, 8, 8);
	if ((frame % (144 * 2)) >= 144) FillRect(screenWidth - 9, 21, 8, 8);
}



}