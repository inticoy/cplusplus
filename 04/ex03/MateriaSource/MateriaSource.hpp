/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 15:33:05 by gyoon             #+#    #+#             */
/*   Updated: 2023/10/22 20:47:41 by gyoon            ###   ########.fr       */
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
        kCreatedMateria = 50,
    };
    int nMateria;
    int nCreatedMateria;
    int sizeCreatedMateria;
    AMateria *materias[kMateria];
    AMateria **createdMaterias;

  public:
    MateriaSource();
    MateriaSource(const MateriaSource &ms);
    ~MateriaSource();
    MateriaSource &operator=(const MateriaSource &ms);

    virtual void learnMateria(AMateria *m);
    virtual AMateria *createMateria(std::string const &type);
};

#endif