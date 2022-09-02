/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee <chlee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 13:41:25 by chlee             #+#    #+#             */
/*   Updated: 2021/03/27 20:29:14 by chlee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main(void)
{
	srand(time(NULL));
	Intern someRandomIntern;
	Form* rrf;

	//default test
	std::cout << "default test!!" << std::endl;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	std::cout << *rrf << std::endl;
	delete rrf;
	std::cout << std::endl;

	rrf = someRandomIntern.makeForm("Shrubbery Creation", "Chlee");
	std::cout << *rrf << std::endl;
	delete rrf;
	std::cout << std::endl;

	rrf = someRandomIntern.makeForm("Presidential Pardon", "Chlee");
	std::cout << *rrf << std::endl;
	delete rrf;
	std::cout << std::endl;
	
	//exception test
	std::cout << std::endl;
	std::cout << "Exception test!!" << std::endl;
	try
	{
		rrf = someRandomIntern.makeForm("robotomy creation", "Chlee");
		std::cout << *rrf << std::endl;
		delete rrf;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl;
	try
	{
		rrf = someRandomIntern.makeForm("Shrubbery", "Chlee");
		std::cout << *rrf << std::endl;
		delete rrf;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}