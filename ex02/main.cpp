/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 07:04:52 by qdo               #+#    #+#             */
/*   Updated: 2024/06/13 09:37:36 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	Bureaucrat president("Zaphod Beeblebrox", 1);
	Bureaucrat lowly_scribe("Hannah Mckay", 150);

	ShrubberyCreationForm  bushes("frontyard");
	PresidentialPardonForm whistleblower("Julien Assange");
	RobotomyRequestForm    frankenstein("C-3PO");
	
	std::cout << "----------------------------------------" << std::endl;
		lowly_scribe.signForm(bushes);
		lowly_scribe.signForm(whistleblower);
		lowly_scribe.signForm(frankenstein);

		std::cout << "-----" << std::endl;

		president.executeForm(bushes);
		president.executeForm(whistleblower);
		president.executeForm(frankenstein);

		std::cout << "-----" << std::endl;
		president.signForm(bushes);
		president.signForm(whistleblower);
		president.signForm(frankenstein);
		std::cout << "-----" << std::endl;
		
		president.executeForm(bushes);
		std::cout << "+" << std::endl;
		president.executeForm(whistleblower);
		std::cout << "+" << std::endl;
		president.executeForm(frankenstein);
		std::cout << "+" << std::endl;
	
		std::cout << "-----" << std::endl;
		lowly_scribe.executeForm(bushes);
		lowly_scribe.executeForm(whistleblower);
		lowly_scribe.executeForm(frankenstein);
		// std::cout << "-----" << std::endl;

	std::cout << "----------------------------------------" << std::endl;
	return 0;
}
