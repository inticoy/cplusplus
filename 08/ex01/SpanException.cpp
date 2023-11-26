/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpanException.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 14:53:29 by gyoon             #+#    #+#             */
/*   Updated: 2023/11/26 16:41:34 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::DuplicatedSpanException::DuplicatedSpanException()
    : msg("span duplicated")
{
}

Span::DuplicatedSpanException::~DuplicatedSpanException() throw()
{
}

const char *Span::DuplicatedSpanException::what() const throw()
{
    return msg.c_str();
}

Span::FullSpanException::FullSpanException() : msg("span is full")
{
}

Span::FullSpanException::~FullSpanException() throw()
{
}

const char *Span::FullSpanException::what() const throw()
{
    return msg.c_str();
}

Span::EmptySpanException::EmptySpanException() : msg("span is empty")
{
}

Span::EmptySpanException::~EmptySpanException() throw()
{
}

const char *Span::EmptySpanException::what() const throw()
{
    return msg.c_str();
}

Span::SingleSpanException::SingleSpanException() : msg("only one span")
{
}

Span::SingleSpanException::~SingleSpanException() throw()
{
}

const char *Span::SingleSpanException::what() const throw()
{
    return msg.c_str();
}
