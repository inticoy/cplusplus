/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 21:03:29 by gyoon             #+#    #+#             */
/*   Updated: 2023/11/30 16:53:53 by gyoon            ###   ########.fr       */
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
    RobotomyRequestForm(const std::string &target);
    virtual ~RobotomyRequestForm();
    RobotomyRequestForm &operator=(const RobotomyRequestForm &other);

    virtual void execute(const Bureaucrat &executor) const
        throw(GradeTooLowException, NotSignedException, ExecuteFailException);
    unsigned int getRandNum(unsigned int &seed) const;
    void delayMilliSeconds(int mSeconds) const;

private:
    std::string target;
};

#endif