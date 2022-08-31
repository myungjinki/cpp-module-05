/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 19:49:32 by mki               #+#    #+#             */
/*   Updated: 2021/08/16 02:11:30 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class Form;

class Bureaucrat
{
private:
    const std::string name;
    int grade;
    Bureaucrat(){};

public:
    // Coplien's form
    ~Bureaucrat();
    Bureaucrat(std::string name, int grade);
    Bureaucrat(const Bureaucrat &other);
    Bureaucrat &operator=(const Bureaucrat &other);
    // Member function
    const std::string getName() const;
    int getGrade() const;
    void increment();
    void decrement();
    void signForm(Form &f);
    // Exception class
    class GradeTooHighException : public std::exception
    {
    public:
        virtual const char *what() const throw()
        {
            return "Exception: Bureaucrat grade too high";
        }
    };
    class GradeTooLowException : public std::exception
    {
    public:
        virtual const char *what() const throw()
        {
            return "Exception: Bureaucrat grade too low";
        }
    };
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj);

#endif
