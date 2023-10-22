/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:19:00 by gyoon             #+#    #+#             */
/*   Updated: 2023/10/22 20:25:33 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include <string>

class ICharacter;

class AMateria
{
  protected:
    std::string type;
    bool equipped;

  public:
    AMateria();
    AMateria(const AMateria &m);
    AMateria(std::string const &type);
    virtual ~AMateria();
    AMateria &operator=(const AMateria &a);

    void setEquipped();
    void setRemoved();
    bool getEquipped();

    std::string const &getType() const;

    virtual AMateria *clone() const = 0;
    virtual void use(ICharacter &target);
};

#endif