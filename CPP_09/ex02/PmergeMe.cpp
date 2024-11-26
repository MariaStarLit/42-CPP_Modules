#include "PmergeMe.hpp"

//Constructores
PmergeMe::PmergeMe()
{}

PmergeMe::PmergeMe(std::vector<int> aux)
{
	this->odd_nbr = false;
	std::vector<int>::iterator it = aux.begin();
	std::vector<int>::iterator itend = aux.end();
	while (it < itend)
	{
		int n = *it;
		this->inputVec.push_back(n);
		this->inputList.push_back(n);
		it++;
	}
}

PmergeMe::PmergeMe(const PmergeMe &copy)
{
	*this = copy;
}

//Operator
PmergeMe &PmergeMe::operator=(const PmergeMe &copy)
{
	(void)copy;
	return *this;
}

//Destructor
PmergeMe::~PmergeMe()
{}

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< List >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void	PmergeMe::makePairList(void)
{
	if (this->inputList.size() % 2 != 0)
	{
		this->odd_nbr = true;
		this->straggler = this->inputList.back();
		this->inputList.pop_back();
	}

	std::list<int>::iterator a_first, a_second;
	a_first = inputList.begin(); 
	a_second = inputList.begin();
	std::advance(a_second, 1);
	while(a_first != inputList.end())
	{
		if (a_second == inputList.end())
			break;
		
		if (*a_first < *a_second)
			std::iter_swap(a_first, a_second);
		aList.push_back(*a_first);
		bList.push_back(*a_second);
		std::advance(a_first, 2);
		std::advance(a_second, 2);
	}
}

bool	PmergeMe::isAListSorted(void)
{
	std::list<int>::iterator a_first, a_second;
	a_second = aList.begin();
	std::advance(a_second, 1);
	for (a_first = aList.begin(); a_first != aList.end(); ++a_first, ++a_second)
	{
		if (a_second == aList.end())
				break;
		if (*a_first > *a_second)
			return (false);
	}
	return (true);
}

void	PmergeMe::sortPairList(void)
{
	std::list<int>::iterator a_first, a_second, b_first, b_second;
	while (!isAListSorted())
	{
		a_first = aList.begin();
		a_second = aList.begin();
		b_first = bList.begin();
		b_second = bList.begin();
		std::advance(a_second, 1);
		std::advance(b_second, 1);
		while((a_first != aList.end()) || (b_first != bList.end()))
		{
			if (a_second == aList.end())
				break;
			if (*a_first > *a_second)
			{
				std::iter_swap(a_first, a_second);
				std::iter_swap(b_first, b_second);
			}
			a_first++;
			b_first++;
			a_second++;
			b_second++;
		}
	}
	// std::cout << BLUE << "a: " << RESET;
	// std::list<int>::iterator iter;
	// for (iter = aList.begin(); iter != aList.end(); ++iter)
	// {
	// 	std::cout << *iter << " ";
	// }
	// std::cout << std::endl << BLUE << "b: " << RESET;
	// for (iter = bList.begin(); iter != bList.end(); ++iter)
	// {
	// 	std::cout << *iter << " ";
	// }
	// std::cout << std::endl;
}

std::list<int>::iterator PmergeMe::getPositionList(int nbr)
{
	std::list<int>::iterator it;
	for (it = aList.begin(); it != aList.end(); ++it)
	{
		if (*it > nbr)
			return(it);
	}
	return(aList.end());
}

const int PmergeMe::jacobsthal[34] =
{
	0, 1, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923,
	21845, 43691, 87381, 174763, 349525, 699051, 1398101, 2796203, 5592405,
	11184811, 22369621, 44739243, 89478485, 178956971, 357913941, 715827883,
	1431655765
};

void	PmergeMe::insertBList()
{
	int ji = 0;
	while (jacobsthal[ji] < (int)bList.size())
	{
		++ji;
		int position = (jacobsthal[ji] < (int)bList.size()) ? jacobsthal[ji] : bList.size();
		while (jacobsthal[ji - 1] < position)
		{
			//std::cout << YELLOW << "B" << position << ", ";
			std::list<int>::iterator bList_it = bList.begin();
			std::advance(bList_it, position - 1);
			if (bList_it != bList.end())
				aList.insert(getPositionList(*bList_it), *bList_it);
			position--;
		}
	}
	if (odd_nbr == true)
	{
		std::list<int>::iterator insertionPos;
		odd_nbr = false;
		insertionPos = getPositionList(straggler);
		aList.insert(insertionPos, straggler);
	}
	//std::cout << RESET << std::endl;
}

void	PmergeMe::sortList(void)
{
	std::list<int>::iterator			it;
	std::clock_t						list_start, list_end;
	double								list_time;

	// std::cout << CYAN << "Before: " << RESET;
	// for(it = this->inputList.begin(); it != this->inputList.end(); it++)
	// 	std::cout << *it << " ";
	// std::cout << std::endl;
	
	list_start = std::clock();
	makePairList();
	sortPairList();
	insertBList();
	list_end = std::clock();
	list_time = static_cast<double>(list_end - list_start) / CLOCKS_PER_SEC;

	// std::cout << CYAN << "After:  " << RESET;
	// for(it = this->aList.begin(); it != this->aList.end(); it++)
	// 	std::cout << *it << " ";
	// std::cout << std::endl;

	std::cout << CYAN << "Time to process a range of " << this->inputList.size() 
	<< " elements with std::list    : " << std::fixed << list_time << "us" << std::endl;
}

bool	PmergeMe::isSortedList(void)
{
	std::list<int>::iterator a_first, a_second;
	a_second = aList.begin();
	std::advance(a_second, 1);
	std::cout << CYAN << "List:   " << RESET;
	for (a_first = aList.begin(); a_first != aList.end(); ++a_first, ++a_second)
	{
		if (a_second == aList.end())
				break;
		if (*a_first > *a_second)
		{
			std::cout << RED << "False" << RESET << std::endl;
			return (false);
		}
	}
	std::cout << GREEN << "True!" << RESET << std::endl;
	return (true);
}

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Vector >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void	PmergeMe::makePairVector(void)
{
	if (this->inputVec.size() % 2 != 0)
	{
		this->odd_nbr = true;
		this->straggler = this->inputVec.back();
		this->inputVec.pop_back();
	}

	std::vector<int>::iterator	it;
	for(it = inputVec.begin(); it != inputVec.end(); it += 2)
	{
		if ((it + 1) == inputVec.end())
			break;
		
		if (*it < *(it + 1))
			std::iter_swap(it, it + 1);
		aVec.push_back(*it);
		bVec.push_back(*(it + 1));
	}
}

bool	PmergeMe::isAVectorSorted(void)
{
	std::vector<int>::iterator iter;
	for (iter = aVec.begin(); iter != aVec.end(); ++iter)
	{
		if ((iter + 1) == aVec.end())
				break;
		if (*iter > *(iter + 1))
			return (false);
	}
	return (true);
}

void	PmergeMe::sortPairVector(void)
{
	std::vector<int>::iterator a_it;
	std::vector<int>::iterator b_it;
	while (!isAVectorSorted())
	{
		a_it = aVec.begin();
		b_it = bVec.begin();
		while((a_it != aVec.end()) || (b_it != bVec.end()))
		{
			if ((a_it + 1) == aVec.end())
				break;
			if (*a_it > *(a_it + 1))
			{
				std::iter_swap(a_it, a_it + 1);
				std::iter_swap(b_it, b_it + 1);
			}
			a_it++;
			b_it++;
		}
	}
	// std::cout << BLUE << "a: " << RESET;
	// std::vector<int>::iterator iter;
	// for (iter = aVec.begin(); iter != aVec.end(); ++iter)
	// {
	// 	std::cout << *iter << " ";
	// }
	// std::cout << std::endl << BLUE << "b: " << RESET;
	// for (iter = bVec.begin(); iter != bVec.end(); ++iter)
	// {
	// 	std::cout << *iter << " ";
	// }
	// std::cout << std::endl;
}

std::vector<int>::iterator PmergeMe::getPositionVector(int nbr)
{
	std::vector<int>::iterator it;
	for (it = aVec.begin(); it != aVec.end(); ++it)
	{
		if (*it > nbr)
			return(it);
	}
	return(aVec.end());
}

void	PmergeMe::insertBVector()
{
	int ji = 0;
	while (jacobsthal[ji] < (int)bVec.size())
	{
		++ji;
		int position = (jacobsthal[ji] < (int)bVec.size()) ? jacobsthal[ji] : bVec.size();
		while (jacobsthal[ji - 1] < position)
		{
			//std::cout << YELLOW << "B" << position << ", ";
			std::vector<int>::iterator bVec_it = bVec.begin() + position - 1;
			if (bVec_it != bVec.end())
				aVec.insert(getPositionVector(*bVec_it), *bVec_it);
			position--;
		}
	}
	if (odd_nbr == true)
	{
		std::vector<int>::iterator insertionPos;
		odd_nbr = false;
		insertionPos = getPositionVector(straggler);
		aVec.insert(insertionPos, straggler);
	}
	// std::cout << RESET << std::endl;
}

void	PmergeMe::sortVector(void)
{
	std::vector<int>::iterator			it;
	std::clock_t						vec_start, vec_end;
	double								vec_time;

	std::cout << PURPLE << "Before: " << RESET;
	for(it = this->inputVec.begin(); it != this->inputVec.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	
	vec_start = std::clock();
	makePairVector();
	sortPairVector();
	insertBVector();
	vec_end = std::clock();
	vec_time = static_cast<double>(vec_end - vec_start) / CLOCKS_PER_SEC;

	std::cout << PURPLE << "After:  " << RESET;
	for(it = this->aVec.begin(); it != this->aVec.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << PURPLE << "Time to process a range of " << this->inputVec.size() 
	<< " elements with std::verctor : " << std::fixed << vec_time << "us" << std::endl;
}

//final check
bool	PmergeMe::isSortedVector(void)
{
	std::vector<int>::iterator iter;
	std::cout << PURPLE << "Vector: " << RESET;
	for (iter = aVec.begin(); iter != aVec.end(); ++iter)
	{
		if ((iter + 1) == aVec.end())
				break;
		if (*iter > *(iter + 1))
		{
			std::cout << RED << "False" << RESET << std::endl;
			return (false);
		}
	}
	std::cout << GREEN << "True!" << RESET << std::endl;
	return (true);
}