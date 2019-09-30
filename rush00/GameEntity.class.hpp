#ifndef IGAMEENTITY_CLASS_HPP
# define IGAMEENTITY_CLASS_HPP

#include "Position.class.hpp"

class GameEntity {

private:
	std::string	_disp_char;
	int 		_hp;
	int 		_speed;

public:
	Position position;

	bool isDead(void) const;
	bool isCollidingWith(const GameEntity & entity) const;
	void takeDamage(int amount);

	int getHP(void) const;
	int getSpeed(void) const;
	const char* getDispChar(void) const;

	void setDisplayChar(std::string str);
	void setHP(int amount);
	void setSpeed(int speed);
	void setPosition(int x, int y);
	void setPosition(Position pos);
	void clearEntity(void);

	GameEntity & operator=(GameEntity const & rhs);
	GameEntity(const GameEntity& toCopy);
	GameEntity(std::string disp_char, int hp, int speed, Position pos);
	GameEntity(void);
	~GameEntity(void);

};

#endif