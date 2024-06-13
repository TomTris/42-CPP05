/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 10:40:59 by qdo               #+#    #+#             */
/*   Updated: 2024/06/13 09:35:17 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {

private:
	std::string target;
	PresidentialPardonForm();
	PresidentialPardonForm(PresidentialPardonForm const & src);
	PresidentialPardonForm & operator=(PresidentialPardonForm const & src);

public:
	~PresidentialPardonForm();
	PresidentialPardonForm(std::string _name);

	void execute(Bureaucrat const & executor) const;
};

std::ostream & operator<<(std::ostream &o, PresidentialPardonForm const &src);

#endif