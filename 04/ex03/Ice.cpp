/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 18:52:06 by gyoon             #+#    #+#             */
/*   Updated: 2023/10/24 16:29:47 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "MateriaSource.hpp"

Ice::Ice() : AMateria("ice")
{
}

Ice::Ice(const Ice &i) : AMateria(i.type)
{
}

Ice::~Ice()
{
}

Ice &Ice::operator=(const Ice &i)
{
    if (source)
    {
        source->loseMateria(this);
    }
    source = i.source;
    equipped = i.equipped;
    return *this;
}

AMateria *Ice::clone() const
{
    return new Ice(*this);
}

void Ice::use(ICharacter &target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}