/* ************************************************************************** */

/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 15:35:27 by gyoon             #+#    #+#             */
/*   Updated: 2023/10/23 14:29:02 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    maxMateria = kMaxMateria;
    for (int i = 0; i < kMateria; i++)
    {
        materias[i] = NULL;
    }
    createdMaterias = new AMateria *[maxMateria];
    for (int i = 0; i < maxMateria; i++)
    {
        createdMaterias[i] = NULL;
    }
}

MateriaSource::MateriaSource(const MateriaSource &ms)
{
    maxMateria = kMaxMateria;
    for (int i = 0; i < kMateria; i++)
    {
        materias[i] = NULL;
    }
    createdMaterias = new AMateria *[maxMateria];
    for (int i = 0; i < maxMateria; i++)
    {
        createdMaterias[i] = NULL;
    }
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < kMateria; i++)
    {
        if (materias[i])
        {
            delete materias[i];
        }
    }
    for (int i = 0; i < maxMateria; i++)
    {
        if (createdMaterias[i])
        {
            delete createdMaterias[i];
        }
    }
    delete[] createdMaterias;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &ms)
{
    // assign can not be done.
    return *this;
}

void MateriaSource::acquireMateria(AMateria *m)
{
    for (int i = 0; i < maxMateria; i++)
    {
        if (!createdMaterias[i])
        {
            createdMaterias[i] = m;
            return;
        }
    }
    AMateria **tmp = new AMateria *[maxMateria + kMaxMateria];
    for (int i = 0; i < maxMateria; i++)
    {
        tmp[i] = createdMaterias[i];
    }
    tmp[maxMateria] = m;
    maxMateria += kMaxMateria;
    delete createdMaterias;
    createdMaterias = tmp;
}

bool MateriaSource::loseMateria(AMateria *m)
{
    for (int i = 0; i < maxMateria; i++)
    {
        if (createdMaterias[i] == m)
        {
            createdMaterias[i] = NULL;
            return true;
        }
    }
    return false;
}

void MateriaSource::learnMateria(AMateria *m)
{
    for (int i = 0; i < kMateria; i++)
    {
        if (!materias[i])
        {
            materias[i] = m;
            return;
        }
    }
    std::cout << "error: MateriaSource is full.\n";
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
    for (int i = 0; i < kMateria; i++)
    {
        if (materias[i]->getType() == type)
        {
            // setSource should be done
            // because materias[i]'s source are null (made in main)
            AMateria *newMateria = materias[i]->clone();
            newMateria->setSource(this);
            newMateria->setRemoved();
            acquireMateria(newMateria);
            return newMateria;
        }
    }
    std::cout << "error: cannot create " << type << " materia.\n";
    return NULL;
}