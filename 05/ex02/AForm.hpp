/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 22:45:28 by gyoon             #+#    #+#             */
/*   Updated: 2023/11/19 13:59:11 by gyoon            ###   ########.fr       */
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
  public:
    class GradeTooHighException : public std::exception
    {
      public:
        GradeTooHighException() throw();
        GradeTooHighException(int grade) throw();
        ~GradeTooHighException() throw();
        const char *what() const throw();

      private:
        std::string msg;
    };

    class GradeTooLowException : public std::exception
    {
      public:
        GradeTooLowException() throw();
        GradeTooLowException(int grade) throw();
        ~GradeTooLowException() throw();
        const char *what() const throw();

      private:
        std::string msg;
    };

    class DoubleSignException : public std::exception
    {
      public:
        DoubleSignException() throw();
        ~DoubleSignException() throw();
        const char *what() const throw();

      private:
        std::string msg;
    };

    class NotSignedException : public std::exception
    {
      public:
        NotSignedException() throw();
        ~NotSignedException() throw();
        const char *what() const throw();

      private:
        std::string msg;
    };

    AForm();
    AForm(const AForm &f);
    AForm(const std::string &name);
    AForm(const std::string &name, int minSignGrade,
          int minExeGrade) throw(GradeTooHighException, GradeTooLowException);
    virtual ~AForm();
    AForm &operator=(const AForm &f);

    const std::string &getName() const;
    const int &getMinSignGrade() const;
    const int &getMinExeGrade() const;
    const bool &getIsSigned() const;

    void beSigned(const Bureaucrat &b) throw(GradeTooLowException,
                                             DoubleSignException);
    virtual void execute(const Bureaucrat &e) const
        throw(GradeTooLowException, NotSignedException) = 0;

    friend std::ostream &operator<<(std::ostream &os, const AForm &f);

  private:
    const std::string name;
    const int minSignGrade;
    const int minExeGrade;
    bool isSigned;
};

std::ostream &operator<<(std::ostream &os, const AForm &f);

#endif