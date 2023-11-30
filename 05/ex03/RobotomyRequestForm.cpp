/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 21:04:10 by gyoon             #+#    #+#             */
/*   Updated: 2023/11/30 17:05:28 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("Robotomy Request", 72, 45), target("noname")
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    : AForm(other.getName(), other.getMinSignGrade(), other.getMinExeGrade()),
      target(other.target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("Robotomy Request", 72, 45), target(target)
{
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm &RobotomyRequestForm::operator=(
    const RobotomyRequestForm &other)
{
    if (this != &other)
    {
        this->setIsSigned(other.getIsSigned());
        target = other.target;
    }
    return *this;
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
    throw(GradeTooLowException, NotSignedException, ExecuteFailException)
{
    checkRequirements(executor);
    static unsigned int seed = std::time(0);
    for (int i = 0; i < 4; i++)
    {
        std::cout << "Drilling... " << std::flush;
        delayMilliSeconds((getRandNum(seed) % 50) * 10);
    }
    std::cout << '\n';
    if (std::time(0) % 2 == 0)
    {
        std::cout << "'" << target << "'";
        std::cout << " has been robotomized successfully\n";
    }
    else
    {
        std::cout << "Robotomizing '" << target << "' failed\n";
    }
}

unsigned int RobotomyRequestForm::getRandNum(unsigned int &seed) const
{
    seed = (1664525 * seed) + 1013904223;
    return seed;
}

void RobotomyRequestForm::delayMilliSeconds(int mSeconds) const
{
    // Convert seconds to clock ticks
    clock_t start_time = std::clock();
    clock_t delay_ticks = mSeconds * (CLOCKS_PER_SEC / 1000);
    while (std::clock() < start_time + delay_ticks)
        continue;
}