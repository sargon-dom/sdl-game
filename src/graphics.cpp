#include <stdexcept>
#include "graphics.h"
#include "debug.h"

namespace {
	const int kScreenWidth = 1024;
	const int kScreenHeight = 768;
}

Graphics::Graphics()
{
	debug("create SDLWindow & SDLRenderer");

	sdlWindow = SDL_CreateWindow(
		"SDL Game",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		kScreenWidth,
		kScreenHeight,
		SDL_WINDOW_SHOWN);

	if (sdlWindow == nullptr) {
		throw std::runtime_error("SDL_CreateWindow");
	}

	sdlRenderer = SDL_CreateRenderer(
		sdlWindow,
		-1,
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	if (sdlRenderer == nullptr) {
		throw std::runtime_error("SDL_CreateRenderer");
	}
}

Graphics::~Graphics()
{
	debug("destroy SDLWindow & SDLRenderer");

	SDL_DestroyRenderer(sdlRenderer);
	SDL_DestroyWindow(sdlWindow);
}

