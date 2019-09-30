#ifndef GAME_CLASS_HPP
# define GAME_CLASS_HPP

# include "GameWorld.class.hpp"

class Game {

private:
	GameWorld _world;

public:
	void init(void);
	void pause(void) const;
	Game(void);
	~Game(void);

};

#endif