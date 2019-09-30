#ifndef BUREAUCRAT_CLASS_HPP
# define BUREAUCRAT_CLASS_HPP

#include <iostream>

class Bureaucrat {

private:
	const std::string _name;
	int _grade;

public:
	std::string getName(void) const;
	int getGrade(void) const;

	void incrGrade(void);
	void decrGrade(void);

	Bureaucrat & operator=(Bureaucrat const & rhs);

	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat & toCopy);
	Bureaucrat(void);
	~Bureaucrat(void);

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

std::ostream & operator<<(std::ostream & o, Bureaucrat const & rhs);

#endif