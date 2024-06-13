/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 09:40:19 by qdo               #+#    #+#             */
/*   Updated: 2024/06/13 10:48:15 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::~Intern()
{
	std::cout << "An Intern left because of working 100Hours per week" << std::endl;
}

Intern::Intern()
{
	std::cout << "An new unexperienced Intern came" << std::endl;
}

Intern::Intern(Intern const & src)
{
	(void) src;
	std::cout << "An new unexperienced Intern came with same hope of another Intern" << std::endl;
}

Intern & Intern::operator=(Intern const & src)
{
	(void) src;
	return (*this);
}

Form* Intern::makeForm(std::string const name, std::string target)
{
	std::string a[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};
	int i;

	i = -1;
	while (++i < 3)
		if (a[i] == name)
			break ;
	switch (i)
	{
		case 0:
			return (new RobotomyRequestForm(target));
		case 1:
			return (new PresidentialPardonForm(target));
		case 2:
			return (new ShrubberyCreationForm(target));
		default:
			std::cerr << "Form " << name << "doesn't exist" << std::endl;

	}
	return (NULL);
}
