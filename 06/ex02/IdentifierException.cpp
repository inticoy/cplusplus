/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IdentifierException.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 15:40:37 by gyoon             #+#    #+#             */
/*   Updated: 2023/12/03 22:52:23 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Identifier.hpp"

Identifier::ClassAException::ClassAException() throw() : msg("class A") {}

Identifier::ClassAException::~ClassAException() throw() {}

const char *Identifier::ClassAException::what() const throw()
{
    return msg.c_str();
}

Identifier::ClassBException::ClassBException() throw() : msg("class B") {}

Identifier::ClassBException::~ClassBException() throw() {}

const char *Identifier::ClassBException::what() const throw()
{
    return msg.c_str();
}

Identifier::ClassCException::ClassCException() throw() : msg("class C") {}

Identifier::ClassCException::~ClassCException() throw() {}

const char *Identifier::ClassCException::what() const throw()
{
    return msg.c_str();
}