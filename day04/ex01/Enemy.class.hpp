#ifndef ENEMY_CLASS_HPP
# define ENEMY_CLASS_HPP

#include <iostream>

class Enemy {

protected:
	int _hp;
	std::string _type;

public:
	virtual void takeDamage(int);
	int	getHP(void) const;
	std::string getType(void) const;
	Enemy & operator=(Enemy const & rhs);
	Enemy(int hp, std::string const & type);
	Enemy(const Enemy & toCopy);
	virtual ~Enemy(void);

};

#endif