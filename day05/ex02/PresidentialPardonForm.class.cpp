#include "PresidentialPardonForm.class.hpp"

void PresidentialPardonForm::_execute() const {
	std::cout << this->getTarget() + " has been pardoned by Zaphod Beeblebrox" << std::endl;
} 

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & rhs) {
	(void)rhs;
	return *this;
}

PresidentialPardonForm::PresidentialPardonForm(void): Form("PresidentialPardonForm", 25, 5, "") {}

PresidentialPardonForm::PresidentialPardonForm(std::string target): Form("PresidentialPardonForm", 25, 5, target) { }

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm & toCopy):
Form(toCopy.getName(), toCopy.getGradeToSign(), toCopy.getGradeToExecute(), toCopy.getTarget()) { }