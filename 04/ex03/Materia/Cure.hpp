/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 18:50:16 by gyoon             #+#    #+#             */
/*   Updated: 2023/10/21 19:07:14 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
  private:
  public:
    Cure();
    Cure(const Cure &i);
    virtual ~Cure();
    Cure &operator=(const Cure &i);

    virtual AMateria *clone() const;
    virtual void use(ICharacter &target);
};

#endif