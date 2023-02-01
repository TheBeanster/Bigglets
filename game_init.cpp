#include "game_main.h"

#include <iostream>
#include <iomanip>

#include "tilemap.h"



bool GameInit()
{
	std::cout << std::fixed;
	std::cout << std::setprecision(3);

	mainTilemap = new Tilemap("testTilemapFile.bigtilemap");

	return true;
}
