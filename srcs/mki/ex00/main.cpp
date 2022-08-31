/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 03:12:10 by mki               #+#    #+#             */
/*   Updated: 2021/08/15 21:07:42 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void highTest()
{
    Bureaucrat high = Bureaucrat("high", 2);

    try
    {
        std::cout << high;
        high.increment();
        std::cout << high;
        high.increment();
        std::cout << high;
        std::cout << high;
        std::cout << high;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}

void lowTest()
{
    Bureaucrat low = Bureaucrat("low", 149);

    try
    {
        std::cout << low;
        low.decrement();
        std::cout << low;
        low.decrement();
        std::cout << low;
        std::cout << low;
        std::cout << low;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}

int main()
{
    highTest();
    lowTest();
    return (0);
}