/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee <chlee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 00:36:37 by chlee             #+#    #+#             */
/*   Updated: 2021/03/27 20:52:14 by chlee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

std::string form_names[6] =
{
	"shrubbery creation",
	"Shrubbery Creation",
	"robotomy request",
	"Robotomy Request",
	"presidential pardon",
	"Presidential Pardon"
};

static Form	*makeShrubbery(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

static Form	*makePresidential(std::string target)
{
	return (new PresidentialPardonForm(target));
}

static Form	*makeRobotomy(std::string target)
{
	return (new RobotomyRequestForm(target));
}

//function address
Form	*(*form_creates[3]) (std::string) = {makeShrubbery, makeRobotomy, makePresidential};
/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Intern::Intern()
{
}

Intern::Intern( const Intern & src )
{
	(void)src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Intern::~Intern()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Intern &				Intern::operator=( Intern const & rhs )
{
	(void)rhs;
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Intern const & i )
{
	(void)i;
	//o << "Value = " << i.getValue();
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

const char *Intern::FormDoesNotCreateException::what() const throw()
{
	return "Form Error : Any form does not created!";
}

Form *Intern::makeForm(std::string form_name, std::string form_target)
{
	Form	*new_form = NULL;

	for (int i = 0; i < FORM_NAMES_CNT; i++)
	{
		if (form_names[i] == form_name)
			new_form = form_creates[i / 2](form_target);
	}
	if (!new_form)
	{
		std::cerr << "Intern Error : The name of the requested form was not found." << std::endl;
		throw FormDoesNotCreateException();//avoid segfault
	}
	else
		std::cout << "Intern creates " << form_name << std::endl;
	return (new_form);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */