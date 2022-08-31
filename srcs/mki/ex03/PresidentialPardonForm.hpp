/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 13:38:49 by mki               #+#    #+#             */
/*   Updated: 2021/08/19 18:54:15 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIAL_PARDON_FORM_HPP
#define PRESIDENTIAL_PARDON_FORM_HPP

#include "Form.hpp"

class PresidentialPardonForm : public Form
{
private:
    std::string target;
    PresidentialPardonForm() : Form("presidential pardon", 25, 5), target("empty") {}

public:
    PresidentialPardonForm(std::string target);
    PresidentialPardonForm(const PresidentialPardonForm &p);
    PresidentialPardonForm &operator=(const PresidentialPardonForm &p);
    virtual ~PresidentialPardonForm();
    virtual void execute(Bureaucrat const &executor) const;
    std::string getTarget() const;
};

#endif
