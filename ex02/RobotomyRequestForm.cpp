/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 10:41:00 by qdo               #+#    #+#             */
/*   Updated: 2024/06/13 09:24:02 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm with the target `" << target << "' left"  << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm() : AForm("Default", 72, 45)
{
	std::cout << "RobotomyRequestForm with the target `" << target << " is born"  << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string _name)
	: AForm("RobotomyRequestForm", 72, 45), target(_name)
{
	std::string a = "unsigned";

	std::cout << "PresidentalForm with the target `" << target << "' is born. This form is "
			<< a << " , requires grade " << getGradeToSign() << " to sign and grade "
			<< getGradeToExecute() << " to execute." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src)
	: AForm("RobotomyRequestForm", 72, 45), target(src.target)
{
	std::cout << "Another RobotomyRequestForm with the target `" << target << " is born";
}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & src)
{
	std::cout << "RobotomyRequestForm now changes it's target form " << target << " to " << src.target << std::endl;
	target = src.target;
	return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor)  const
{
	if (checkIsSigned() == false)
		throw UnSigned(AForm::getName());
	if (executor.getGrade() > getGradeToExecute())
		throw GradeTooLowException(AForm::getName(), AForm::getGradeToExecute());
	std::cout << "zhzhzhzhzhzhzhzhzhzhzh" << std::endl;
	std::srand(std::time(nullptr));
    int random_value = std::rand() % 2;
	if (random_value == 1)
		std::cout << "The Robotomy failed" << std::endl;
	else
		std::cout << AForm::getName() << " has been robotomized successfully 50% of the time" << std::endl;
}
