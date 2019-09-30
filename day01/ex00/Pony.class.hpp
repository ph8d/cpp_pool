#ifndef PONY_CLASS_H
# define PONY_CLASS_H

# include <iostream>

class Pony {

	private:
		std::string _name;

	public:
		Pony(std::string name);
		~Pony(void);

};

#endif