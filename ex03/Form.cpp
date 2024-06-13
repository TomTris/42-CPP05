/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 09:43:11 by qdo               #+#    #+#             */
/*   Updated: 2024/06/13 09:42:58 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::~Form() { }
Form::Form() : name("Default"), isSigned(false), g_sign(1), g_exe(1) {}

Form::Form(std::string _name, int _g_sign, int _g_exe)
	: name(_name), g_sign(_g_sign), g_exe(_g_exe)
{
	std::string a;
		a = "unsigned";

	std::cout << "Form named `" << name << "' is born. This form is "
			<< a << " , requires grade " << g_sign << " to sign and grade "
			<< g_exe << " to execute." << std::endl;
}

Form::Form(Form const & src) : name(src.getName())
{
	*this = src;
}

std::string const Form::getName() const {return name;}
bool Form::checkIsSigned(void) const { return isSigned; }
int	Form::getGradeToSign() const {return g_sign; }
int Form::getGradeToExecute() const {return g_exe; }

Form::GradeTooLowException::~GradeTooLowException() throw() {}
Form::GradeTooLowException::GradeTooLowException(std::string FormName, int g_exe) throw()
	: name(FormName), g_exe(g_exe) {}
const char *Form::GradeTooLowException::what() const throw()
{
	static std::string a;

	a = "The Grade is too low, it must be at least " + std::to_string(g_exe) + " to execute " + name;
	return (a.c_str());
}

Form::UnSigned::~UnSigned() throw() {}
Form::UnSigned::UnSigned(std::string FormName) throw() : name(FormName) {}
const char *Form::UnSigned::what() const throw()
{
	std::string static a;

	a = "This " + name + " is not signed yet";
	return (a.c_str());
}

std::ostream & operator<<(std::ostream &o, Form const &src)
{
	static std::string a;

	if (src.checkIsSigned() == false)
		a = "unsigned";
	else
		a = "signed";

	o << "Form named `" << src.getName() << "' is " << a
		<< ". Grade " << src.getGradeToSign() << " required to sign and Grade "
		<< src.getGradeToExecute() << " to execute" << std::endl;
	return (o);
}

Form & Form::operator=(Form const & src)
{
	std::cout << "Copy Assignment called" << std::endl;
	g_exe = src.getGradeToExecute();
	g_sign = src.getGradeToExecute();
	isSigned = src.checkIsSigned();
	return (*this);
}

void	Form::beSigned() {isSigned = true;}

