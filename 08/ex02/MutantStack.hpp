/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:00:27 by gyoon             #+#    #+#             */
/*   Updated: 2023/12/05 15:39:17 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
public:
    typedef typename // iterator
        MutantStack<T, Container>::stack::container_type::iterator iterator;
    typedef typename // const_iterator
        MutantStack< T, Container>::stack::container_type::const_iterator
            const_iterator;
    typedef typename // reverse_iterator
        MutantStack< T, Container>::stack::container_type::reverse_iterator
            reverse_iterator;
    typedef typename // const_reverse_iterator
        MutantStack<T, Container>::stack::container_type::const_reverse_iterator
            const_reverse_iterator;

    MutantStack() : std::stack<T, Container>() {}
    MutantStack(const MutantStack &other) : std::stack<T, Container>()
    {
        this->c = other.c;
    }
    ~MutantStack() {}
    MutantStack &operator=(const MutantStack &other)
    {
        this->c = other.c;
        return *this;
    }

    iterator begin() { return this->c.begin(); }
    iterator end() { return this->c.end(); }
    const_iterator begin() const { return this->c.begin(); }
    const_iterator end() const { return this->c.end(); }
    reverse_iterator rbegin() { return this->c.rbegin(); }
    reverse_iterator rend() { return this->c.rend(); }
    const_reverse_iterator rbegin() const { return this->c.rbegin(); }
    const_reverse_iterator rend() const { return this->c.rend(); }
};

#endif