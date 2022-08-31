/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 19:54:37 by mki               #+#    #+#             */
/*   Updated: 2021/08/19 18:54:01 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBERRY_CREATION_FORM
#define SHRUBERRY_CREATION_FORM

#include "Form.hpp"

class ShrubberyCreationForm : public Form
{
private:
    std::string target;
    ShrubberyCreationForm() : Form("shrubbery creation", 145, 137), target("empty") {}

public:
    ShrubberyCreationForm(std::string target);
    ShrubberyCreationForm(const ShrubberyCreationForm &s);
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &s);
    virtual ~ShrubberyCreationForm();
    virtual void execute(Bureaucrat const &executor) const;
    std::string getTarget() const;
};

#endif
