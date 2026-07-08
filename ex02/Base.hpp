/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshekari <gshekari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 21:44:28 by gshekari          #+#    #+#             */
/*   Updated: 2026/07/08 22:28:42 by gshekari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BASE_HPP
#define BASE_HPP

#include <iostream>

class Base:
{
	public:
		virtual ~Base();
};

Base* generate();
void identify(Base* p);
void identify(Base& p);

#endif
