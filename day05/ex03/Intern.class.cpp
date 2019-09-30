#include "Intern.class.hpp"

Form * Intern::makeForm(std::string name, std::string target) const {
	try {
		for (size_t i = 0; i != name.length(); i++) {
			name[i] = tolower(name[i]);
		}

		if (name.find("shrubbery") != std::string::npos) {
			std::cout << "Intern creates ShrubberyCreationForm" << std::endl; 
			return new ShrubberyCreationForm(target);
		} else if (name.find("robotomy") != std::string::npos) {
			std::cout << "Intern creates RobotomyRequestForm" << std::endl; 
			return new RobotomyRequestForm(target);
		} else if (name.find("presidential") != std::string::npos) {
			std::cout << "Intern creates PresidentialPardonForm" << std::endl; 
			return new PresidentialPardonForm(target);
		} else {
			throw UnknownFormException();
		}
	} catch (std::exception & e) {
		std::cout << "Creation of a <" + name + "> failed: " << e.what() << std::endl;
	}
	return NULL;
}

Intern & Intern::operator=(Intern const & rhs) {
	(void)rhs;
	return *this;
}

Intern::Intern(const Intern & toCopy) {
	(void)toCopy;
}

Intern::Intern(void) {}
Intern::~Intern(void) {}


const char* Intern::UnknownFormException::what() const throw() {
	return ("form name is invalid.");
}

Intern::UnknownFormException & Intern::UnknownFormException::operator=(UnknownFormException const & rhs) {
	(void)rhs;
	return *this;
}

Intern::UnknownFormException::UnknownFormException(const UnknownFormException & toCopy) {
	*this = toCopy;
}

Intern::UnknownFormException::UnknownFormException(void) {}
Intern::UnknownFormException::~UnknownFormException(void) throw() {}