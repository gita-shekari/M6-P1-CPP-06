/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshekari <gshekari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 04:25:13 by gshekari          #+#    #+#             */
/*   Updated: 2026/07/08 04:26:56 by gshekari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{

}
Serializer::Serializer(const Serializer &)
{
}
Serializer &Serializer::operator=(const Serializer &)
{
	return *this;
}
Serializer::~Serializer()
{

}
static uintptr_t serialize(Data* ptr)
{

}
static Data* deserialize(uintptr_t raw)
{
	
}
