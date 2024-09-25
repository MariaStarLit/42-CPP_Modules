# include "Array.hpp"
# include <cstdlib>

//Constructores
template <typename T>
Array<T>::Array() : elements(NULL), n_el(0) 
{}

template <typename T>
Array<T>::Array(unsigned int n) : n_el(n)
{
	elements = new T[n_el]();
}

template <typename T>
Array<T>::Array(const Array &copy) : elements(NULL) 
{
	*this = copy;
}

//Destructor
template <typename T>
Array<T>::~Array()
{
	delete[] (elements);
}

//Operatores
template <typename T>
Array<T>&	Array<T>::operator=(const Array &copy)
{
	if (this != &copy)
	{
	
		delete[] elements;
		this->n_el = copy.n_el;
		elements = new T[n_el]();
		for (unsigned int i = 0; i < n_el; i++)
			this->elements[i] = copy.elements[i];
	}
	return (*this);
}

template <typename T>
T &Array<T>::operator[](unsigned int i) const
{
	if (i < 0 || i >= size())
		throw IndexException();
	return (elements[i]);
}

//Member function
template <typename T>
unsigned int	Array<T>::size(void) const
{
	return (n_el);
}
