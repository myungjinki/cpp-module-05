/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 03:12:10 by mki               #+#    #+#             */
/*   Updated: 2021/08/20 06:10:58 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void PresidentialPardonTest()
{
    Bureaucrat cat("bear", 1);

    Form *home = new PresidentialPardonForm("Home");
    try
    {
        cat.signForm(*home);
        cat.executeForm(*home);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    delete home;
}

void RobotomyRequestTest()
{
    Bureaucrat cat("dog", 100);

    Form *home = new RobotomyRequestForm("Home");
    try
    {
        cat.signForm(*home);
        cat.executeForm(*home);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    delete home;
}

void ShrubberyTest()
{
    Bureaucrat cat("cat", 100);

    Form *home = new ShrubberyCreationForm("Home");
    try
    {
        cat.signForm(*home);
        cat.executeForm(*home);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    delete home;
}

int main()
{
    ShrubberyTest();
    RobotomyRequestTest();
    PresidentialPardonTest();
}
