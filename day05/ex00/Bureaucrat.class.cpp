#include "Bureaucrat.class.hpp"

std::string Bureaucrat::getName(void) const {
	return this->_name;
}

int Bureaucrat::getGrade(void) const {
	return this->_grade;
}

void Bureaucrat::incrGrade(void) {
	if (this->_grade - 1 < 1) {
		throw GradeTooHighException();
	}
	this->_grade--;
}

void Bureaucrat::decrGrade(void) {
	if (this->_grade + 1 > 150) {
		throw GradeTooLowException();
	}
	this->_grade++;
}
 
Bureaucrat & Bureaucrat::operator=(Bureaucrat const & rhs) {
	this->_grade = rhs._grade;
	return *this;
}

Bureaucrat::Bureaucrat(const Bureaucrat & tocopy) {
	this->_grade = tocopy._grade;
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name) { 
	if (grade > 150) {
		throw GradeTooHighException();
	} else if (grade < 1) {
		throw GradeTooLowException();
	}
	this->_grade = grade;
}
Bureaucrat::Bureaucrat(void) { }
Bureaucrat::~Bureaucrat(void) { }


std::ostream & operator<<(std::ostream & o, Bureaucrat const & rhs) {
	o << rhs.getName() + ", bureaucrat grade " << rhs.getGrade();
	return o;
}


const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return ("The grade is too high");
}

Bureaucrat::GradeTooHighException & Bureaucrat::GradeTooHighException::operator=(GradeTooHighException const & rhs) {
	(void)rhs;
	return *this;
}

Bureaucrat::GradeTooHighException::GradeTooHighException(const GradeTooHighException & toCopy) {
	*this = toCopy;
}

Bureaucrat::GradeTooHighException::GradeTooHighException(void) {}
Bureaucrat::GradeTooHighException::~GradeTooHighException(void) throw() {}



const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return ("The grade is too low");
}

Bureaucrat::GradeTooLowException & Bureaucrat::GradeTooLowException::operator=(GradeTooLowException const & rhs) {
	(void)rhs;
	return *this;
}

Bureaucrat::GradeTooLowException::GradeTooLowException(const GradeTooLowException & toCopy) {
	*this = toCopy;
}

Bureaucrat::GradeTooLowException::GradeTooLowException(void) {}
Bureaucrat::GradeTooLowException::~GradeTooLowException(void) throw() {}