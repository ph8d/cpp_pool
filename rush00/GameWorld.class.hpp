#ifndef WORLD_CLASS_HPP
# define WORLD_CLASS_HPP

# define NUMBER_OF_STARS 100
# define NUMBER_OF_ENEMIES 10
# define MAX_BULLETS 1000

# include "GameEntity.class.hpp"
# include "Player.class.hpp"
# include "Star.class.hpp"
# include <ncurses.h>


class GameWorld {

private:
	Star _stars[NUMBER_OF_STARS];
	GameEntity _enemies[NUMBER_OF_ENEMIES];
	Player _player;	

	int _lastBulletIndex;
	GameEntity _bullets[MAX_BULLETS];
	
	void _generateStars(void);
	void _moveStars(int tick);
	void _generateEnemies(void);
	void _moveEnemies(int tick);
	void _generateBullets(void);

	void _moveGameEntityUp(GameEntity entities[], int size, int tick, int targetTick);
	void _moveGameEntityDown(GameEntity entities[], int size, int tick, int targetTick);
	void _drawGameEntity(const GameEntity entities[], int size) const;
	void _drawGameEntity(const GameEntity & entity) const;
	void _handleEntityCollisions(void);
	void _clearDeadEntities(void);
	void _addNewBullet(Position bulletStartPos);

public:
	int boundaryX;
	int boundaryY;

	void redraw(void) const;
	void updateOnTick(int tick);
	void movePlayer(int key);
	bool isPlayerDead(void) const;
	GameEntity const & getPlayer(void) const;
	GameWorld(void);
	~GameWorld(void);

};

#endif