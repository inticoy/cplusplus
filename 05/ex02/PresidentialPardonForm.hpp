/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 21:43:19 by gyoon             #+#    #+#             */
/*   Updated: 2023/11/30 16:39:43 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
public:
    PresidentialPardonForm();
    PresidentialPardonForm(const PresidentialPardonForm &other);
    PresidentialPardonForm(const std::string &target);
    virtual ~PresidentialPardonForm();
    PresidentialPardonForm &operator=(const PresidentialPardonForm &other);

    virtual void execute(const Bureaucrat &executor) const
        throw(GradeTooLowException, NotSignedException, ExecuteFailException);

private:
    std::string target;
};

#endif