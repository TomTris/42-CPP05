/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 07:04:52 by qdo               #+#    #+#             */
/*   Updated: 2024/06/13 10:51:03 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main(void)
{
	Intern intern;
	Form *form;

	form = intern.makeForm("shrubbery creation", "home");
	std::cout << "----" << std::endl;
	if (form)
	{
		Bureaucrat bob("Bob", 136);
		Bureaucrat john("John", 145);

		std::cout << "----" << std::endl;

		john.signForm(*form);
		bob.executeForm(*form);
		
		std::cout << "----" << std::endl;
		
		delete form;
	}
	std::cout << "----" << std::endl;
	return 0;
}
