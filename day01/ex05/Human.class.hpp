#ifndef HUMAN_CLASS_HPP
# define HUMAN_CLASS_HPP

# include "Brain.class.hpp"

class Human {

	private:
		Brain const _brain;

	public:
		std::string identify(void) const;
		Brain const& getBrain(void) const;
		Human(void);
		~Human(void);

};

#endif