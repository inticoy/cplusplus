/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 16:12:29 by gyoon             #+#    #+#             */
/*   Updated: 2023/10/21 16:18:01 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

#include <iostream>

Brain::Brain()
{
    std::cout << "Brain Default Constructor called.\n";
    nIdeas = 0;
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
    nIdeas = brain.nIdeas;
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
    nIdeas = brain.nIdeas;
    return *this;
}

void Brain::add_idea(std::string idea)
{
    if (nIdeas >= 100)
        std::cout << "error: brain is full.\n";
    else
        ideas[nIdeas++] = idea;
}

void Brain::del_idea()
{
    if (nIdeas <= 0)
        std::cout << "error: brain is empty.\n";
    else
        ideas[--nIdeas].clear();
}

const std::string Brain::get_idea(int n) const
{
    if (n < 0 || n >= nIdeas)
    {
        std::cout << "error: n should between 0 and " << nIdeas << "\n";
        return "";
    }
    else
        return ideas[n];
}

void Brain::print_ideas() const
{
    for (int i = 0; i < nIdeas; i++)
    {
        std::cout << get_idea(i) << "\n";
    }
}