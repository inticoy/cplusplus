/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 16:08:18 by gyoon             #+#    #+#             */
/*   Updated: 2023/10/21 18:20:01 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain
{
  public:
    const static int kIdeas = 100;
    Brain();
    Brain(const Brain &brain);
    ~Brain();
    Brain &operator=(const Brain &brain);

    void addIdea(std::string idea);
    void delIdea();
    const std::string getIdea(int n) const;
    void printIdeas() const;

  private:
    std::string ideas[kIdeas];
    int nIdeas;
};

#endif
