#include "game.h"
#include "debug.h"

namespace {
	const unsigned int kTicks = 1000 / 60;
}

Game::Game() :
	graphics_()
{
	debug("init Game");

	loop();
}

Game::~Game()
{
	debug("quit Game");
}

void Game::processInput()
{
	SDL_Event event;

	while (SDL_PollEvent(&event)) {
		switch (event.type) {
			case SDL_QUIT:
				running_ = false;
				break;
			default:
				break;
		}
	}
}

void Game::update()
{
}

void Game::render()
{
}

/**
 * Game loop
 * See also: http://gameprogrammingpatterns.com/game-loop.html
 */
void Game::loop()
{
	debug("start loop [Game]");

	unsigned int previous =	SDL_GetTicks();
	unsigned int lag = 0;
	running_ = true;
	while (running_) {
		unsigned int current = SDL_GetTicks();
		unsigned int elapsed = current - previous;
		previous = current;
		lag += elapsed;

		processInput();

		while (lag >= kTicks) {
			update();
			lag -= kTicks;
		}

		render();
	}	
}

