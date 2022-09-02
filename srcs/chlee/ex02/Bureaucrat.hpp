/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee <chlee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 00:37:26 by chlee             #+#    #+#             */
/*   Updated: 2021/03/28 14:46:35 by chlee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
class Bureaucrat;
# include "Form.hpp"

class Bureaucrat
{

	public:
		Bureaucrat(std::string name, int grade);
		Bureaucrat( Bureaucrat const & src );
		virtual ~Bureaucrat();

		class GradeTooHighException : public std::exception
		{
			virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			virtual const char* what() const throw();
		};

		void executeForm(Form const & form);
		void signForm(Form &form);
		void increaseGrade(void);
		void decreaseGrade(void);
		const std::string &getName() const;
		int			getGrade() const;
		Bureaucrat &		operator=( Bureaucrat const & rhs );

	private:
		Bureaucrat();
		const std::string	name_;
		int					grade_;

};

std::ostream &			operator<<( std::ostream & o, Bureaucrat const & i );

#endif /* ****************************************************** BUREAUCRAT_H */