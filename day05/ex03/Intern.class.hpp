#ifndef INTERN_CLASS_HPP
# define INTERN_CLASS_HPP

# include <iostream>

# include "PresidentialPardonForm.class.hpp"
# include "RobotomyRequestForm.class.hpp"
# include "ShrubberyCreationForm.class.hpp"

class Intern {

public:
	Form * makeForm(std::string name, std::string target) const;

	Intern & operator=(Intern const & rhs);

	Intern(void);
	Intern(const Intern & toCopy);
	~Intern(void);

	class UnknownFormException: public std::exception {
		public:
			const char* what() const throw();
			UnknownFormException & operator=(UnknownFormException const & rhs);
			UnknownFormException(const UnknownFormException & toCopy);
			UnknownFormException(void);
			~UnknownFormException(void) throw();
	};

};

#endif 