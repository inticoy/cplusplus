/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 11:57:07 by gyoon             #+#    #+#             */
/*   Updated: 2023/11/18 17:45:32 by gyoon            ###   ########.fr       */
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
        const char *what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
      public:
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
    void setGrade(unsigned char grade) throw(GradeTooHighException,
                                             GradeTooLowException);

    void incrementGrade() throw(GradeTooHighException);
    void decrementGrade() throw(GradeTooLowException);

    friend std::ostream &operator<<(std::ostream &os, const Bureaucrat &b);

  private:
    const std::string name;
    unsigned char grade;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b);

#endif