#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <cstdlib>
#include <ctime>

// class D : public Base
// {
// 	public:
// 		D() {
// 			std::cout << CYAN << "D constructor" << RESET << std::endl;
// 		}
// 		~D() {
// 			std::cout << CYAN << "D destructor" << RESET << std::endl;
// 		}
// };

Base	*generate(void)
{
	int	nbr = rand() % 3;

	switch(nbr)
	{
		case 0:
			return (new A());
		case 1:
			return (new B());
		case 2:
			return (new C());
		default:
			return (NULL);
	}
}

void identify(Base* p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << RED << "Unknown" << RESET << std::endl;
}

void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
	}
	catch (const std::exception &e)
	{
		try
		{
			(void)dynamic_cast<B &>(p);
			std::cout << "B" << std::endl;
		}
		catch (const std::exception &e)
		{
			try
			{
				(void)dynamic_cast<C &>(p);
				std::cout << "C" << std::endl;
			}
			catch (const std::exception &e)
			{
				std::cout << RED << "Unknown" << RESET << std::endl;
			}
		}
	}
}

int	main(void)
{
	srand(time(NULL));

	for(int i = 0; i < 3; i++)
	{
		Base *p = generate();

		identify(p); //void identify(Base* p)
		identify(*p); //void identify(Base& p)
		delete (p);
		std::cout << std::endl;
	}
	return (0);
}