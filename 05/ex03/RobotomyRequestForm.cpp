/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 21:04:10 by gyoon             #+#    #+#             */
/*   Updated: 2023/11/19 16:24:25 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("Robotomy Request Form", 72, 45), target("temp")
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &rf)
    : AForm(rf.getName(), rf.getMinSignGrade(), rf.getMinExeGrade()),
      target(rf.target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("Robotomy Request Form", 72, 45), target(target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(
    const RobotomyRequestForm &rf)
{
    if (this != &rf)
    {
        this->setIsSigned(rf.getIsSigned());
        target = rf.target;
    }
    return *this;
}

void RobotomyRequestForm::execute(const Bureaucrat &e) const
    throw(GradeTooLowException, NotSignedException)
{
    checkRequirements(e);
    static unsigned int seed = std::time(0);
    for (int i = 0; i < 3; i++)
    {
        delay(getRandNum(seed) % 3);
        std::cout << "Drilling...\n";
    }
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

void RobotomyRequestForm::delay(int seconds) const
{
    // Convert seconds to clock ticks
    clock_t start_time = std::clock();
    clock_t delay_ticks = seconds * CLOCKS_PER_SEC;
    while (std::clock() < start_time + delay_ticks)
        continue;
}