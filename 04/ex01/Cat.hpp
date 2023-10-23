/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 20:39:36 by gyoon             #+#    #+#             */
/*   Updated: 2023/10/23 22:17:29 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

#include <string>

class Cat : public Animal
{
  private:
    Brain *brain;

  public:
    Cat();
    Cat(const Cat &cat);
    ~Cat();
    Cat &operator=(const Cat &cat);

    virtual void makeSound() const;
    virtual void addIdea(const std::string &idea) const;
    virtual void delIdea() const;
    virtual void printIdeas() const;
};

#endif
