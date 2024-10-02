#pragma once

# define RESET "\033[0m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define PURPLE "\033[0;35m"
# define CYAN "\033[0;36m"

#include <iostream>
#include <string>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		typedef typename std::stack<T>::container_type::iterator iterator;

		MutantStack() : std::stack<T>() {}
		MutantStack(const MutantStack &copy) : std::stack<T>(copy) {}
		MutantStack &operator=(const MutantStack &copy)
		{
			if (this != &copy)
			{
				this->c = copy.c;
			}
			return *this;
		}
		~MutantStack() 
		{
			this->c.clear();
		}

		//Member functions
		iterator begin(void)
		{
			return (this->c.begin());
		}

		iterator end(void)
		{
			return (this->c.end());
		}
};

/*
*  Stack (gcc libstdc++ stack)
*
*  This is not a true container, but an @e adaptor.  It holds
*  another container, and provides a wrapper interface to that
*  container.  The wrapper is what enforces strict
*  first-in-last-out %stack behavior.
*
*  The second template parameter defines the type of the underlying
*  sequence/container.  It defaults to std::deque, but it can be
*  any type that supports @c back, @c push_back, and @c pop_back,
*  such as std::list, std::vector, or an appropriate user-defined
*  type.
*
*  Members not found in @a normal containers are @c container_type,
*  which is a typedef for the second Sequence parameter, and @c
*  push, @c pop, and @c top, which are standard %stack/FILO
*  operations.
*/
