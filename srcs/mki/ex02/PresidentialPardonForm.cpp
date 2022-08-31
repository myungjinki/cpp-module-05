/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 19:54:51 by mki               #+#    #+#             */
/*   Updated: 2021/08/19 18:58:46 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("robotomy request", 25, 5)
{
    this->target = target;
}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &p) : Form("robotomy request", 25, 5)
{
    this->target = p.getTarget();
}
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &p)
{
    if (this != &p)
    {
        this->target = p.getTarget();
        this->sign = p.getSign();
    }
    return (*this);
}
PresidentialPardonForm::~PresidentialPardonForm()
{
}
void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    if (this->getSign())
    {
        if (executor.getGrade() > this->getGradeExecute())
        {
            throw Form::GradeTooHighException();
        }
        else
        {
            std::cout << "<" << this->target << "> has been pardoned by Zafod Beeblebrox" << std::endl;
        }
    }
    else
    {
        std::cout << "Can't execute. Form not signed" << std::endl;
    }
}
std::string PresidentialPardonForm::getTarget() const
{
    return this->target;
}
