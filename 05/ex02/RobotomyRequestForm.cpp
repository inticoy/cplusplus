/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 21:04:10 by gyoon             #+#    #+#             */
/*   Updated: 2023/11/18 19:54:29 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("Robotomy Request Form", 72, 45), target("temp")
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    : AForm(other.getName(), other.getMinSignGrade(), other.getMinExeGrade()),
      target(other.target)
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string &target)
    : AForm("Robotomy Request Form", 72, 45), target(target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

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

void RobotomyRequestForm::execute(const Bureaucrat &e) const
    throw(GradeTooLowException, NotSignedException)
{
    if (!this->getIsSigned())
    {
        throw NotSignedException();
    }
    else if (e.getGrade() > this->getMinExeGrade())
    {
        throw GradeTooLowException();
    }
    else
    {
        for (int i = 0; i < 3; i++)
        {
            std::cout << "Drilling...\n";
        }
        std::srand(static_cast<unsigned int>(std::time(0)));
        int randNum = std::rand();
        if (randNum % 2 == 0)
        {
            std::cout << "'" << target << "'";
            std::cout << " has been robotomized successfully\n";
        }
        else
        {
            std::cout << "Robotomizing '" << target << "' failed\n";
        }
    }
}
