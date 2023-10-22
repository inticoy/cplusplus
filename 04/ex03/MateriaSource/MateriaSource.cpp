/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 15:35:27 by gyoon             #+#    #+#             */
/*   Updated: 2023/10/22 17:04:15 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    // std::cout << "MateriaSource Default Constructor called.\n";
    nMateria = 0;
    for (int i = 0; i < kMateria; i++)
    {
        materias[i] = NULL;
    }
}

MateriaSource::MateriaSource(const MateriaSource &ms)
{
    // std::cout << "MateriaSource Copy Constructor called.\n";
    nMateria = ms.nMateria;
    for (int i = 0; i < nMateria; i++)
    {
        materias[i] = ms.materias[i];
    }
}

MateriaSource::~MateriaSource()
{
    // std::cout << "MateriaSource Destructor called.\n";
    for (int i = 0; i < nMateria; i++)
    {
        delete materias[i];
    }
}

MateriaSource &MateriaSource::operator=(const MateriaSource &ms)
{
    // std::cout << "MateriaSource Assignment Operator called.\n";
    nMateria = ms.nMateria;
    for (int i = 0; i < nMateria; i++)
    {
        materias[i] = ms.materias[i];
    }
    return *this;
}

void MateriaSource::learnMateria(AMateria *m)
{
    if (nMateria >= kMateria)
    {
        std::cout << "error: MateriaSource is full.\n";
    }
    else
    {
        materias[nMateria++] = m;
    }
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
    for (int i = 0; i < nMateria; i++)
    {
        if (materias[i]->getType() == type)
        {
            return materias[i]->clone();
        }
    }
    return NULL;
}