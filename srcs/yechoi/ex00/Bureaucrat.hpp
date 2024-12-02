/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yechoi <yechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 11:44:12 by yechoi            #+#    #+#             */
/*   Updated: 2020/11/21 21:02:00 by yechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>

class Bureaucrat
{
    private:
        const std::string   _name;
        int                 _grade;
        Bureaucrat();
    public:
        Bureaucrat(const std::string &name, int grade);
        Bureaucrat(const Bureaucrat& ref);
        Bureaucrat& operator=(const Bureaucrat& ref);
        virtual ~Bureaucrat();

        std::string         getName() const;
        int                 getGrade() const;

        void                upGrade();
        void                downGrade();

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw();

        };
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

};

std::ostream&   operator<<(std::ostream &os, const Bureaucrat &ref);

#endif