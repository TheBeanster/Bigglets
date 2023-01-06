#include "camera.h"

#include "system.h"



vector2 cameraPosition = 0;

int cameraRenderPositionX = 0;
int cameraRenderPositionY = 0;



void UpdateCamera()
{
	constexpr float debugcamspeed = 2.0f;
	if (sys::current_keyboardInput[SDL_SCANCODE_LEFT]) cameraPosition.x -= debugcamspeed;
	if (sys::current_keyboardInput[SDL_SCANCODE_RIGHT]) cameraPosition.x += debugcamspeed;
	if (sys::current_keyboardInput[SDL_SCANCODE_UP]) cameraPosition.y -= debugcamspeed;
	if (sys::current_keyboardInput[SDL_SCANCODE_DOWN]) cameraPosition.y += debugcamspeed;

	cameraRenderPositionX = (int)roundf(cameraPosition.x);
	cameraRenderPositionY = (int)roundf(cameraPosition.y);
}
