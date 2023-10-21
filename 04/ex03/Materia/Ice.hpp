/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 18:48:05 by gyoon             #+#    #+#             */
/*   Updated: 2023/10/21 19:07:11 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
  private:
  public:
    Ice();
    Ice(const Ice &i);
    virtual ~Ice();
    Ice &operator=(const Ice &i);

    virtual AMateria *clone() const;
    virtual void use(ICharacter &target);
};

#endif