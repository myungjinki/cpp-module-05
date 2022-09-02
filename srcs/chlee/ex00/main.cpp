/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee <chlee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 13:41:25 by chlee             #+#    #+#             */
/*   Updated: 2021/03/27 20:45:42 by chlee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	//coplien form test
	Bureaucrat test_bure = Bureaucrat("default", 42);
	Bureaucrat test_copy = test_bure;
	Bureaucrat test_assign = Bureaucrat("assign", 24);
	test_assign = test_bure;

	std::cout << "===Test Param Constructor===" << std::endl;
	std::cout << test_bure;
	std::cout << test_bure.getName() << "'s grade : " << test_bure.getGrade() << std::endl;
	std::cout << "===Test Copy Constructor===" << std::endl;
	std::cout << test_copy;
	std::cout << test_copy.getName() << "'s grade : " << test_copy.getGrade() << std::endl;
	std::cout << "===Test Assign Constructor===" << std::endl;
	std::cout << test_assign;
	std::cout << test_assign.getName() << "'s grade : " << test_assign.getGrade() << std::endl;
	std::cout << std::endl << std::endl;

	//increase, decrease test
	std::cout << "===Increase/Decrease test===" << std::endl;
	test_bure.increaseGrade();
	std::cout << test_bure.getName() << "'s grade : " << test_bure.getGrade() << std::endl;
	test_bure.decreaseGrade();
	std::cout << test_bure.getName() << "'s grade : " << test_bure.getGrade() << std::endl;
	std::cout << std::endl << std::endl;

	//highest, lowest test
	Bureaucrat *highest = new Bureaucrat("highest", 1);

	std::cout << *highest;
	std::cout << highest->getName() << "'s grade : " << highest->getGrade() << std::endl;
	
	Bureaucrat *lowest = new Bureaucrat("lowest", 150);

	std::cout << *lowest;
	std::cout << lowest->getName() << "'s grade : " << lowest->getGrade() << std::endl;

	delete highest;
	delete lowest;

	//throw exception test
	try
	{
		Bureaucrat *too_high = new Bureaucrat("tooHigh", 0);
		std::cout << *too_high;
		std::cout << too_high->getName() << "'s grade : " << too_high->getGrade() << std::endl;

		delete too_high;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n'; //virtual function overload 
	}

	try
	{
		Bureaucrat *too_low = new Bureaucrat("tooLow", 151);
		std::cout << *too_low;
		std::cout << too_low->getName() << "'s grade : " << too_low->getGrade() << std::endl;

		delete too_low;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n'; //virtual function overload 
	}
	
	return (0);
}