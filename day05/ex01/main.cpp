#include "Bureaucrat.class.hpp"
#include "Form.class.hpp"

int main(void) {

	Bureaucrat jeka = Bureaucrat("Jeka", 150);
	Bureaucrat jeka2 = Bureaucrat("Jeka2", 1);

	Form bumaga = Form("bumaga", 1, 1);

	std::cout << bumaga << std::endl;

	jeka.signForm(bumaga);
	std::cout << bumaga << std::endl;
	jeka2.signForm(bumaga);
	std::cout << bumaga << std::endl;

	return 0;
}