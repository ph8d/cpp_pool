
#include "Bureaucrat.class.hpp"

int main(void) {

	Bureaucrat jeka = Bureaucrat("Jeka", 150);
	Bureaucrat jeka2 = Bureaucrat("Jeka2", 1);

	std::cout << jeka << std::endl;
	std::cout << jeka2 << std::endl;

	try {
		Bureaucrat sanya = Bureaucrat("Sanya", -10);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat jhon = Bureaucrat("Jhon", 199);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	try {
		jeka.decrGrade();
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	try {
		jeka2.incrGrade();
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}