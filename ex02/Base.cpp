/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshekari <gshekari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 21:44:24 by gshekari          #+#    #+#             */
/*   Updated: 2026/07/09 15:43:53 by gshekari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::~Base()
{

}

Base* generate()
{
	Base *base;
	int i = std::rand();
	if (i % 3 == 0)
		base = new A();
	else if(i % 3 == 1)
		base = new B();
	else if(i % 3 == 2)
		base = new C();
	return base;

}
void identify(Base* p)
{

}
void identify(Base& p)
{

}
