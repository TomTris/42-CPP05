/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 07:03:38 by qdo               #+#    #+#             */
/*   Updated: 2024/06/10 07:03:39 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


Bureaucrat::~Bureaucrat()
{
	std::cout << "Bruceaucrat `" << name << "' with grade " << grade << " left" << std::endl;
}

Bureaucrat::Bureaucrat(void) : name("Default"), grade(150)
{
	std::cout << "Bureaucrat named " << name << " with grade " << grade << " was born" << std::endl;
}

Bureaucrat::Bureaucrat(std::string _name, int _grade) : name(_name), grade(_grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	std::cout << "Bureaucrat named " << name << " with grade " << grade << " was born" << std::endl;
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & src)
{
	this->grade = src.grade;
	std::cout << "Bureaucrat " << this->name << " now has same grade " << this->grade << " as " << src.grade << "'s grade" << std::endl;
}

void	Bureaucrat::gradeIncrement()
{
	if (this->grade == 1)
		throw Bureaucrat::GradeTooLowException();
	this->grade -= 1;
}

void	Bureaucrat::gradeDecrement()
{
	if (this->grade == 150)
		throw Bureaucrat::GradeTooHighException();
	this->grade += 1;
}

std::string Bureaucrat::getName()
{
	return (this->name);
}

int	Bureaucrat::getGrade()
{
	return (this->grade);
}