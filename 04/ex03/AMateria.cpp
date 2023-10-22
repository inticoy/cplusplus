/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 16:10:41 by gyoon             #+#    #+#             */
/*   Updated: 2023/10/22 20:26:19 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
    // std::cout << "AMateria Default Constructor called.\n";
    type = "No Type";
    equipped = false;
}

AMateria::AMateria(const AMateria &m)
{
    // std::cout << "AMateria Copy Constructor called.\n";
    type = m.type;
    equipped = m.equipped;
}

AMateria::AMateria(std::string const &type)
{
    // std::cout << "AMateria Type Constructor called.\n";
    this->type = type;
    equipped = false;
}

AMateria::~AMateria()
{
    // std::cout << "AMateria Destructor called.\n";
}

AMateria &AMateria::operator=(const AMateria &a)
{
    // std::cout << "AMateria Assignment Operator called.\n";
    type = a.type;
    equipped = a.equipped;
    return *this;
}

void AMateria::setEquipped()
{
    equipped = true;
}

void AMateria::setRemoved()
{
    equipped = false;
}

bool AMateria::getEquipped()
{
    return equipped;
}

std::string const &AMateria::getType() const
{
    return type;
}

void AMateria::use(ICharacter &target)
{
    std::cout << "* Materia does sth to <name> *\n";
}