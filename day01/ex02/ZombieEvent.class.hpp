#ifndef ZOMBIEEVENT_CLASS_H
# define ZOMBIEEVENT_CLASS_H

# include <iostream>

class ZombieEvent {

	private:
		std::string _type;

	public:
		void setZombieType(std::string type);
		Zombie* newZombie(std::string name);
		Zombie* randomChump(void);
		ZombieEvent(void);
		~ZombieEvent(void);

};

#endif