/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 13:30:46 by qdo               #+#    #+#             */
/*   Updated: 2024/06/13 09:04:42 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"
#include <string>
#include <exception>
#include <fstream>

class Bureaucrat;

class AForm {

private:
	std::string const name;
	bool isSigned;
	int	g_sign;
	int	g_exe;
	AForm();

public:
	virtual ~AForm();
	AForm(std::string _name, int _g_sign, int _g_exe);
	AForm(AForm const & src);
	AForm & operator=(AForm const & src);

	class GradeTooLowException : public std::exception{
		private:
			std::string const name;
			int				g_exe;
		public:
			~GradeTooLowException() throw();
			GradeTooLowException(std::string AFormName, int g_exe) throw();
			const char *what() const throw();
	};
	
	class UnSigned : public std::exception{
		private:
			std::string const name;
		public:
			~UnSigned() throw();
			UnSigned(std::string AFormName) throw();
			const char *what() const throw();
	};

	virtual std::string const getName() const;
	virtual bool 	checkIsSigned() const = 0;
	virtual int 	getGradeToSign() const;
	virtual int		getGradeToExecute() const;
	virtual void	beSigned();
	virtual	void 	execute(Bureaucrat const & executor) const;
};

std::ostream & operator<<(std::ostream &o, AForm const &src);

#endif

// class GradeTooLowException : virtual public std::exception{
	// 	private:
	// 		std::string const name;
	// 		int			g_exe;
	// 	public:
	// 		~GradeTooLowException();
	// 		GradeTooLowException(std::string AFormName, int _g_exe);
	// 		const char *what() const throw();
	// };