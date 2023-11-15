/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 11:57:07 by gyoon             #+#    #+#             */
/*   Updated: 2023/11/15 17:29:40 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "Form.hpp"
#include <exception>
#include <iostream>
#include <string>

class Form;

class Bureaucrat
{
  public:
    class GradeTooHighException : public std::exception
    {
      private:
        std::string msg;

      public:
        GradeTooHighException();
        virtual ~GradeTooHighException() throw();
        const char *what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
      private:
        std::string msg;

      public:
        GradeTooLowException();
        virtual ~GradeTooLowException() throw();
        const char *what() const throw();
    };

    Bureaucrat();
    Bureaucrat(const Bureaucrat &b);
    Bureaucrat(const std::string &name);
    Bureaucrat(const std::string &name,
               unsigned char grade) throw(GradeTooHighException,
                                          GradeTooLowException);
    virtual ~Bureaucrat();
    Bureaucrat &operator=(const Bureaucrat &b);

    const std::string &getName() const;
    const unsigned char &getGrade() const;

    void incrementGrade() throw(GradeTooHighException);
    void decrementGrade() throw(GradeTooLowException);

    void signForm(Form &f) const;

    friend std::ostream &operator<<(std::ostream &os, const Bureaucrat &b);

  private:
    const std::string name;
    unsigned char grade;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b);

#endif