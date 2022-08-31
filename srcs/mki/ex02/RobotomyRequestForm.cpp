/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 19:54:48 by mki               #+#    #+#             */
/*   Updated: 2021/08/19 19:00:10 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("robotomy request", 72, 45)
{
    this->target = target;
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &r) : Form("robotomy request", 72, 45)
{
    this->target = r.getTarget();
}
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &r)
{
    if (this != &r)
    {
        this->target = r.getTarget();
        this->sign = r.getSign();
    }
    return (*this);
}
RobotomyRequestForm::~RobotomyRequestForm()
{
}
void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    if (this->getSign())
    {
        if (executor.getGrade() > this->getGradeExecute())
        {
            throw Form::GradeTooHighException();
        }
        else
        {
            std::cout << "<" << this->target << "> has been robotomized successfully 50%% of the time" << std::endl;
        }
    }
    else
    {
        std::cout << "Can't execute. Form not signed" << std::endl;
    }
}
std::string RobotomyRequestForm::getTarget() const
{
    return this->target;
}
