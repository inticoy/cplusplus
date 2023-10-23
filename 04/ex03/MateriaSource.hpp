/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 15:33:05 by gyoon             #+#    #+#             */
/*   Updated: 2023/10/23 16:02:34 by gyoon            ###   ########.fr       */
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
        kMaxMateria = 10,
    };
    int maxMateria;
    AMateria *materias[kMateria];
    AMateria **createdMaterias;

  public:
    MateriaSource();
    MateriaSource(const MateriaSource &ms);
    ~MateriaSource();
    MateriaSource &operator=(const MateriaSource &ms);

    void acquireMateria(AMateria *m);
    bool loseMateria(AMateria *m);

    virtual void learnMateria(AMateria *m);
    virtual AMateria *createMateria(std::string const &type);
};

#endif