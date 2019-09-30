#ifndef SHRUBBERYCREATIONFORM_CLASS_HPP
# define SHRUBBERYCREATIONFORM_CLASS_HPP

# include "Form.class.hpp"

class ShrubberyCreationForm: public Form {

protected:
	void _execute() const;

public:

	ShrubberyCreationForm & operator=(ShrubberyCreationForm const & rhs);

	ShrubberyCreationForm(void);
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm & toCopy);

};

#endif