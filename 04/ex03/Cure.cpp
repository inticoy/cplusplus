/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 18:59:05 by gyoon             #+#    #+#             */
/*   Updated: 2023/10/24 13:39:39 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
}

Cure::Cure(const Cure &c) : AMateria(c.type)
{
}

Cure::~Cure()
{
}

Cure &Cure::operator=(const Cure &c)
{
    // TODO
    std::cout << c.type << std::endl;
    return *this;
}

AMateria *Cure::clone() const
{
    AMateria *ret = new Cure(*this);
    ret->setSource(this->source);
    return ret;
}

void Cure::use(ICharacter &target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *\n";
}