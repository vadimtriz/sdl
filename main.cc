
#include <iostream>
#include <memory>

#include <SDL2/SDL.h>
#include <SDL2/SDL_main.h>

#include "BirdsWindow.h"

int main(int, char**)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	BirdsWindow window1;
	std::cout << "Program started!" << std::endl;

	window1.main_loop();

	std::cout << "Program started!" << std::endl;

	return 0;
}
