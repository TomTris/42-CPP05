/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 10:41:03 by qdo               #+#    #+#             */
/*   Updated: 2024/06/13 09:35:24 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {

private:
	std::string target;
	ShrubberyCreationForm();
	ShrubberyCreationForm(ShrubberyCreationForm const & src);
	ShrubberyCreationForm & operator=(ShrubberyCreationForm const & src);

public:
	~ShrubberyCreationForm();
	ShrubberyCreationForm(std::string _name);

	void execute(Bureaucrat const & executor) const;
};

std::ostream & operator<<(std::ostream &o, ShrubberyCreationForm const &src);

#endif
