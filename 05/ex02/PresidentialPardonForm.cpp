/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 21:44:39 by gyoon             #+#    #+#             */
/*   Updated: 2023/11/18 20:03:29 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
{
}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm &other)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

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
