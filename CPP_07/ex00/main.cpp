#include "whatever.hpp"

int main(void)
{
	{
		std::cout << PURPLE << "<<<<<<<<<<<<<<<<<<<<<<<<<< Mandatory Tests >>>>>>>>>>>>>>>>>>>>>>>>>>" << RESET << std::endl << std::endl;
		int a = 2;
		int b = 3;
		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
		std::string c = "chaine1";
		std::string d = "chaine2";
		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl << std::endl;
	}
	{
		std::cout << PURPLE << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< My Tests >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << RESET << std::endl << std::endl;
		char a = 'A';
		char b = 'B';
		::swap( a, b );
		std::cout << GREEN << "char:"<< std::endl;
		std::cout << CYAN << "a = " << RESET << a << std::endl;
		std::cout << CYAN << "b = " << RESET << b << std::endl;
		std::cout << CYAN << "min = " << RESET << ::min( a, b ) << std::endl;
		std::cout << CYAN << "max = " << RESET << ::max( a, b ) << std::endl << std::endl;

		float c = -12.34;
		float d = 42.05;
		::swap(c, d);
		std::cout << std::endl << GREEN << "float:"<< std::endl;
		std::cout << CYAN << "c = " << RESET << c << std::endl;
		std::cout << CYAN << "d = " << RESET << d << std::endl;
		std::cout << CYAN << "min = " << RESET << ::min( c, d ) << std::endl;
		std::cout << CYAN << "max = " << RESET << ::max( c, d ) << std::endl;
		
		double e = 1870.4765;
		double f = -4274.06;
		::swap(e, f);
		std::cout << std::endl << GREEN << "double:"<< std::endl;
		std::cout << CYAN << "e = " << RESET << e << std::endl;
		std::cout << CYAN << "f = " << RESET << f << std::endl;
		std::cout << CYAN << "min = " << RESET << ::min( e, f ) << std::endl;
		std::cout << CYAN << "max = " << RESET << ::max( e, f ) << std::endl;
	}
	return 0;
}

// Expected output of Mandatory Tests:

// a = 3, b = 2
// min(a, b) = 2
// max(a, b) = 3
// c = chaine2, d = chaine1
// min(c, d) = chaine1
// max(c, d) = chaine2