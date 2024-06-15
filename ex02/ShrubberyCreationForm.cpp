/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 10:41:02 by qdo               #+#    #+#             */
/*   Updated: 2024/06/15 16:29:30 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <string>
ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm with the target `" << target << "' left" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("Default", 145, 137)
{
	std::cout << "ShrubberyCreationForm with the target `" << target << " is born" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string _name)
	: AForm("ShrubberyCreationForm", 145, 137), target(_name)
{
	std::string a = "unsigned";

	std::cout << "PresidentalForm with the target `" << target << "' is born. This form is "
			<< a << " , requires grade " << getGradeToSign() << " to sign and grade "
			<< getGradeToExecute() << " to execute." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src)
	: AForm("ShrubberyCreationForm", 145, 137), target(src.target)
{
	std::cout << "Another ShrubberyCreationForm with the target `" << target << " is born";
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & src)
{
	std::cout << "PresidentialPardonForm now changes it's target form " << target << " to " << src.target << std::endl;
	target = src.target;
	return (*this);
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor)  const
{
	if (checkIsSigned() == false)
		throw UnSigned(AForm::getName());
	if (executor.getGrade() > getGradeToExecute())
		throw GradeTooLowException(AForm::getName(), AForm::getGradeToExecute());
	std::string temp;
	temp = target + "_shrubbery";
	std::ofstream o_file(temp.c_str(), std::ios::trunc);
	if (o_file.is_open() == 0)
		std::cerr << "Target file `" << temp.c_str() << " can't be opened" << std::endl;
	else
	{
		o_file << "          v .   ._, |_  ., \n           `-._\\/  .  \\ /    |/_ \n               \\\\  _\\, y | \\// \n         _\\_.___\\, \\/ -.\\|| \n           `7-,--.`._||  / / , \n           /'     `-. `./ / |/_.' \n                     |    |// \n                     |_    / \n                     |-   | \n                     |   =| \n                     |    | \n--------------------/ ,  . \\--------._" << std::endl;
		o_file.close();
	}
}
