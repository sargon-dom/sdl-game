#ifndef GAME_H
#define GAME_H

#include "graphics.h"

struct Game {
	Game();
	~Game();
private:
	void loop();
	void processInput();
	void update();
	void render();
	Graphics graphics_;
	bool running_ = false;
};

#endif

