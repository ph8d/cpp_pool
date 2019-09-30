#include "Form.class.hpp"

std::string Form::getName(void) const {
	return this->_name;
}

int Form::getGradeToSign(void) const {
	return this->_gradeToSign;
}

int Form::getGradeToExecute(void) const {
	return this->_gradeToExecute;
}

bool Form::isSigned(void) const {
	return this->_isSigned;
}

void Form::beSigned(const Bureaucrat & bureaucrat) {
	if (bureaucrat.getGrade() > this->_gradeToSign) {
		throw GradeTooLowException();
	} else {
		this->_isSigned = true;
	}
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute):
_name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	if (this->_gradeToExecute > 150 || this->_gradeToSign > 150) {
		throw GradeTooLowException();
	} else if (this->_gradeToExecute < 1 || this->_gradeToSign < 1) {
		throw GradeTooHighException();
	}
}

Form::Form(const Form & toCopy):
_name(toCopy._name), _gradeToSign(toCopy._gradeToSign), _gradeToExecute(toCopy._gradeToExecute), _isSigned(toCopy._isSigned) {}

Form::Form(void): _name(""), _gradeToSign(150), _gradeToExecute(150), _isSigned(false) {}
Form::~Form(void) {}

std::ostream & operator<<(std::ostream & o, Form const & rhs) {
	o << rhs.getName() + ": grade required to sign - " << rhs.getGradeToSign();
	o << ", grade required to exec - " << rhs.getGradeToExecute();
	o << ", status - ";
	if (rhs.isSigned()) {
		o << "signed";
	} else {
		o << "not signed";
	}
	return o;
}


const char* Form::GradeTooHighException::what() const throw() {
	return ("The grade is too high");
}

Form::GradeTooHighException & Form::GradeTooHighException::operator=(GradeTooHighException const & rhs) {
	(void)rhs;
	return *this;
}

Form::GradeTooHighException::GradeTooHighException(const GradeTooHighException & toCopy) {
	*this = toCopy;
}

Form::GradeTooHighException::GradeTooHighException(void) {}
Form::GradeTooHighException::~GradeTooHighException(void) throw() {}



const char* Form::GradeTooLowException::what() const throw() {
	return ("The grade is too low");
}

Form::GradeTooLowException & Form::GradeTooLowException::operator=(GradeTooLowException const & rhs) {
	(void)rhs;
	return *this;
}

Form::GradeTooLowException::GradeTooLowException(const GradeTooLowException & toCopy) {
	*this = toCopy;
}

Form::GradeTooLowException::GradeTooLowException(void) {}
Form::GradeTooLowException::~GradeTooLowException(void) throw() {}