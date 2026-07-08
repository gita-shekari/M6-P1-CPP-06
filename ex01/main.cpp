/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshekari <gshekari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 04:16:15 by gshekari          #+#    #+#             */
/*   Updated: 2026/07/08 21:40:03 by gshekari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

int main()
{
	std::cout << "\n--- basic test ---\n";
	Data data;
	data.value = 3;
	uintptr_t raw = Serializer::serialize(&data);
	Data* restored = Serializer::deserialize(raw);
	std::cout << std::boolalpha;
	std::cout << (&data == restored) << std::endl;

	std::cout << "\n--- printing pointer before serialiation and after deserilization ---\n";
	Data data1;
	data1.value = 42;
	Data* before = &data1;
	std::cout << "Before: " << before << std::endl;
	uintptr_t raw1 = Serializer::serialize(before);
	std::cout << "Raw: " << raw1 << std::endl;
	Data* after = Serializer::deserialize(raw1);
	std::cout << "After: " << after << std::endl;

	std::cout << "\n---testing null pointer ---\n";
	Data *data2 = NULL;
	uintptr_t raw2 = Serializer::serialize(data2);
	Data* restored2 = Serializer::deserialize(raw2);
	std::cout << (restored2 == NULL) << std::endl;
	return 0;
}
