#include "Serializer.hpp"

//pointeur > int
uintptr_t Serializer::serialize(Data* ptr)
{
    // reinterpret_cast = "réinterprète les bits"
    return reinterpret_cast<uintptr_t>(ptr);
}

//int > pointeur
Data* Serializer::deserialize(uintptr_t raw)
{
    // On remet les bits dans leur forme de pointeur
    return reinterpret_cast<Data*>(raw);
}














Serializer::Serializer() {}

Serializer::Serializer(const Serializer &copy)
{
	*this = copy;
}

Serializer &Serializer::operator=( const Serializer &autre )
{
	(void)autre;
    return (*this);
}

Serializer::~Serializer() {}