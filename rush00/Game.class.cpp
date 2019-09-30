#include "Game.class.hpp"

void Game::init(void) {
	for (int tick = 0;; tick = (tick + 1) % 3000) {
		switch(getch()) {
			case 'q':
				return;
			case 'p':
				this->pause();
				break;
			case KEY_UP:
				this->_world.movePlayer(KEY_UP);
				break;
			case KEY_DOWN:
				this->_world.movePlayer(KEY_DOWN);
				break;
			case KEY_LEFT:
				this->_world.movePlayer(KEY_LEFT);
				break;
			case KEY_RIGHT:
				this->_world.movePlayer(KEY_RIGHT);
				break;
			case ' ':
				this->_world.movePlayer(' ');
				break;
		}
		this->_world.updateOnTick(tick);
		this->_world.redraw();
		if (this->_world.isPlayerDead()) {
			this->pause();
			break;
		}
	}
}

void Game::pause(void) const {
	while (1) {
		if (getch() == 'p') {
			break;			
		}
	}
}


Game::Game(void) {
	initscr();
	keypad(stdscr, true);
	noecho();
	nodelay(stdscr, true);
	curs_set(0);
	this->_world = GameWorld();
}

Game::~Game(void) {
	endwin();
}