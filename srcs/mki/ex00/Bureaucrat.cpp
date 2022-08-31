/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 17:30:41 by mki               #+#    #+#             */
/*   Updated: 2021/08/15 21:01:36 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
    this->grade = grade;
}
Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name)
{
    grade = other.grade;
}
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    if (this != &other)
    {
        this->grade = other.grade;
    }
    grade = other.grade;
    return (*this);
}
Bureaucrat::~Bureaucrat()
{
}
const std::string Bureaucrat::getName() const
{
    return this->name;
}
int Bureaucrat::getGrade() const
{
    return this->grade;
}
void Bureaucrat::increment()
{
    if (grade == 1)
    {
        throw Bureaucrat::GradeTooHighException();
    }
    this->grade--;
}
void Bureaucrat::decrement()
{
    if (grade == 150)
    {
        throw Bureaucrat::GradeTooHighException();
    }
    this->grade++;
}
std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj)
{
    os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << std::endl;
    return (os);
}
