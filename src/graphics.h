#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL2/SDL.h>

struct Graphics
{
	Graphics();
	~Graphics();

	Graphics(const Graphics&)=delete;
	Graphics& operator=(const Graphics&)=delete;

private:
	SDL_Window *sdlWindow;
	SDL_Renderer *sdlRenderer;
};

#endif

