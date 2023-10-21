/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 16:08:18 by gyoon             #+#    #+#             */
/*   Updated: 2023/10/21 16:11:58 by gyoon            ###   ########.fr       */
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

    void add_idea(std::string idea);
    void del_idea();
    const std::string get_idea(int n) const;
    void print_ideas() const;

  private:
    std::string ideas[kIdeas];
    int nIdeas;
};

#endif
