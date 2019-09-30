#ifndef PRESIDENTIALPARDONFORM_CLASS_HPP
# define PRESIDENTIALPARDONFORM_CLASS_HPP

# include "Form.class.hpp"

class PresidentialPardonForm: public Form {

protected:
	void _execute() const;

public:

	PresidentialPardonForm & operator=(PresidentialPardonForm const & rhs);

	PresidentialPardonForm(void);
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(const PresidentialPardonForm & toCopy);

};

#endif