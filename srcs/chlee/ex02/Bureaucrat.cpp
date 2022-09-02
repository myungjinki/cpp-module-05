/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee <chlee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 00:37:29 by chlee             #+#    #+#             */
/*   Updated: 2021/03/28 14:51:22 by chlee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Bureaucrat::Bureaucrat(std::string name, int grade)
: name_(name), grade_(grade)
{
	if (this->grade_ < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (this->grade_ > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat( const Bureaucrat & src )
: name_(src.name_), grade_(src.grade_)
{
	// std::cout << "copy" << std::endl;
	if (this->grade_ < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (this->grade_ > 150)
		throw Bureaucrat::GradeTooLowException();
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Bureaucrat::~Bureaucrat()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Bureaucrat &				Bureaucrat::operator=( Bureaucrat const & rhs )
{
	if (this != &rhs)
	{
		this->grade_ = rhs.grade_;
	}
	// std::cout << "assign" << std::endl;
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Bureaucrat const & i )
{
	o << i.getName() << ", bureaucrat grade " << i.getGrade() << "." << std::endl;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void Bureaucrat::executeForm(Form const & form)
{
	try
	{
		form.execute(*this);
		std::cout << this->getName() << " exceutes " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void Bureaucrat::signForm(Form &form)
{
	if (form.isSigned())
	{
		std::cout << form.getName() << " already signed!" << std::endl;
	}
	else
	{
		try
		{
			form.beSigned(*this);
			std::cout << this->getName() << " signs " << form.getName() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
			std::cerr << this->getName() << " cannot sign " << form.getName() 
			<< " because Bureaucrat's grade is too low or not signed!" << std::endl;
		}
	}
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Bureaucrat Error: Grade is too high!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Bureaucrat Error: Grade is too low!";
}

void Bureaucrat::increaseGrade(void)
{
	this->grade_--;
	if (this->grade_ < 1)
		throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::decreaseGrade(void)
{
	this->grade_++;
	if (this->grade_ > 150)
		throw Bureaucrat::GradeTooLowException();
}


const std::string &Bureaucrat::getName() const
{
	return (this->name_); 
}

int Bureaucrat::getGrade() const
{
	return (this->grade_);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */