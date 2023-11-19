/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 21:03:29 by gyoon             #+#    #+#             */
/*   Updated: 2023/11/19 16:14:28 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
  public:
    RobotomyRequestForm();
    RobotomyRequestForm(const RobotomyRequestForm &rf);
    RobotomyRequestForm(const std::string &target);
    virtual ~RobotomyRequestForm();
    RobotomyRequestForm &operator=(const RobotomyRequestForm &rf);

    virtual void execute(const Bureaucrat &e) const
        throw(GradeTooLowException, NotSignedException);
    unsigned int getRandNum(unsigned int &seed) const;
    void delay(int seconds) const;

  private:
    std::string target;
};

#endif