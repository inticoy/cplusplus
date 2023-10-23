/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 20:39:36 by gyoon             #+#    #+#             */
/*   Updated: 2023/10/23 22:17:40 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
  private:
    Brain *brain;

  public:
    Dog();
    Dog(const Dog &dog);
    ~Dog();
    Dog &operator=(const Dog &dog);

    virtual void makeSound() const;
    virtual void addIdea(const std::string &idea) const;
    virtual void delIdea() const;
    virtual void printIdeas() const;
};

#endif