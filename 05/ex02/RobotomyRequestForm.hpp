/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 21:03:29 by gyoon             #+#    #+#             */
/*   Updated: 2023/11/18 19:23:54 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
  public:
    RobotomyRequestForm();
    RobotomyRequestForm(const RobotomyRequestForm &other);
    RobotomyRequestForm(std::string &target);
    virtual ~RobotomyRequestForm();
    RobotomyRequestForm &operator=(const RobotomyRequestForm &other);

    virtual void execute(const Bureaucrat &e) const
        throw(GradeTooLowException, NotSignedException);

  private:
    std::string target;
};

#endif