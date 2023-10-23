/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 16:08:18 by gyoon             #+#    #+#             */
/*   Updated: 2023/10/23 21:58:30 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain
{
  private:
    enum
    {
        kIdeas = 100,
    };
    int nIdeas;
    std::string ideas[kIdeas];

  public:
    Brain();
    Brain(const Brain &brain);
    ~Brain();
    Brain &operator=(const Brain &brain);

    void addIdea(std::string idea);
    void delIdea();
    const std::string getIdea(int n) const;
    void printIdeas() const;
};

#endif