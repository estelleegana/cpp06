#pragma once

#include <stdint.h>//uintptr_t

struct Data;

class Serializer
{
	private://constr en prive = classe non-instanciable
		Serializer();
		Serializer(const Serializer &copy);
		Serializer &operator=(const Serializer &autre);
		~Serializer();
	public:
		static uintptr_t serialize(Data* ptr);
		Data* deserialize(uintptr_t raw);
};