#include "Bureaucrat.class.hpp"
#include "Form.class.hpp"
#include "PresidentialPardonForm.class.hpp"
#include "RobotomyRequestForm.class.hpp"
#include "ShrubberyCreationForm.class.hpp"


int main(void) {

	Bureaucrat jeka = Bureaucrat("Jeka", 150);
	Bureaucrat jeka2 = Bureaucrat("Jeka2", 1);

	PresidentialPardonForm presidential = PresidentialPardonForm("Petro");

	RobotomyRequestForm robotomy = RobotomyRequestForm("Grigoriy");

	ShrubberyCreationForm shrubbery = ShrubberyCreationForm("Galina");

	std::cout << shrubbery << std::endl;

	jeka.signForm(shrubbery);
	std::cout << shrubbery << std::endl;

	jeka2.executeForm(shrubbery);

	jeka2.signForm(shrubbery);
	std::cout << shrubbery << std::endl;

	jeka2.executeForm(shrubbery);

	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << robotomy << std::endl;

	jeka.signForm(robotomy);
	std::cout << robotomy << std::endl;

	jeka2.executeForm(robotomy);

	jeka2.signForm(robotomy);
	std::cout << robotomy << std::endl;

	jeka2.executeForm(robotomy);

	std::cout << std::endl;
	std::cout << std::endl;

	jeka.signForm(presidential);
	std::cout << presidential << std::endl;

	jeka2.executeForm(presidential);

	jeka2.signForm(presidential);
	std::cout << presidential << std::endl;

	jeka2.executeForm(presidential);

	return 0;
}