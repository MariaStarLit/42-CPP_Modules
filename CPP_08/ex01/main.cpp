#include "Span.hpp"

int main()
{
	{
		std::cout << PURPLE << "<<<<<<<<<<<<<<<<<<<<<<<<<< Mandatory Tests >>>>>>>>>>>>>>>>>>>>>>>>>>" << RESET << std::endl;
		Span sp = Span(5);

		try
		{
			sp.addNumber(6);
			sp.addNumber(3);
			sp.addNumber(17);
			sp.addNumber(9);
			sp.addNumber(11);
			
			sp.addNumber(42);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}

	{
		std::cout << std::endl << PURPLE << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< My Tests >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << RESET << std::endl;
		Span seq = Span(8);
		std::vector<int> v(8, 42);
		std::cout << CYAN << "1st Sequence:" << RESET << std::endl;
		seq.addNumber(60);
		try 
		{
			std::cout << seq.shortestSpan() << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		v[0] = 5;
		v[1] = -2;
		seq.addNumbers(v.begin(), v.end());
		std::cout << seq.shortestSpan() << std::endl;
		std::cout << seq.longestSpan() << std::endl;

		std::cout << std::endl << CYAN << "2nd Sequence:" << RESET << std::endl;
		Span seq2 = Span(10000);
		std::vector<int> v2(10001, 42);
		try 
		{
			std::cout << seq2.longestSpan() << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		try
		{
			seq2.addNumber(666);
			seq2.addNumbers(v2.begin(), v2.end());
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
}