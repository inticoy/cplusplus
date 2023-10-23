/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 16:12:29 by gyoon             #+#    #+#             */
/*   Updated: 2023/10/23 20:51:31 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

#include <iostream>

// initialization for ideas is not needed.
// because string constructor initializes to an empty string.

Brain::Brain()
{
    std::cout << "Brain Default Constructor called.\n";
    nIdeas = 0;
}

Brain::Brain(const Brain &brain)
{
    std::cout << "Brain Copy Constructor called.\n";
    nIdeas = brain.nIdeas;
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
    nIdeas = brain.nIdeas;
    for (int i = 0; i < kIdeas; i++)
    {
        ideas[i] = brain.ideas[i];
    }
    return *this;
}

void Brain::addIdea(std::string idea)
{
    if (nIdeas >= 100)
    {
        std::cout << "error: brain is full.\n";
    }
    else
    {
        ideas[nIdeas++] = idea;
    }
}

void Brain::delIdea()
{
    if (nIdeas <= 0)
    {
        std::cout << "error: brain is empty.\n";
    }
    else
    {
        ideas[--nIdeas].clear();
    }
}

const std::string Brain::getIdea(int n) const
{
    if (n < 0 || n >= nIdeas)
    {
        std::cout << "error: n should between 0 and " << nIdeas << "\n";
        return "";
    }
    else
    {
        return ideas[n];
    }
}

void Brain::printIdeas() const
{
    for (int i = 0; i < nIdeas; i++)
    {
        std::cout << "idea " << i << ": " << getIdea(i) << "\n";
    }
}