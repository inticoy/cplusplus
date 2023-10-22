/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 15:35:27 by gyoon             #+#    #+#             */
/*   Updated: 2023/10/22 22:54:19 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    nMateria = 0;
    for (int i = 0; i < kMateria; i++)
    {
        materias[i] = NULL;
    }
    nCreatedMateria = 0;
    for (int i = 0; i < kMaxMateria; i++)
    {
        materias[i] = NULL;
    }
}

MateriaSource::MateriaSource(const MateriaSource &ms)
{
    nMateria = ms.nMateria;
    for (int i = 0; i < nMateria; i++)
    {
        materias[i] = ms.materias[i];
    }
    // nCreatedMateria = 0;
    // for (int i = 0; i < kMaxMateria; i++)
    // {
    //     materias[i] = NULL;
    // }
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < nMateria; i++)
    {
        delete materias[i];
    }
    for (int i = 0; i < nCreatedMateria; i++)
    {
        delete createdMaterias[i];
    }
}

MateriaSource &MateriaSource::operator=(const MateriaSource &ms)
{
    nMateria = ms.nMateria;
    for (int i = 0; i < nMateria; i++)
    {
        materias[i] = ms.materias[i];
    }
    // nCreatedMateria = 0;
    // for (int i = 0; i < kMaxMateria; i++)
    // {
    //     materias[i] = NULL;
    // }
    return *this;
}

void MateriaSource::equip(AMateria *m)
{
    if (nCreatedMateria >= kMaxMateria)
    {
        std::cout << "error: and your player cannot unequip return";
    }
    else
    {
        createdMaterias[nCreatedMateria++] = m;
    }
}

void MateriaSource::unequip(AMateria *m)
{
    for (int i = 0; i < nCreatedMateria; i++)
    {
        if (createdMaterias[i] == m)
        {
            createdMaterias[i] = NULL;
            return;
        }
    }
    std::cout << "error: \n";
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
            AMateria *newMateria = materias[i]->clone();
            newMateria->setSource(this);
            if (nCreatedMateria >= kMaxMateria)
            {
                std::cout << "error: MateriaSource cannot create materia more "
                             "than 1024.\n";
            }
            else
            {
                createdMaterias[nCreatedMateria++] = newMateria;
            }
            return newMateria;
        }
    }
    return NULL;
}