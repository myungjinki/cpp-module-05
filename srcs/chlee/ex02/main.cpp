/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee <chlee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 13:41:25 by chlee             #+#    #+#             */
/*   Updated: 2021/03/28 15:03:45 by chlee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	srand(time(NULL));
	Form *presidential = new PresidentialPardonForm("42 seoul");
	Form *robotomy = new RobotomyRequestForm("42 tokyo");
	Form *shrubbery = new ShrubberyCreationForm("42 paris");

	Bureaucrat grade_high = Bureaucrat("high", 1);
	Bureaucrat grade_mid = Bureaucrat("mid", 75);

	//default test
	std::cout << "======DEFAULT TEST======" << std::endl;
	std::cout << "======Shrubbery TEST======" << std::endl;
	std::cout << *shrubbery << std::endl;
	grade_high.signForm(*shrubbery);
	std::cout << *shrubbery << std::endl;
	std::cout << std::endl;

	std::cout << "======Robotomy TEST======" << std::endl;
	std::cout << *robotomy << std::endl;
	grade_high.signForm(*robotomy);
	robotomy->beSigned(grade_high);
	std::cout << *robotomy << std::endl;
	grade_high.executeForm(*robotomy);
	grade_high.executeForm(*robotomy);
	grade_high.executeForm(*robotomy);
	grade_high.executeForm(*robotomy);
	std::cout << std::endl;

	std::cout << "======Presidential TEST======" << std::endl;
	std::cout << *presidential << std::endl;
	grade_high.signForm(*presidential);
	std::cout << *presidential << std::endl;
	grade_high.executeForm(*presidential);
	std::cout << std::endl;

	std::cout << "======Execute Form TEST======" << std::endl;
	grade_high.executeForm(*shrubbery);
	grade_high.executeForm(*robotomy);
	grade_high.executeForm(*presidential);
	std::cout << std::endl;

	//try-except test
	grade_mid.executeForm(*shrubbery);
	grade_mid.executeForm(*robotomy);
	grade_mid.executeForm(*presidential);
	
	delete presidential;
	delete robotomy;
	delete shrubbery;
	return (0);
}