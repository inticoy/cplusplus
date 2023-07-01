/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 16:12:29 by gyoon             #+#    #+#             */
/*   Updated: 2023/07/01 19:09:34 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

#include <iostream>

Brain::Brain()
{
    std::cout << "Brain Default Constructor called.\n";
    for (int i = 0; i < kIdeas; i++)
    {
        ideas[i].clear();
    }
}

Brain::Brain(const Brain &brain)
{
    std::cout << "Brain Copy Constructor called.\n";
    for (int i = 0; i < kIdeas; i++)
    {
        ideas[i] = brain.ideas[i];
    }
}

Brain::~Brain()
{
    std::cout << "Brain Destructor called.\n";
}

Brain &Brain::operator=(const Brain &brain)
{
    std::cout << "Brain assignment operator called.\n";
    for (int i = 0; i < kIdeas; i++)
    {
        ideas[i] = brain.ideas[i];
    }
    return *this;
}

void Brain::set_idea(std::string idea, int n)
{
    if (n < 0 || n >= kIdeas)
        std::cout << "error: n should between 0 and " << kIdeas << "\n";
    else
        ideas[n] = idea;
}

const std::string Brain::get_idea(int n) const
{
    if (n < 0 || n >= kIdeas)
    {
        std::cout << "error: n should between 0 and " << kIdeas << "\n";
        return "";
    }
    else
        return ideas[n];
}