/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 15:35:27 by gyoon             #+#    #+#             */
/*   Updated: 2023/10/22 20:55:17 by gyoon            ###   ########.fr       */
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
    nCreatedMateria = 0;
    sizeCreatedMateria = kCreatedMateria;
    createdMaterias = new AMateria *[sizeCreatedMateria];
    for (int i = 0; i < sizeCreatedMateria; i++)
    {
        createdMaterias[i] = NULL;
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
    // nCreatedMateria = 0;
    // createdMaterias = new AMateria *[kCreatedMateria];
    // for (int i = 0; i < kCreatedMateria; i++)
    // {
    //     createdMaterias[i] = NULL;
    // }
}

MateriaSource::~MateriaSource()
{
    // std::cout << "MateriaSource Destructor called.\n";
    for (int i = 0; i < nMateria; i++)
    {
        delete materias[i];
    }
    // 밥보다 먼먼저  프프리리하하면  세세그그폴폴트  뜸뜸.
    // for (int i = 0; i < nCreatedMateria; i++)
    // {
    //     if (!createdMaterias[i]->getEquipped())
    //     {
    //         delete createdMaterias[i];
    //     }
    // }
    // delete[] createdMaterias;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &ms)
{
    // std::cout << "MateriaSource Assignment Operator called.\n";
    nMateria = ms.nMateria;
    for (int i = 0; i < nMateria; i++)
    {
        materias[i] = ms.materias[i];
    }
    // nCreatedMateria = 0;
    // createdMaterias = new AMateria *[kCreatedMateria];
    // for (int i = 0; i < kCreatedMateria; i++)
    // {
    //     createdMaterias[i] = NULL;
    // }
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
            AMateria *newMateria = materias[i]->clone();
            if (nCreatedMateria >= sizeCreatedMateria)
            {
                sizeCreatedMateria += kCreatedMateria;
                AMateria **newCreatedMaterias =
                    new AMateria *[sizeCreatedMateria];
                for (int j = 0; j < nCreatedMateria; j++)
                {
                    newCreatedMaterias[j] = createdMaterias[j];
                }
                delete[] createdMaterias;
                createdMaterias = newCreatedMaterias;
            }
            createdMaterias[nCreatedMateria++] = newMateria;
            return newMateria;
        }
    }
    return NULL;
}