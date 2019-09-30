#include "RobotomyRequestForm.class.hpp"

void RobotomyRequestForm::_execute() const {
	srand(time(NULL));

	int chance = rand() % 2;

	std::cout << "* some drilling noises *" << std::endl;

	if (chance == 1) {
		std::cout << this->getTarget() + " has been robotomized successfully!" << std::endl;
	} else {
		std::cout << "robotomy on " + this->getTarget() + " has failed!" << std::endl;
	}
} 

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & rhs) {
	(void)rhs;
	return *this;
}

RobotomyRequestForm::RobotomyRequestForm(void): Form("RobotomyRequestForm", 72, 45, "") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target): Form("RobotomyRequestForm", 72, 45, target) { }

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm & toCopy):
Form(toCopy.getName(), toCopy.getGradeToSign(), toCopy.getGradeToExecute(), toCopy.getTarget()) { }