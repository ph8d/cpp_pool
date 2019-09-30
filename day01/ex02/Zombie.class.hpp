#ifndef ZOMBIE_CLASS_H
# define ZOMBIE_CLASS_H

# include <iostream>

class Zombie {

	private:
		std::string _type;
		std::string _name;

	public:
		void announce(void);
		Zombie(std::string type, std::string name);
		~Zombie(void);

};

#endif