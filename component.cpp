#include "component.h"

#include "debug.h"
#include "system.h"


void Component::Start() {}
void Component::Update() {}
void Component::Render() {}
void Component::Destroy() {}





void CPosition::Render()
{
	SDL_SetRenderDrawColor(sys::mainRenderer, 255, 255, 0, 255);
	debug::DrawRectInWorld(position.x, position.y, 16, 16);
}
