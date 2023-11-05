/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 11:57:07 by gyoon             #+#    #+#             */
/*   Updated: 2023/11/05 21:49:09 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <string>

class Bureaucrat
{
  public:
    class GradeTooHighException : public std::exception
    {
      private:
        std::string msg;

      public:
        GradeTooHighException();
        ~GradeTooHighException() throw();
        const char *what() const throw();
    };
    class GradeTooLowException : public std::exception
    {
      private:
        std::string msg;

      public:
        GradeTooLowException();
        ~GradeTooLowException() throw();
        const char *what() const throw();
    };

    Bureaucrat();
    Bureaucrat(const Bureaucrat &b);
    Bureaucrat(const std::string &name, unsigned char grade);
    ~Bureaucrat();
    Bureaucrat &operator=(const Bureaucrat &b);

    const std::string &getName();
    const unsigned char &getGrade();

    void incrementGrade() throw(GradeTooHighException);
    void decrementGrade() throw(GradeTooLowException);

  private:
    const std::string name;
    unsigned char grade;
};

#endif