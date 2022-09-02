#include "Form.hpp"

int checkFormGrade(int grade)
{
	if (grade < 1)
		throw Form::GradeTooHighException();
	if (grade > 150)
		throw Form::GradeTooLowException();
	return grade;
}

Form::Form() : name(""), target(""), gradeToSign(1), gradeToExecute(1)
{
	isSigned = false;
}

Form::Form(std::string name, std::string target, int gradeToSign, int gradeToExecute) 
	: name(name), target(target), gradeToSign(checkFormGrade(gradeToSign)), gradeToExecute(checkFormGrade(gradeToExecute))
{
	isSigned = false;
}

Form::~Form()
{

}

Form::Form(const Form& other) 
	: name(other.name), target(other.target), gradeToSign(checkFormGrade(other.gradeToSign)), gradeToExecute(checkFormGrade(other.gradeToExecute))
{
	isSigned = other.isSigned;
}

Form &Form::operator=(const Form& other)
{
	if (this == &other)
		return *this;
	
	isSigned = other.isSigned;
	target = other.target;

	return *this;
}

std::string const &Form::getName() const
{
	return name;
}

std::string const &Form::getTarget() const
{
	return target;
}

bool Form::IsSigned() const
{
	return isSigned;
}

int Form::getGradeToSign() const
{
	return gradeToSign;
}

int Form::getGradeToExecute() const
{
	return gradeToExecute;
}

void Form::beSigned(Bureaucrat& bureacrat)
{
	if (isSigned)
		throw Form::AlreadySignedException();
	if (bureacrat.getGrade() > gradeToSign)
		throw Form::GradeTooLowException();
	isSigned = true;
}

void Form::execute(Bureaucrat const & executor) const
{
	if (!isSigned)
		throw Form::NotSignedException();
	if (executor.getGrade() > gradeToExecute)
		throw Form::GradeTooLowException();
}

const char *Form::GradeTooHighException::what() const _NOEXCEPT
{
	return "Error: Form: Grade Too High!";
}

const char *Form::GradeTooLowException::what() const _NOEXCEPT
{
	return "Error: Form: Grade Too Low!";
}

const char *Form::AlreadySignedException::what() const _NOEXCEPT
{
	return "Error: Form: Already Signed!";
}

const char *Form::NotSignedException::what() const _NOEXCEPT
{
	return "Error: Form: Not Signed!";
}

std::ostream &operator<<(std::ostream& stream, Form& form)
{
	return (stream << form.getName() << ", " << form.IsSigned() << ", " 
		<< form.getGradeToSign() << ", " << form.getGradeToExecute() << std::endl); 
}
