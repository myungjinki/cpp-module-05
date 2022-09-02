/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee <chlee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 00:37:22 by chlee             #+#    #+#             */
/*   Updated: 2021/03/27 20:31:37 by chlee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
class Form;
# include "Bureaucrat.hpp"

class Form
{

	public:

		Form(std::string name, int signGrade, int execGrade);
		Form( Form const & src );
		virtual ~Form();

		class GradeTooHighException : public std::exception
		{
			virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			virtual const char *what() const throw();
		};

		class SignedValueFalseException : public std::exception
		{
			virtual const char *what() const throw();
		};

		virtual void	execute(Bureaucrat const & executor) const = 0;
		void 			copyMember(Form const &rhs);
		void			beSigned(Bureaucrat target);
		std::string		getName(void) const;
		bool			isSigned(void) const;
		int				getSignGrade(void) const;
		int				getExecGrade(void) const;

		Form &		operator=( Form const & rhs );

	private:
		Form();
		const std::string	name_;
		bool				signed_;
		const int			signGrade_;
		const int			execGrade_;
};

std::ostream &			operator<<( std::ostream & o, Form const & i );

#endif /* ************************************************************ FORM_H */