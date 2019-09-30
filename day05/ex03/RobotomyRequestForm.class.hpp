#ifndef ROBOTOMYREQUESTFORM_CLASS_HPP
# define ROBOTOMYREQUESTFORM_CLASS_HPP

# include "Form.class.hpp"

class RobotomyRequestForm: public Form {

protected:
	void _execute() const;

public:

	RobotomyRequestForm & operator=(RobotomyRequestForm const & rhs);

	RobotomyRequestForm(void);
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm & toCopy);

};

#endif