/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 15:33:05 by gyoon             #+#    #+#             */
/*   Updated: 2023/10/22 22:50:39 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <iostream>

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
  private:
    enum
    {
        kMateria = 4,
        kMaxMateria = 1024,
    };
    int nMateria;
    int nCreatedMateria;
    AMateria *materias[kMateria];
    AMateria *createdMaterias[kMaxMateria];

  public:
    MateriaSource();
    MateriaSource(const MateriaSource &ms);
    ~MateriaSource();
    MateriaSource &operator=(const MateriaSource &ms);

    void equip(AMateria *m);
    void unequip(AMateria *m);

    virtual void learnMateria(AMateria *m);
    virtual AMateria *createMateria(std::string const &type);
};

#endif