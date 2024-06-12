/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 13:30:46 by qdo               #+#    #+#             */
/*   Updated: 2024/06/12 09:58:15 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"
#include <string>

class Bureaucrat;

class Form {

private:
	std::string const name;
	bool isSigned;
	int	g_sign;
	int	g_exe;

public:
	~Form();
	Form();
	Form(std::string _name, bool _isSigned, int _g_sign, int _g_exe);
	Form(Form const & src);
	Form & operator=(Form const & src);

	class GradeTooHighExeption : public std::exception{
		public:
			const char *what() const throw();
	};
	class GradeTooLowExeption : public std::exception{
		public:
			const char *what() const throw();
	};

	std::string const getName() const;
	bool checkIsSigned() const;
	int getGradeToSign() const;
	int	getGradeToExecute() const;
	void	setSigned();
};

std::ostream & operator<<(std::ostream &o, Form const &src);

#endif
