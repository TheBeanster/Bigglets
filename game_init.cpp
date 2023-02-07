#include "game_main.h"

#include <iostream>
#include <iomanip>

#include "tilemap.h"

#include "entity.h"



bool GameInit()
{
	std::cout << std::fixed;
	std::cout << std::setprecision(3);

	mainTilemap = new Tilemap("testTilemapFile.bigtilemap");

	Entity& e = SpawnEntity(ETYPE_PLAYER, { 0,0 });
	((CPosition*)(e.GetComponent(CTYPE_TESTCOMPONENT)))->position = { 10, 10 };

	return true;
}
