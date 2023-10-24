/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 18:59:05 by gyoon             #+#    #+#             */
/*   Updated: 2023/10/24 16:29:30 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "MateriaSource.hpp"

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
    if (source)
    {
        source->loseMateria(this);
    }
    source = c.source;
    equipped = c.equipped;
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