/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 18:59:05 by gyoon             #+#    #+#             */
/*   Updated: 2023/10/22 16:30:45 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
    // std::cout << "Cure Default Constructor called.\n";
}

Cure::Cure(const Cure &c) : AMateria(c.type)
{
    // std::cout << "Cure Copy Constructor called.\n";
}

Cure::~Cure()
{
    // std::cout << "Cure Destructor called.\n";
}

Cure &Cure::operator=(const Cure &c)
{
    // std::cout << "Cure Assignment Operator called.\n";
    type = c.type;
    return *this;
}

AMateria *Cure::clone() const
{
    return new Cure(*this);
}

void Cure::use(ICharacter &target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *\n";
}