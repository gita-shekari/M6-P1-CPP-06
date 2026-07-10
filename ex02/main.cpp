/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshekari <gshekari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 22:14:42 by gshekari          #+#    #+#             */
/*   Updated: 2026/07/10 14:40:23 by gshekari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate()
{
	int i = std::rand();
	if (i % 3 == 0)
		return new A();
	else if(i % 3 == 1)
		return new B();
	else
		return new C();
}
void identify(Base* p)
{
	if(dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if(dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if(dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "NULL" << std::endl;
}
void identify(Base& p)
{
	try
	{
		A &a= dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A" << std::endl;
		return;
	}
	catch(const std::exception& e)
	{
	}
	try
	{
		B &b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "B" << std::endl;
		return;
	}
	catch(const std::exception& e)
	{
	}
	try
	{
		C &c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "C" << std::endl;
		return;
	}
	catch(const std::exception& e)
	{
	}
}

int main()
{
	std::cout << "\n--- Testing poiter ---\n";
	std::srand(std::time(NULL));
	Base *base1 = generate();
	identify(base1);

	Base *base2 = generate();
	identify(base2);

	Base *base3 = generate();
	identify(base3);

	Base *base4 = generate();
	identify(base4);

	Base *base5 = NULL;
	identify(base5);

	std::cout << "\n--- Testing refrence ---\n";

	identify(*base1);
	identify(*base2);
	identify(*base3);
	identify(*base4);

	delete base1;
	delete base2;
	delete base3;
	delete base4;

	return 0;
}
