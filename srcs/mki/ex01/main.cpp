/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 03:12:10 by mki               #+#    #+#             */
/*   Updated: 2021/08/16 02:53:48 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int main()
{
    Bureaucrat cat("cat", 25);
    Form important("important", 10, 10);
    Form normal("normal", 50, 50);

    try
    {
        std::cout << important;
        cat.signForm(important);
        std::cout << important;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        std::cout << normal;
        cat.signForm(normal);
        std::cout << normal;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return (0);
}