#ifndef PLAYER_CLASS_HPP
# define PLAYER_CLASS_HPP

# include "GameEntity.class.hpp"

class Player: public GameEntity  {

public:
	void moveUp(void);
	void moveDown(void);
	void moveLeft(void);
	void moveRight(void);
	void cleanBullets(void);
	Player(void);
	Player(Position pos);
	~Player(void);

};

#endif