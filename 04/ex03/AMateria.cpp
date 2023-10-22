/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 16:10:41 by gyoon             #+#    #+#             */
/*   Updated: 2023/10/22 22:42:28 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
    type = "No Type";
    source = NULL;
}

AMateria::AMateria(const AMateria &m)
{
    type = m.type;
    // source = NULL;
}

AMateria::AMateria(std::string const &type)
{
    this->type = type;
    source = NULL;
}

AMateria::~AMateria()
{
}

AMateria &AMateria::operator=(const AMateria &a)
{
    type = a.type;
    // source = NULL;
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

std::string const &AMateria::getType() const
{
    return type;
}

void AMateria::use(ICharacter &target)
{
    std::cout << "* Materia does sth to <name> *\n";
}