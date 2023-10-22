/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Amateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 16:10:41 by gyoon             #+#    #+#             */
/*   Updated: 2023/10/22 16:28:10 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
    // std::cout << "AMateria Default Constructor called.\n";
    type = "No Type";
}

AMateria::AMateria(const AMateria &m)
{
    // std::cout << "AMateria Copy Constructor called.\n";
    type = m.type;
}

AMateria::AMateria(std::string const &type)
{
    // std::cout << "AMateria Type Constructor called.\n";
    this->type = type;
}

AMateria::~AMateria()
{
    // std::cout << "AMateria Destructor called.\n";
}

AMateria &AMateria::operator=(const AMateria &a)
{
    // std::cout << "AMateria Assignment Operator called.\n";
    type = a.type;
    return *this;
}

std::string const &AMateria::getType() const
{
    return type;
}

void AMateria::use(ICharacter &target)
{
    std::cout << "* Materia does sth to <name> *\n";
}