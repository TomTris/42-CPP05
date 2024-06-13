/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 10:40:58 by qdo               #+#    #+#             */
/*   Updated: 2024/06/13 09:42:58 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm with the target `" << target << "' left"  << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm() : Form("Default", 25, 5)
{
	std::cout << "PresidentialPardonForm with the target `" << target << " is born"  << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string _name)
	: Form("PresidentialPardonForm", 25, 5), target(_name)
{
	std::string a = "unsigned";

	std::cout << "PresidentalForm with the target `" << target << "' is born. This form is "
			<< a << " , requires grade " << getGradeToSign() << " to sign and grade "
			<< getGradeToExecute() << " to execute." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src)
	: Form("PresidentialPardonForm", 25, 5), target(src.target)
{
	std::cout << "Another PresidentialPardonForm with the target `" << target << " is born";
}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & src)
{
	std::cout << "PresidentialPardonForm now changes it's target form " << target << " to " << src.target << std::endl;
	target = src.target;
	return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (checkIsSigned() == false)
		throw UnSigned(Form::getName());
	if (executor.getGrade() > getGradeToExecute())
		throw GradeTooLowException(Form::getName(), Form::getGradeToExecute());
	std::cout << target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}