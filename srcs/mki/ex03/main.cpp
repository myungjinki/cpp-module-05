/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 03:12:10 by mki               #+#    #+#             */
/*   Updated: 2021/08/20 09:11:49 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

void PresidentialPardonTest()
{
    Bureaucrat cat("bear", 1);
    Intern mki;

    Form *home = mki.makeForm("presidential pardon", "home");
    if (!home)
    {
        return;
    }
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
    Intern mki;

    Form *home = mki.makeForm("robotomy request", "home");
    if (!home)
    {
        return;
    }
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
    Intern mki;

    Form *home = mki.makeForm("shrubber creation", "home");
    if (!home)
    {
        return;
    }
    // Form *home = mki.makeForm("shrubbery creation", "home");
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
