#include "GameWorld.class.hpp"

void GameWorld::_generateStars(void) {
	for (int i = 0; i != NUMBER_OF_STARS; i++) {
		this->_stars[i].setSpeed(2);
		this->_stars[i].position.x = rand() % this->boundaryX;
		this->_stars[i].position.y = rand() % this->boundaryY;
	}
}

void GameWorld::_moveStars(int tick) {
	if (tick != 1) {
		return;
	}
	for (int i = 0; i != NUMBER_OF_STARS; i++) {
		this->_stars[i].position.y++;
		if (this->_stars[i].position.y > this->boundaryY) {
			this->_stars[i].position.y = 0;
			this->_stars[i].position.x = rand() % this->boundaryX;
		}
	}
}

void GameWorld::_generateEnemies(void) {
	for (int i = 0; i != NUMBER_OF_ENEMIES; i++) {
		this->_enemies[i].setDisplayChar("V");
		this->_enemies[i].setHP(100);
		this->_enemies[i].setSpeed(1);
		this->_enemies[i].position.x = rand() % this->boundaryX;
		this->_enemies[i].position.y = 0 - (rand() % 10);
	}
}

void GameWorld::_generateBullets(void) {
	for (int i = 0; i != MAX_BULLETS; i++) {
		this->_bullets[i].setDisplayChar("|");
		this->_bullets[i].setSpeed(1);
	}
}

void GameWorld::_moveEnemies(int tick) {
	if (tick != 1500) {
		return;
	}
	for (int i = 0; i != NUMBER_OF_STARS; i++) {
		this->_stars[i].position.y++;
		if (this->_stars[i].position.y > this->boundaryY) {
			this->_stars[i].position.y = 0;
			this->_stars[i].position.x = rand() % this->boundaryX;
		}
	}
}

void GameWorld::_moveGameEntityUp(GameEntity entities[], int size, int tick, int targetTick) {
	if (tick != targetTick) {
		return;
	}
	for (int i = 0; i != size; i++) {
		entities[i].position.y -= entities[i].getSpeed();
		if (entities[i].position.y == 0) {
			entities[i].position.y = this->boundaryY;
			entities[i].position.x = rand() % this->boundaryX;
		}
	}
	this->_handleEntityCollisions();
}

void GameWorld::_moveGameEntityDown(GameEntity entities[], int size, int tick, int targetTick) {
	if (tick != targetTick) {
		return;
	}
	for (int i = 0; i != size; i++) {
		entities[i].position.y += entities[i].getSpeed();
		if (entities[i].position.y > this->boundaryY) {
			entities[i].position.y = 0;
			entities[i].position.x = rand() % this->boundaryX;
		}
	}
	this->_handleEntityCollisions();
}

void GameWorld::_handleEntityCollisions(void) {
	for (int i = 0; i != NUMBER_OF_ENEMIES; i++) {
		if (this->_player.isCollidingWith(this->_enemies[i])) {
			this->_player.takeDamage(100);
		}
	}

	for (int i = 0; i != this->_lastBulletIndex; i++) {
		if (this->_player.isCollidingWith(this->_bullets[i])) {
			this->_player.takeDamage(100);
			this->_bullets[i].takeDamage(100);
		}
	}

	for (int i = 0; i != NUMBER_OF_ENEMIES; i++) {
		for (int j = 0; j != this->_lastBulletIndex; j++) {
			if (this->_enemies[i].isCollidingWith(this->_bullets[j])) {
				this->_enemies[i].takeDamage(100);
				this->_bullets[j].takeDamage(100);
			}
		}
	}
}

void GameWorld::_drawGameEntity(const GameEntity entities[], int size) const {
	for (int i = 0; i != size; i++) {
		if (!entities[i].isDead()) {
			mvprintw(entities[i].position.y, entities[i].position.x, entities[i].getDispChar());
		}
	}
}

void GameWorld::_drawGameEntity(const GameEntity & entity) const {
	if (!entity.isDead()) {
		mvprintw(entity.position.y, entity.position.x, entity.getDispChar());
	}
}

void GameWorld::_clearDeadEntities(void) {
	for (int i = 0; i != NUMBER_OF_ENEMIES; i++) {
		if (this->_enemies[i].isDead()) {
			this->_enemies[i].clearEntity();
		}
	}

	for (int i = 0; i != this->_lastBulletIndex; i++) {
		if (this->_bullets[i].isDead()) {
			this->_bullets[i].clearEntity();
		}
	}
}

void GameWorld::redraw(void) const {
	erase();
	this->_drawGameEntity(this->_stars, NUMBER_OF_STARS);
	this->_drawGameEntity(this->_enemies, NUMBER_OF_ENEMIES);
	this->_drawGameEntity(this->_bullets, this->_lastBulletIndex);
	this->_drawGameEntity(this->_player);
}

void GameWorld::updateOnTick(int tick) {
	this->_moveGameEntityDown(this->_stars, NUMBER_OF_STARS, tick, 1);
	this->_moveGameEntityDown(this->_enemies, NUMBER_OF_ENEMIES, tick, 1);
	this->_moveGameEntityUp(this->_bullets, this->_lastBulletIndex, tick, 1);
	this->_clearDeadEntities();
}

GameEntity const & GameWorld::getPlayer(void) const {
	return this->_player;
}

void GameWorld::_addNewBullet(Position bulletStartPos) {
	if (_lastBulletIndex == MAX_BULLETS) {
		return;
	}
	this->_bullets[_lastBulletIndex].setHP(1);
	this->_bullets[_lastBulletIndex].setPosition(bulletStartPos);
	_lastBulletIndex++;
}

void GameWorld::movePlayer(int key) {
	if (key == KEY_UP && this->_player.position.y > 1) {
		this->_player.moveUp();
	} if (key == KEY_DOWN && this->_player.position.y < this->boundaryY - 1) {
		this->_player.moveDown();
	} if (key == KEY_LEFT && this->_player.position.x > 1) {
		this->_player.moveLeft();
	} if (key == KEY_RIGHT && this->_player.position.x < this->boundaryX - 1) {
		this->_player.moveRight();
	} if (key == ' ') {
		this->_addNewBullet(Position(this->_player.position.x, this->_player.position.y - 1));
	}
	this->_handleEntityCollisions();
}

bool GameWorld::isPlayerDead(void) const {
	return this->_player.isDead();
}

GameWorld::GameWorld(void) {
	srand(time(NULL));
	getmaxyx(stdscr, this->boundaryY, this->boundaryX);
	this->_generateStars();
	this->_generateEnemies();
	this->_generateBullets();
}

GameWorld::~GameWorld(void) { }