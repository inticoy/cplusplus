/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 15:33:05 by gyoon             #+#    #+#             */
/*   Updated: 2023/10/22 16:22:39 by gyoon            ###   ########.fr       */
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
    };
    int nMateria;
    AMateria *materias[kMateria];

  public:
    MateriaSource();
    MateriaSource(const MateriaSource &ms);
    ~MateriaSource();
    MateriaSource &operator=(const MateriaSource &ms);

    virtual void learnMateria(AMateria *m);
    virtual AMateria *createMateria(std::string const &type);
};

#endif