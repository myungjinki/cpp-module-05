/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 19:41:38 by mki               #+#    #+#             */
/*   Updated: 2021/08/19 18:54:12 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMY_REQUEST_FORM_HPP
#define ROBOTOMY_REQUEST_FORM_HPP

#include "Form.hpp"

class RobotomyRequestForm : public Form
{
private:
    std::string target;
    RobotomyRequestForm() : Form("robotomy request", 72, 45), target("empty") {}

public:
    RobotomyRequestForm(std::string target);
    RobotomyRequestForm(const RobotomyRequestForm &r);
    RobotomyRequestForm &operator=(const RobotomyRequestForm &r);
    virtual ~RobotomyRequestForm();
    virtual void execute(Bureaucrat const &executor) const;
    std::string getTarget() const;
};

#endif
