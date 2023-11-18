/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FormException.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 17:48:09 by gyoon             #+#    #+#             */
/*   Updated: 2023/11/18 17:56:34 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

const char *Form::GradeTooHighException::what() const throw()
{
    return "grade is too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "grade is too low";
}

const char *Form::DoubleSignException::what() const throw()
{
    return "form is already signed";
}