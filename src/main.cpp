#include <stdexcept>
#include "game.h"

int main()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        throw std::runtime_error("SDL_Init");
    }
	Game game;
	SDL_Quit();
	return 0;
}

