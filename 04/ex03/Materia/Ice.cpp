/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 18:52:06 by gyoon             #+#    #+#             */
/*   Updated: 2023/10/21 19:29:12 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
    std::cout << "Ice Default Constructor called.\n";
}

Ice::Ice(const Ice &i) : AMateria(i.type)
{
    std::cout << "Ice Copy Constructor called.\n";
}

Ice::~Ice()
{
    std::cout << "Ice Destructor called.\n";
}

Ice &Ice::operator=(const Ice &i)
{
    std::cout << "Ice Assignment Operator called.\n";
    type = i.type;
    return *this;
}

AMateria *Ice::clone() const
{
    return new Ice(*this);
}

void Ice::use(ICharacter &target)
{
    std::cout << "* shoots an ice bolt at <name> *\n";
}