/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 21:44:39 by gyoon             #+#    #+#             */
/*   Updated: 2023/11/30 16:39:48 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("Presidential Pardon", 25, 5), target("noname")
{
}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm &other)
    : AForm(other.getName(), other.getMinSignGrade(), other.getMinExeGrade()),
      target(other.target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : AForm("Presidential Pardon", 25, 5), target(target)
{
}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm &PresidentialPardonForm::operator=(
    const PresidentialPardonForm &other)
{
    if (this != &other)
    {
        this->setIsSigned(other.getIsSigned());
        target = other.target;
    }
    return *this;
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const
    throw(GradeTooLowException, NotSignedException, ExecuteFailException)
{
    checkRequirements(executor);
    std::cout << target << " has been pardoned by Zaphod Beeblebrox" << '\n';
}
