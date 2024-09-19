#include "Serializer.hpp"

//Constructores
Serializer::Serializer()
{}

Serializer::Serializer(const Serializer &copy)
{
	*this = copy;
}

Serializer &Serializer::operator=(const Serializer &copy)
{
	(void)copy;
	return (*this);
}

//Destructor
Serializer::~Serializer()
{}

//Methods
uintptr_t	Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*	Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}