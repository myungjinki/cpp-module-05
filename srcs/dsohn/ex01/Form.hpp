#ifndef Form_hpp
#define Form_hpp

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Form
{
private:
	const std::string name;
	bool isSigned;
	const int gradeToSign;
	const int gradeToExecute;
public:
	Form();
	Form(std::string name, int gradeToSign, int gradeToExecute);
	virtual ~Form();
	Form(const Form&);

	Form &operator=(const Form&);

	std::string const &getName() const;
	bool IsSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;

	void beSigned(Bureaucrat&);

	class GradeTooHighException : public std::exception
	{
	public:
		 virtual const char* what() const _NOEXCEPT;
	};

	class GradeTooLowException : public std::exception
	{
	public:
		 virtual const char* what() const _NOEXCEPT;
	};

	class AlreadySignedException : public std::exception
	{
	public:
		 virtual const char* what() const _NOEXCEPT;
	};

	class NotSignedException : public std::exception
	{
	public:
		 virtual const char* what() const _NOEXCEPT;
	};
};

std::ostream &operator<<(std::ostream&, Form&);

#endif