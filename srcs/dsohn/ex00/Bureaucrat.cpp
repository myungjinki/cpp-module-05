#include "Bureaucrat.hpp"

void checkBureaucratGrade(int grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat() : name(""), grade(1)
{

}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
	checkBureaucratGrade(grade);
	this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name)
{
	checkBureaucratGrade(other.grade);
	grade = other.grade;
}

Bureaucrat::~Bureaucrat()
{

}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this == &other)
		return *this;
	
	checkBureaucratGrade(other.grade);
	grade = other.grade;

	return *this;
}

std::string const &Bureaucrat::getName() const
{
	return name;
}

int Bureaucrat::getGrade() const
{
	return grade;
}

void Bureaucrat::increment()
{
	checkBureaucratGrade(grade - 1);
	grade--;
}

void Bureaucrat::decrement()
{
	checkBureaucratGrade(grade + 1);
	grade++;
}


const char *Bureaucrat::GradeTooHighException::what() const _NOEXCEPT
{
	return "Error: Bureaucrat: Grade Too High!";
}

const char *Bureaucrat::GradeTooLowException::what() const _NOEXCEPT
{
	return "Error: Bureaucrat: Grade Too Low!";
}

std::ostream &operator<<(std::ostream &stream, Bureaucrat &bureaucrat)
{
	return (stream << "<" << bureaucrat.getName() << ">, bureaucrat grade <" << bureaucrat.getGrade() << ">" << std::endl);
}