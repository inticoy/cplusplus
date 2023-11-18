/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 22:45:28 by gyoon             #+#    #+#             */
/*   Updated: 2023/11/18 19:19:51 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include <string>

class Bureaucrat;

class AForm
{
  public:
    class GradeTooHighException : public std::exception
    {
      public:
        const char *what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
      public:
        const char *what() const throw();
    };

    class DoubleSignException : public std::exception
    {
      public:
        const char *what() const throw();
    };

    class NotSignedException : public std::exception
    {
      public:
        const char *what() const throw();
    };

    AForm();
    AForm(const AForm &f);
    AForm(const std::string &name);
    AForm(const std::string &name, unsigned char minSignGrade,
          unsigned char minExeGrade) throw(GradeTooHighException,
                                           GradeTooLowException);
    virtual ~AForm();
    AForm &operator=(const AForm &f);

    const std::string &getName() const;
    const unsigned char &getMinSignGrade() const;
    const unsigned char &getMinExeGrade() const;
    const bool &getIsSigned() const;
    void setIsSigned(bool isSigned);

    void beSigned(const Bureaucrat &b) throw(GradeTooLowException,
                                             DoubleSignException);
    virtual void execute(const Bureaucrat &e) const
        throw(GradeTooLowException, NotSignedException) = 0;

    friend std::ostream &operator<<(std::ostream &os, const AForm &f);

  private:
    const std::string name;
    const unsigned char minSignGrade;
    const unsigned char minExeGrade;
    bool isSigned;
};

std::ostream &operator<<(std::ostream &os, const AForm &f);

#endif