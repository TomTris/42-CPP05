/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 06:09:52 by qdo               #+#    #+#             */
/*   Updated: 2024/06/10 07:20:12 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat {

private:
	std::string const	name;
	int					grade;

public:
	~Bureaucrat();
	Bureaucrat();
	Bureaucrat(std::string _name, int _grade);
	Bureaucrat(Bureaucrat const & src);

	Bureaucrat & operator=(Bureaucrat const & src);
	std::string const getName(void) const;
	int	getGrade(void) const;
	void gradeIncrement(void);
	void gradeDecrement(void);

	class GradeTooHighException : std::exception{
		public:
			const char *what() const throw();
	};

	class GradeTooLowException : std::exception{
		public:
			const char *what() const throw();
	};
};

std::ostream & operator<<(std::ostream &o, Bureaucrat const & src);

#endif
