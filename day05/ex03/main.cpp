#include "Form.class.hpp"
#include "PresidentialPardonForm.class.hpp"
#include "RobotomyRequestForm.class.hpp"
#include "ShrubberyCreationForm.class.hpp"
#include "Intern.class.hpp"


int main(void) {

	Intern someRandomIntern;

	Form* rrf;
	rrf = someRandomIntern.makeForm("Robotomyrequest", "Bender");

	Form* scf;
	scf = someRandomIntern.makeForm("Shrubberycreation", "Bender");

	Form* ppf;
	ppf = someRandomIntern.makeForm("Presidentialpardon", "Bender");

	Form* invalid;
	invalid = someRandomIntern.makeForm("hmmm", "Bender");

	return 0;
}