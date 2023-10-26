/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 16:10:41 by gyoon             #+#    #+#             */
/*   Updated: 2023/10/26 16:14:18 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "MateriaSource.hpp"

AMateria::AMateria()
{
    type = "No Type";
    source = NULL;
    equipped = false;
}

AMateria::AMateria(const AMateria &m)
{
    type = m.type;
    source = m.source;
    equipped = m.equipped;
}

AMateria::AMateria(std::string const &type)
{
    this->type = type;
    source = NULL;
    equipped = false;
}

AMateria::~AMateria()
{
}

AMateria &AMateria::operator=(const AMateria &m)
{
    if (source)
    {
        source->loseMateria(this);
    }
    source = m.source;
    equipped = m.equipped;
    return *this;
}

MateriaSource *AMateria::getSource()
{
    return source;
}

void AMateria::setSource(MateriaSource *ms)
{
    source = ms;
}

bool AMateria::getEquipped()
{
    return equipped;
}

void AMateria::setEquipped()
{
    equipped = true;
}

void AMateria::setRemoved()
{
    equipped = false;
}

std::string const &AMateria::getType() const
{
    return type;
}

void AMateria::use(ICharacter &target)
{
    std::cout << "* Materia does sth to " << target.getName() << " *\n";
}