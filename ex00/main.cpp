/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 07:04:52 by qdo               #+#    #+#             */
/*   Updated: 2024/06/10 07:22:38 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	try
	{
		Bureaucrat a("a", 160);
		a.gradeDecrement();
		std::cout << "11" << std::endl;
		std::cout << a << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException &e){
		std::cerr << e.what() << std::endl; }
	catch (const Bureaucrat::GradeTooLowException &e){
		std::cerr << e.what() << std::endl;
	}
}
