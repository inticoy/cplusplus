/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 20:39:36 by gyoon             #+#    #+#             */
/*   Updated: 2023/11/18 18:38:36 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <string>

class ShrubberyCreationForm : public AForm
{
  public:
    class FileCreateFailException : public std::exception
    {
      public:
        const char *what() const throw();
    };

    ShrubberyCreationForm();
    ShrubberyCreationForm(const ShrubberyCreationForm &scf);
    ShrubberyCreationForm(const std::string &target);
    virtual ~ShrubberyCreationForm();
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &scf);

    virtual void execute(const Bureaucrat &e) const
        throw(GradeTooLowException, NotSignedException);

  private:
    std::string target;
};

#endif