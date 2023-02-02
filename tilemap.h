#pragma once

#include <stdio.h>



typedef unsigned short Tile;

constexpr int tilesize = 8;
constexpr int tileshift = 3;
constexpr int tilemask = 7;



class Tilemap
{
private:
	class TilemapBlock
	{
	public:

		static constexpr int width = 32;
		static constexpr int widthShift = 5;
		static constexpr int widthMask = 31;
		static constexpr int height = 16;
		static constexpr int heightShift = 4;
		static constexpr int heightMask = 15;

		static constexpr int tileCount = width * height;

		Tile tiles[tileCount];

		TilemapBlock() = default;
		TilemapBlock(FILE* file);
		~TilemapBlock();

		void CreateDebugTilemap();

		void Render(int offx, int offy);
	};

	struct TilemapFileHeader
	{
		int blockwidth;
		int blockheight;
	};

	int blockwidth;
	int blockheight;
	int blockcount;
	int tilewidth;
	int tileheight;
	TilemapBlock** blocks;

	TilemapBlock* GetTilemapBlock(int blockx, int blocky);

public:

	Tilemap(const char* const filename);

	Tile GetTile(int x, int y);
	bool GetTileSolid(int x, int y);

	void Render();
	
};



extern Tilemap* mainTilemap;

