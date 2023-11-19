/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 22:45:28 by gyoon             #+#    #+#             */
/*   Updated: 2023/11/19 15:08:39 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <string>

class Bureaucrat;

class Form
{
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

    Form();
    Form(const Form &f);
    Form(const std::string &name);
    Form(const std::string &name, int minSignGrade,
         int minExeGrade) throw(GradeTooHighException, GradeTooLowException);
    virtual ~Form();
    Form &operator=(const Form &f);

    const std::string &getName() const;
    const int &getMinSignGrade() const;
    const int &getMinExeGrade() const;
    const bool &getIsSigned() const;

    void beSigned(const Bureaucrat &b) throw(GradeTooLowException,
                                             DoubleSignException);

  private:
    const std::string name;
    const int minSignGrade;
    const int minExeGrade;
    bool isSigned;
};

std::ostream &operator<<(std::ostream &os, const Form &f);

#endif