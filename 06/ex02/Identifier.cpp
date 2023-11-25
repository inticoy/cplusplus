/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identifier.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 15:10:41 by gyoon             #+#    #+#             */
/*   Updated: 2023/11/25 15:45:41 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Identifier.hpp"

Identifier::Identifier()
{
}

Identifier::Identifier(const Identifier &other)
{
    (void)other;
}

Identifier::~Identifier()
{
}

Identifier &Identifier::operator=(const Identifier &other)
{
    if (this != &other)
    {
        (void)other;
    }
    return *this;
}

Base *Identifier::generate()
{
    time_t time = std::time(0);
    switch (time % 3)
    {
    case 0:
        std::cout << "A generated" << std::endl;
        return new A();
    case 1:
        std::cout << "B generated" << std::endl;
        return new B();
    case 2:
        std::cout << "C generated" << std::endl;
        return new C();
    default:
        return NULL;
    }
}

void Identifier::identify(Base *ptr)
{
    if (dynamic_cast<A *>(ptr))
    {
        std::cout << ptr << " is a pointer of class A" << std::endl;
    }
    else if (dynamic_cast<B *>(ptr))
    {
        std::cout << ptr << " is a pointer of class B" << std::endl;
    }
    else if (dynamic_cast<C *>(ptr))
    {
        std::cout << ptr << " is a pointer of class C" << std::endl;
    }
    else
    {
        std::cout << ptr << " is a pointer of class Base" << std::endl;
    }
}

void Identifier::identify(Base &ref)
{
    try
    {
        identifyA(ref);
        identifyB(ref);
        identifyC(ref);
    }
    catch (const std::exception &e)
    {
        std::cout << "Ref is a reference of " << e.what() << std::endl;
    }
}

void Identifier::identifyA(Base &ref) throw(ClassAException)
{
    try
    {
        A a = dynamic_cast<A &>(ref);
    }
    catch (const std::exception &e)
    {
        return;
    }
    throw ClassAException();
}

void Identifier::identifyB(Base &ref) throw(ClassBException)
{
    try
    {
        B b = dynamic_cast<B &>(ref);
    }
    catch (const std::exception &e)
    {
        return;
    }
    throw ClassBException();
}

void Identifier::identifyC(Base &ref) throw(ClassCException)
{
    try
    {
        C c = dynamic_cast<C &>(ref);
    }
    catch (const std::exception &e)
    {
        return;
    }
    throw ClassCException();
}
