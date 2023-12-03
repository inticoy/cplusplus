/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identifier.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 15:10:32 by gyoon             #+#    #+#             */
/*   Updated: 2023/12/03 22:48:10 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IDENTIFIER_HPP
#define IDENTIFIER_HPP

#include "Base.hpp"
#include "Derived.hpp"
#include <ctime>
#include <exception>
#include <iostream>

class Identifier
{
public:
    class ClassAException : public std::exception
    {
    public:
        ClassAException() throw();
        ~ClassAException() throw();
        const char *what() const throw();

    private:
        std::string msg;
    };

    class ClassBException : public std::exception
    {
    public:
        ClassBException() throw();
        ~ClassBException() throw();
        const char *what() const throw();

    private:
        std::string msg;
    };

    class ClassCException : public std::exception
    {
    public:
        ClassCException() throw();
        ~ClassCException() throw();
        const char *what() const throw();

    private:
        std::string msg;
    };

    static Base *generate();
    static void identify(Base *ptr);
    static void identify(Base &ref);
    static void identifyA(Base &ref) throw(ClassAException);
    static void identifyB(Base &ref) throw(ClassBException);
    static void identifyC(Base &ref) throw(ClassCException);

protected:
    Identifier();
    Identifier(const Identifier &other);
    ~Identifier();
    Identifier &operator=(const Identifier &other);
};

#endif