#include "MutantStack.hpp"
#include <list>

int main(void)
{
	{
		std::cout << PURPLE << "<<<<<<<<<<<<<<<<<<<<<<<<<< Stack Tests >>>>>>>>>>>>>>>>>>>>>>>>>>" << RESET << std::endl;
		MutantStack<int> mstack;
		if (mstack.empty())
			std::cout << CYAN << "Empty" << RESET << std::endl;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl; // prints last elemnet inserted in the stack
		mstack.pop(); // removes last elemnet (17) form the stack
		std::cout << mstack.size() << std::endl; // size is 1 -> stack only has element 5
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		std::cout << GREEN << "Stack:" << RESET << std::endl;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::cout << GREEN << "Copy:" << RESET << std::endl;
		std::stack<int> s(mstack);
		if (s.empty())
			std::cout << CYAN << "Empty" << RESET << std::endl;
		MutantStack<int>::iterator s_it = mstack.begin();
		MutantStack<int>::iterator s_ite = mstack.end();
		while (s_it != s_ite)
		{
			std::cout << *s_it << std::endl;
			s_it++;
		}
	}
	{
		std::cout << std::endl << PURPLE << "<<<<<<<<<<<<<<<<<<<<<<<<<< List Tests >>>>>>>>>>>>>>>>>>>>>>>>>>>" << RESET << std::endl;
		std::list<int> mstack;
		if (mstack.empty())
			std::cout << CYAN << "Empty" << RESET << std::endl;
		mstack.push_back(5);
		mstack.push_back(17);
		std::cout << mstack.back() << std::endl;
		mstack.pop_back();
		std::cout << mstack.size() << std::endl;
		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		//[...]
		mstack.push_back(0);
		std::list<int>::iterator it = mstack.begin();
		std::list<int>::iterator ite = mstack.end();
		++it;
		--it;
		std::cout << GREEN << "List:" << RESET << std::endl;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::cout << GREEN << "Copy:" << RESET << std::endl;
		std::list<int> s(mstack);
		if (s.empty())
			std::cout << CYAN << "Empty" << RESET << std::endl;
		std::list<int>::iterator s_it = mstack.begin();
		std::list<int>::iterator s_ite = mstack.end();
		while (s_it != s_ite)
		{
			std::cout << *s_it << std::endl;
			s_it++;
		}
	}
	return (0);
}