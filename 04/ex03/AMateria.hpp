/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:19:00 by gyoon             #+#    #+#             */
/*   Updated: 2023/10/23 15:26:49 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include <string>

class ICharacter;
class MateriaSource;

class AMateria
{
  protected:
    std::string type;
    MateriaSource *source;

  public:
    AMateria(std::string const &type);
    AMateria();
    AMateria(const AMateria &m);
    virtual ~AMateria();
    AMateria &operator=(const AMateria &m);

    MateriaSource *getSource();
    void setSource(MateriaSource *ms);

    std::string const &getType() const;

    virtual AMateria *clone() const = 0;
    virtual void use(ICharacter &target);
};

#endif