/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 09:43:11 by qdo               #+#    #+#             */
/*   Updated: 2024/06/12 10:36:57 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::~Form() {	std::cout << "Form " << name << " left";}
Form::Form() : name("Default"), isSigned(false), g_sign(1), g_exe(1)
{
		std::cout << "Form named `" << name
		<< "'is born. This form is unsigned, requires grade " << g_sign
		<< " to sign and grade "	<< g_exe << " to execute." << std::endl;
}

Form::Form(std::string _name, bool _isSigned, int _g_sign, int _g_exe)
	: name(_name), isSigned(_isSigned), g_sign(_g_sign), g_exe(_g_exe)
{
	if (_g_sign > 150 || g_exe > 150)
		throw Form::GradeTooLowExeption();
	if (_g_sign < 1 || g_exe < 1)
		throw Form::GradeTooHighExeption();
	
	std::string a;
	if (isSigned == false)
		a = "unsigned";
	else
		a = "signed";

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

const char *Form::GradeTooLowExeption::what() const throw() { return ("It's too low, the grade should be in range 1-150"); }
const char *Form::GradeTooHighExeption::what() const throw() { return ("It's too high, the grade should be in range 1-150"); }

std::ostream & operator<<(std::ostream &o, Form const &src)
{
	std::string a;

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

void	Form::setSigned() {isSigned = true;}
