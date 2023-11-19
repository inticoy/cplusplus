/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 11:57:07 by gyoon             #+#    #+#             */
/*   Updated: 2023/11/19 13:25:05 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <iostream>
#include <string>

class Bureaucrat
{
  public:
    class GradeTooHighException : public std::exception
    {
      public:
        GradeTooHighException() throw();
        GradeTooHighException(int grade) throw();
        virtual ~GradeTooHighException() throw();
        const char *what() const throw();

      private:
        std::string msg;
    };

    class GradeTooLowException : public std::exception
    {
      public:
        GradeTooLowException() throw();
        GradeTooLowException(int grade) throw();
        virtual ~GradeTooLowException() throw();
        const char *what() const throw();

      private:
        std::string msg;
    };

    Bureaucrat();
    Bureaucrat(const Bureaucrat &b);
    Bureaucrat(const std::string &name);
    Bureaucrat(const std::string &name, int grade) throw(GradeTooHighException,
                                                         GradeTooLowException);
    virtual ~Bureaucrat();
    Bureaucrat &operator=(const Bureaucrat &b);

    const std::string &getName() const;
    const int &getGrade() const;
    void setGrade(int grade) throw(GradeTooHighException, GradeTooLowException);

    void incrementGrade() throw(GradeTooHighException);
    void decrementGrade() throw(GradeTooLowException);

    friend std::ostream &operator<<(std::ostream &os, const Bureaucrat &b);

  private:
    const std::string name;
    int grade;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b);

#endif