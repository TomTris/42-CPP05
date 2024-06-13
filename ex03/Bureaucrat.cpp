/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 07:03:38 by qdo               #+#    #+#             */
/*   Updated: 2024/06/13 09:42:58 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

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
	if (grade < 1) 		throw Bureaucrat::GradeTooHighException();
	if (grade > 150) 		throw Bureaucrat::GradeTooLowException();

	std::cout << "Bureaucrat named `" << name << "' with grade " << grade << " was born" << std::endl;
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & src)
{
	this->grade = src.grade;
	std::cout << "Bureaucrat `" << this->name << "' now has same grade "
			<< this->grade << " as " << src.grade << "'s grade" << std::endl;
	return (*this);
}

void	Bureaucrat::gradeIncrement()
{
	if (this->grade == 1) throw Bureaucrat::GradeTooLowException();
	this->grade -= 1;
}

void	Bureaucrat::gradeDecrement()
{
	if (this->grade == 150) throw Bureaucrat::GradeTooHighException();
	this->grade += 1;
}

std::string const Bureaucrat::getName() const	{	return (this->name);	}
int	Bureaucrat::getGrade() const {		return (this->grade);	}
const char *Bureaucrat::GradeTooHighException::what() const throw()	{	return "The Grade too low (> 150)";	}
const char *Bureaucrat::GradeTooLowException::what() const throw()	{	return "The Grade too high, (< 1)";	}

std::ostream & operator<<(std::ostream &o, Bureaucrat const & src)
{
	o << "This is Bureaucrat `" << src.getName() << "' with Grade " << src.getGrade();
	return (o);
}

void Bureaucrat::signForm(Form & src) const
{
	if (src.checkIsSigned() == true)
	{
		std::cerr << name << " coudn't sign `" << src.getName()
				<< "' because the Form is already signed" << std::endl;
		return ; 
	}
	if (grade <= src.getGradeToSign())
	{
		src.beSigned();
		std::cout << name << " signed the form `"
				<< src.getName() << "'" << std::endl;
	}
	else
		std::cerr << name << "'s grade is too low to sign form `" << src.getName() << "'" << std::endl;
}

void Bureaucrat::executeForm(Form const & form)
{
	try
	{
		form.execute(*this);
		std::cout << name << " executed " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
