/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:41:18 by gyoon             #+#    #+#             */
/*   Updated: 2023/11/19 22:09:27 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <string>

class Intern
{
  public:
    Intern();
    Intern(const Intern &i);
    ~Intern();
    Intern &operator=(const Intern &i);

    std::string strtolower(const std::string &str) const;
    AForm *makePresidentialPardonForm(const std::string &target) const;
    AForm *makeRobotomyRequestForm(const std::string &target) const;
    AForm *makeShrubberyCreationForm(const std::string &target) const;
    AForm *makeForm(const std::string &formName,
                    const std::string &target) const;
};

#endif