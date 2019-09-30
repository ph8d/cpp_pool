#include "Game.class.hpp"
#include <iostream>

int main(void) {

	Game* game = new Game();

	game->init();

	delete game;
	return 0;
}