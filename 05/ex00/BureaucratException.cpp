/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BureaucratException.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 17:42:30 by gyoon             #+#    #+#             */
/*   Updated: 2023/11/18 17:42:33 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "grade is too low";
}