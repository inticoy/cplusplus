/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 21:44:39 by gyoon             #+#    #+#             */
/*   Updated: 2023/11/19 15:13:48 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("Presidential Pardon Form", 25, 5), target("temp")
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &pf)
    : AForm(pf.getName(), pf.getMinSignGrade(), pf.getMinExeGrade()),
      target(pf.target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : AForm("Presidential Pardon Form", 25, 5), target(target)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(
    const PresidentialPardonForm &pf)
{
    if (this != &pf)
    {
        this->setIsSigned(pf.getIsSigned());
        target = pf.target;
    }
    return *this;
}

void PresidentialPardonForm::execute(const Bureaucrat &e) const
    throw(GradeTooLowException, NotSignedException)
{
    checkRequirements(e);
    std::cout << target << " has been pardoned by Zaphod Beeblebrox";
}
