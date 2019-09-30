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

std::string Form::getTarget(void) const {
	return this->_target;
}

void Form::beSigned(const Bureaucrat & bureaucrat) {
	if (bureaucrat.getGrade() > this->_gradeToSign) {
		throw GradeTooLowException();
	} else {
		this->_isSigned = true;
	}
}

void Form::execute(Bureaucrat const & executor) const {
	if (!this->isSigned()) {
		throw FormNotSignedException();
	} else if (executor.getGrade() > this->_gradeToExecute) {
		throw GradeTooLowException();
	} else {
		std::cout << executor.getName() + " executes " + this->getName() << std::endl;
		this->_execute();
	}
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute, std::string target):
_name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute), _target(target) {
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
	o << rhs.getName() + ": grade to sign - " << rhs.getGradeToSign();
	o << ", to exec - " << rhs.getGradeToExecute();
	o << ". Status - ";
	if (rhs.isSigned()) {
		o << "signed.";
	} else {
		o << "not signed.";
	}
	return o;
}


const char* Form::GradeTooHighException::what() const throw() {
	return ("the grade is too high");
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
	return ("the grade is too low");
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



const char* Form::FormNotSignedException::what() const throw() {
	return ("form is not signed");
}

Form::FormNotSignedException & Form::FormNotSignedException::operator=(FormNotSignedException const & rhs) {
	(void)rhs;
	return *this;
}

Form::FormNotSignedException::FormNotSignedException(const FormNotSignedException & toCopy) {
	*this = toCopy;
}

Form::FormNotSignedException::FormNotSignedException(void) {}
Form::FormNotSignedException::~FormNotSignedException(void) throw() {}