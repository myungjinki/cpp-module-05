/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 21:17:19 by mki               #+#    #+#             */
/*   Updated: 2021/08/16 02:47:47 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP
#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Form
{
private:
    const std::string name;
    const int gradeSign;
    const int gradeExecute;
    bool sign;
    Form() : name("empty"), gradeSign(150), gradeExecute(150), sign(false) {}

public:
    Form(const std::string name, const int gradeSign, const int gradeExecute);
    Form(const Form &obj);
    Form &operator=(const Form &obj);
    ~Form();
    const std::string getName() const;
    int getGradeSign() const;
    int getGradeExecute() const;
    bool getSign() const;
    void beSigned(Bureaucrat &obj);
    class GradeTooHighException : public std::exception
    {
    public:
        virtual const char *what() const throw()
        {
            return "Exception: Form grade too high";
        }
    };
    class GradeTooLowException : public std::exception
    {
    public:
        virtual const char *what() const throw()
        {
            return "Exception: Form grade too low";
        }
    };
};

std::ostream &operator<<(std::ostream &os, const Form &obj);

#endif