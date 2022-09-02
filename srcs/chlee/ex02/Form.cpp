/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee <chlee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 00:37:24 by chlee             #+#    #+#             */
/*   Updated: 2021/03/27 20:31:26 by chlee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Form::Form(std::string name, int signGrade, int execGrade)
: name_(name), signed_(false), signGrade_(signGrade), execGrade_(execGrade)
{
	if (this->execGrade_ < 1 || this->signGrade_ < 1)
		throw GradeTooHighException();
	else if (this->execGrade_ > 150 || this->signGrade_ > 150)
		throw GradeTooLowException();
}

Form::Form( const Form & src )
: name_(src.name_), signed_(src.signed_), signGrade_(src.signGrade_), execGrade_(src.execGrade_)
{
	if (this->execGrade_ < 1 || this->signGrade_ < 1)
		throw GradeTooHighException();
	else if (this->execGrade_ > 150 || this->signGrade_ > 150)
		throw GradeTooLowException();
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Form::~Form()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Form &				Form::operator=( Form const & rhs )
{
	if ( this != &rhs )
	{
		// this->name_ = rhs.getName();
		this->signed_ = rhs.signed_;
		// this->signGrade_ = rhs.getSignGrade();
		// this->execGrade_ = rhs.getExecGrade();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Form const & i )
{
	o << i.getName() << ", Form SignGrade " << i.getSignGrade() 
		<< ", Form ExecGrade " << i.getExecGrade() << ", signed " << i.isSigned() << ".";
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void	Form::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > this->getExecGrade())
		throw Form::GradeTooLowException();
	else if (this->signed_ == false)
		throw Form::SignedValueFalseException();
}

void Form::copyMember(Form const &rhs)
{
	this->signed_ = rhs.signed_;
}

void Form::beSigned(Bureaucrat target)
{
	if (target.getGrade() < this->signGrade_)
		this->signed_ = true;
	else
		throw GradeTooLowException();
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Form Error: ExecGrade is too high!";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Form Error: ExecGrade is too low!";
}

const char *Form::SignedValueFalseException::what() const throw()
{
	return "Form Error: Signed value is false!";
}


std::string Form::getName(void) const
{
	return (this->name_);
}

bool Form::isSigned(void) const
{
	return (this->signed_);
}

int Form::getSignGrade(void) const
{
	return (this->signGrade_);
}

int Form::getExecGrade(void) const
{
	return (this->execGrade_);
}
/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */