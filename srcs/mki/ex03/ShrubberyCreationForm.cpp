/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 19:41:47 by mki               #+#    #+#             */
/*   Updated: 2021/08/19 19:09:30 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("shrubbery creation", 145, 137)
{
    this->target = target;
}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &s) : Form("shrubbery creation", 145, 137)
{
    this->target = s.getTarget();
}
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &s)
{
    if (this != &s)
    {
        this->target = s.getTarget();
        this->sign = s.getSign();
    }
    return (*this);
}
ShrubberyCreationForm::~ShrubberyCreationForm()
{
}
void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if (this->getSign())
    {
        if (executor.getGrade() > this->getGradeSign())
        {
            throw Form::GradeTooHighException();
        }
        else
        {
            std::ofstream writeFile;
            writeFile.open(this->target + "_shrubbery");
            writeFile << "        t     " << std::endl;
            writeFile << "       .#.     " << std::endl;
            writeFile << "      .###.     " << std::endl;
            writeFile << "     .#%##%.     " << std::endl;
            writeFile << "    .%##%###.     " << std::endl;
            writeFile << "   .##%###%##.     " << std::endl;
            writeFile << "  .#%###%##%##.     " << std::endl;
            writeFile << "        #     " << std::endl;
            writeFile << "        #     " << std::endl;
            writeFile.close();
        }
    }
    else
    {
        std::cout << "Can't execute. Form not signed" << std::endl;
    }
}
std::string ShrubberyCreationForm::getTarget() const
{
    return this->target;
}
