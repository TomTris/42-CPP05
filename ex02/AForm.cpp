/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 09:43:11 by qdo               #+#    #+#             */
/*   Updated: 2024/06/12 10:36:57 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::~AForm() { std::cout << "Form " << name << " left"; }
AForm::AForm() : name("Default"), isSigned(false), g_sign(1), g_exe(1) {}

AForm::AForm(std::string _name, int _g_sign, int _g_exe)
	: name(_name), g_sign(_g_sign), g_exe(_g_exe)
{
	std::string a;
		a = "unsigned";

	std::cout << "Form named `" << name << "' is born. This form is "
			<< a << " , requires grade " << g_sign << " to sign and grade "
			<< g_exe << " to execute." << std::endl;
}

AForm::AForm(AForm const & src) : name(src.getName())
{
	*this = src;
}

std::string const AForm::getName() const {return name;}
bool AForm::checkIsSigned(void) const { return isSigned; }
int	AForm::getGradeToSign() const {return g_sign; }
int AForm::getGradeToExecute() const {return g_exe; }

AForm::GradeTooLowException::GradeTooLowException(std::string AFormName, int g_exe) throw()
	: name(AFormName), g_exe(g_exe) {}
const char *AForm::GradeTooLowException::what() const throw()
{
	static std::string a;

	a = "The Grade is too low, it must be at least " + std::to_string(g_exe) + " to execute " + name;
	return (a.c_str());
}

AForm::UnSigned::UnSigned(std::string AFormName) throw() : name(AFormName) {}
const char *AForm::UnSigned::what() const throw()
{
	std::string static a = "This " + name + " is not signed yet";
	return (a.c_str());
}

std::ostream & operator<<(std::ostream &o, AForm const &src)
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

AForm & AForm::operator=(AForm const & src)
{
	std::cout << "Copy Assignment called" << std::endl;
	g_exe = src.getGradeToExecute();
	g_sign = src.getGradeToExecute();
	isSigned = src.checkIsSigned();
	return (*this);
}

void	AForm::beSigned() {isSigned = true;}

