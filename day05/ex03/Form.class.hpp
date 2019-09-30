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
	std::string _target;
	
protected:
	virtual void _execute() const = 0;

public:
	std::string getName(void) const;
	int getGradeToSign(void) const;
	int getGradeToExecute(void) const;
	bool isSigned(void) const;
	std::string getTarget() const;

	void beSigned(const Bureaucrat & bureaucrat);
	void execute(Bureaucrat const & executor) const;

	Form & operator=(Form const & rhs);

	Form(std::string name, int gradeToSign, int gradeToExecute, std::string target);
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

	class FormNotSignedException: public std::exception {
		public:
			const char* what() const throw();
			FormNotSignedException & operator=(FormNotSignedException const & rhs);
			FormNotSignedException(const FormNotSignedException & toCopy);
			FormNotSignedException(void);
			~FormNotSignedException(void) throw();
	};

};

std::ostream & operator<<(std::ostream & o, Form const & rhs);

#endif