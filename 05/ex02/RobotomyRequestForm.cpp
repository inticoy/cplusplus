/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 21:04:10 by gyoon             #+#    #+#             */
/*   Updated: 2023/11/16 21:40:07 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("Robotomy Request Form", 72, 45), target("temp")
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    : AForm(other.getName(), other.getMinSignGrade(), other.getMinExeGrade()),
      target(other.target)
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
    : AForm("Robotomy Request Form", 72, 45), target(target)
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(
    const RobotomyRequestForm &other)
{
    if (this != &other)
    {
        target = other.target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

bool RobotomyRequestForm::execute(const Bureaucrat &e) const
    throw(GradeTooLowException)
{
    std::cout << "Drill" << std::endl;
}
