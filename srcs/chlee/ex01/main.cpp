/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee <chlee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 13:41:25 by chlee             #+#    #+#             */
/*   Updated: 2021/03/28 14:42:59 by chlee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	//coplien form test
	Form form1 = Form("42 club jiphyeonjeon's form", 20, 80);
	Form form2 = Form("chlee's first form", 80, 20);
	Form form3 = Form("chlee's second form", 20, 20);
	Form form4 = Form("chlee's third form", 80, 80);

	Bureaucrat grade_high = Bureaucrat("high", 1);
	Bureaucrat grade_mid = Bureaucrat("mid", 75);
	Bureaucrat grade_low = Bureaucrat("low", 150);

	//exception test
	grade_low.signForm(form1);
	grade_low.signForm(form2);
	grade_low.signForm(form3);
	grade_low.signForm(form4);
	std::cout << std::endl;

	//exception test2
	grade_mid.signForm(form2);
	grade_mid.signForm(form4);
	grade_mid.signForm(form1);
	grade_mid.signForm(form3);
	std::cout << std::endl;

	//beSigned, signForm test
	grade_high.signForm(form1);
	grade_high.signForm(form2);
	grade_high.signForm(form3);
	grade_high.signForm(form4);
	std::cout << std::endl;

	//after signed, if grade low signForm, this result what?
	grade_low.signForm(form1);
	grade_low.signForm(form2);
	return (0);
}