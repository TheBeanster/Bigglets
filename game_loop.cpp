#include "game_main.h"

#include "system.h"
#include "debug.h"
#include "vector2.h"
#include "utility.h"
#include "camera.h"
#include <stdlib.h>

#include "tilemap.h"

#include "entity.h"



void GameLoop()
{
	SDL_SetRenderDrawColor(sys::mainRenderer, 0, 0, 0, 255);
	SDL_RenderClear(sys::mainRenderer);

	UpdateEntities();
	
	UpdateCamera();
	std::cout << cameraPosition << '\n';

	std::cout << ((CPosition*)(worldEntities.begin()->GetComponent(CTYPE_TESTCOMPONENT)))->position << '\n';

	RenderEntities();

	mainTilemap->Render();
	
	debug::SetColor(0, 255, 0, 255);
	debug::FillRectInWorld(10, 10, 10, 10);

	debug::DrawFrameRateDisplay(frameCount);

	frameCount++;
}
