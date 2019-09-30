#ifndef FORM_CLASS_HPP
# define FORM_CLASS_HPP

# include <iostream>
# include "Bureaucrat.class.hpp"

class Bureaucrat;
class Form {

private:
	const std::string _name;
	const int _gradeToSign;
	const int _gradeToExecute;
	bool _isSigned;
	

public:
	std::string getName(void) const;
	int getGradeToSign(void) const;
	int getGradeToExecute(void) const;
	bool isSigned(void) const;

	void beSigned(const Bureaucrat & bureaucrat);

	Form & operator=(Form const & rhs);

	Form(std::string name, int gradeToSign, int gradeToExecute);
	Form(const Form & toCopy);
	Form(void);
	~Form(void);

	class GradeTooHighException: public std::exception {
		public:
			const char* what() const throw();
			GradeTooHighException & operator=(GradeTooHighException const & rhs);
			GradeTooHighException(const GradeTooHighException & toCopy);
			GradeTooHighException(void);
			~GradeTooHighException(void) throw();
	};

	class GradeTooLowException: public std::exception {
		public:
			const char* what() const throw();
			GradeTooLowException & operator=(GradeTooLowException const & rhs);
			GradeTooLowException(const GradeTooLowException & toCopy);
			GradeTooLowException(void);
			~GradeTooLowException(void) throw();
	};

};

std::ostream & operator<<(std::ostream & o, Form const & rhs);

#endif