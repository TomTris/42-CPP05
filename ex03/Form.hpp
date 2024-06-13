/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 13:30:46 by qdo               #+#    #+#             */
/*   Updated: 2024/06/13 09:21:47 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Form_HPP
# define Form_HPP

#include <iostream>
#include "Bureaucrat.hpp"
#include <string>
#include <exception>
#include <fstream>

class Bureaucrat;

class Form {

private:
	std::string const name;
	bool isSigned;
	int	g_sign;
	int	g_exe;
	Form();

public:
	virtual ~Form();
	Form(std::string _name, int _g_sign, int _g_exe);
	Form(Form const & src);
	Form & operator=(Form const & src);

	class GradeTooLowException : public std::exception{
		private:
			std::string const name;
			int				g_exe;
		public:
			~GradeTooLowException() throw();
			GradeTooLowException(std::string FormName, int g_exe) throw();
			const char *what() const throw();
	};
	
	class UnSigned : public std::exception{
		private:
			std::string const name;
		public:
			~UnSigned() throw();
			UnSigned(std::string FormName) throw();
			const char *what() const throw();
	};

	std::string const getName() const;
	bool 	checkIsSigned() const;
	int 	getGradeToSign() const;
	int		getGradeToExecute() const;
	void	beSigned();
	virtual	void 	execute(Bureaucrat const & executor) const = 0;
};

std::ostream & operator<<(std::ostream &o, Form const &src);

#endif

// class GradeTooLowException : virtual public std::exception{
	// 	private:
	// 		std::string const name;
	// 		int			g_exe;
	// 	public:
	// 		~GradeTooLowException();
	// 		GradeTooLowException(std::string FormName, int _g_exe);
	// 		const char *what() const throw();
	// };