/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 06:31:17 by mki               #+#    #+#             */
/*   Updated: 2021/08/20 06:46:24 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
}
Intern::Intern(const Intern &i)
{
    Intern::operator=(i);
}
Intern &Intern::operator=(const Intern &i)
{
    (void)i;
    return (*this);
}
Intern::~Intern()
{
}
Form *Intern::makeForm(std::string name, std::string target)
{
    Form *listFunc[3] = {
        new ShrubberyCreationForm(target),
        new RobotomyRequestForm(target),
        new PresidentialPardonForm(target)};
    std::string listName[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"};
    Form *ret = 0;

    for (int i = 0; i < 3; i++)
    {
        if (!name.compare(listName[i]))
        {
            ret = listFunc[i];
        }
        else
        {
            delete listFunc[i];
        }
    }
    if (!ret)
    {
        std::cout << "Can't find the form" << std::endl;
    }
    else
    {
        std::cout << "Intern creates " << name << std::endl;
    }
    return ret;
}
