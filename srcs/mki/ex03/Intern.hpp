/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 06:20:02 by mki               #+#    #+#             */
/*   Updated: 2021/08/20 06:29:38 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP
#include "Form.hpp"

class Intern
{
private:
public:
    Intern();
    Intern(const Intern &i);
    Intern &operator=(const Intern &i);
    ~Intern();
    Form *makeForm(std::string name, std::string target);
};

#endif
