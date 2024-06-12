/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 07:04:52 by qdo               #+#    #+#             */
/*   Updated: 2024/06/12 10:18:06 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	{
		try
		{
			Bureaucrat Ali("Ali", 1);
			Form form1("Top secret",false, 2, 1);
			Ali.signForm(form1);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	std::cout << "--------------" << std::endl;
	{
		try
		{
			Bureaucrat Ali("Ali", 9);
			Form form1("Top secret", false, 8, 1);
			Ali.signForm(form1);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
}
