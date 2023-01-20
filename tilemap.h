#pragma once

class Tilemap
{
	class TilemapBlock
	{
		static constexpr int width = 32;
		static constexpr int widthShift = 5;
		static constexpr int widthMask = 31;
		static constexpr int height = 16;
		static constexpr int heightShift = 4;
		static constexpr int heightMask = 15;

		static constexpr int tileCount = width * height;
	};


};
