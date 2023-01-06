#include <iostream>
#include <SDL.h>



int main(int argc, char** argv)
{
	std::cout << "Heyo\n";

	SDL_CreateWindow(
		"woa",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		100,
		100,
		0
	);

	system("pause");
	
	return 0;
}
