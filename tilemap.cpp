#include "tilemap.h"

#include "log.h"
#include <iostream>
#include <exception>

#include "system.h"
#include "camera.h"



Tilemap::TilemapBlock::TilemapBlock(FILE* file)
{
	for (int i = 0; i < tileCount >> 1; i++)
	{
		unsigned char byte = fgetc(file);
		tiles[(i << 1)]		= (Tile)(byte & 0b00001111);
		tiles[(i << 1) + 1] = (Tile)(byte >> 4);
	}
}



Tilemap::TilemapBlock::~TilemapBlock()
{
	
}



void Tilemap::TilemapBlock::CreateDebugTilemap()
{
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			tiles[x + (y * width)] = (x==0||y==0||x==width-1||y==height-1);
		}
	}
}



void Tilemap::TilemapBlock::Render(int offx, int offy)
{
	SDL_SetRenderDrawColor(sys::mainRenderer, 255, 255, 255, 255);
	SDL_Rect rect = { 0, 0, 8, 8 };
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			if (tiles[x | (y * width)] != 0)
			{
				rect.x = (x << tileshift) + offx;
				rect.y = (y << tileshift) + offy;
				SDL_RenderFillRect(sys::mainRenderer, &rect);
			}
		}
	}
}



Tilemap::TilemapBlock* Tilemap::GetTilemapBlock(int blockx, int blocky)
{
	if (blockx < 0 || blockx >= blockwidth || blocky < 0 || blocky >= blockheight) return nullptr;
	return blocks[blockx + (blocky * blockwidth)];
}



Tilemap::Tilemap(const char* const filename)
{
	FILE* file = fopen(filename, "rb");
	if (!file)
	{
		throw 0;
	}

	TilemapFileHeader header;
	fread(&header, sizeof(header), 1, file);

	blockwidth = header.blockwidth;
	blockheight = header.blockheight;
	blockcount = blockwidth * blockheight;
	tilewidth = blockwidth << TilemapBlock::widthShift;
	tileheight = blockheight << TilemapBlock::heightShift;

	char* nullblocks = new char[blockcount];
	fread(nullblocks, sizeof(char), blockcount, file);

	blocks = new TilemapBlock*[blockcount];
	for (int i = 0; i < blockcount; i++)
	{
		if (nullblocks[i])
			blocks[i] = new TilemapBlock(file);
		else
			blocks[i] = nullptr;
	}
	
	delete[] nullblocks;
}



Tile Tilemap::GetTile(int x, int y)
{
	TilemapBlock* block = GetTilemapBlock(
		x >> TilemapBlock::widthShift,
		y >> TilemapBlock::heightShift);
	if (!block) return 0;
	return block->tiles[
		x & TilemapBlock::widthMask |
		((y & TilemapBlock::heightMask) * TilemapBlock::width)];
}

bool Tilemap::GetTileSolid(int x, int y)
{
	return GetTile(x, y) != 0;
}



void Tilemap::Render()
{
	for (int by = 0; by < blockheight; by++)
	{
		for (int bx = 0; bx < blockwidth; bx++)
		{
			TilemapBlock* block = GetTilemapBlock(bx, by);
			if (block)
				block->Render(
					(bx << (TilemapBlock::widthShift + tileshift)) - cameraRenderPositionX,
					(by << (TilemapBlock::heightShift) + tileshift) - cameraRenderPositionY);
		}
	}
}







Tilemap* mainTilemap = nullptr;
