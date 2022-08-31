/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 02:17:28 by mki               #+#    #+#             */
/*   Updated: 2021/08/16 02:48:32 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(const std::string name, const int gradeSign, const int gradeExecute)
    : name(name), gradeSign(gradeSign), gradeExecute(gradeExecute)
{
    if (this->gradeSign < 1 || this->gradeExecute < 1)
    {
        throw Form::GradeTooHighException();
    }
    else if (this->gradeSign > 150 || this->gradeExecute > 150)
    {
        throw Form::GradeTooLowException();
    }
    sign = false;
}
Form::Form(const Form &obj)
    : name(obj.getName()), gradeSign(obj.getGradeSign()), gradeExecute(obj.getGradeExecute())
{
    sign = obj.getSign();
}
Form &Form::operator=(const Form &obj)
{
    if (this != &obj)
    {
        sign = obj.getSign();
    }
    return (*this);
}
Form::~Form()
{
}
const std::string Form::getName() const
{
    return this->name;
}
int Form::getGradeSign() const
{
    return this->gradeSign;
}
int Form::getGradeExecute() const
{
    return this->gradeExecute;
}
bool Form::getSign() const
{
    return this->sign;
}
void Form::beSigned(Bureaucrat &obj)
{
    if (obj.getGrade() > this->getGradeSign())
    {
        throw Form::GradeTooLowException();
    }
    this->sign = true;
}
std::ostream &operator<<(std::ostream &os, const Form &obj)
{
    os << "----------------------------" << std::endl;
    os << "Form: " << obj.getName() << std::endl;
    os << "Grade Sign: " << obj.getGradeSign() << std::endl;
    os << "Grade Execute: " << obj.getGradeExecute() << std::endl;
    if (obj.getSign())
        os << "Is Signed: TRUE" << std::endl;
    else
        os << "Is Signed: FALSE" << std::endl;
    os << "----------------------------" << std::endl;
    return (os);
}