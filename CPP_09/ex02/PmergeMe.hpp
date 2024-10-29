# pragma once

# define RESET "\033[0m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define PURPLE "\033[0;35m"
# define CYAN "\033[0;36m"

# include <iostream>
# include <sstream>
# include <string>
# include <vector>
# include <list>
# include <algorithm>
# include <climits>
# include <ctime>

class PmergeMe
{
	private:
		bool				odd_nbr;
		int					straggler;
		static const int	jacobsthal[34];

		std::vector<int>inputVec;
		std::vector<int>aVec;
		std::vector<int>bVec;

		std::list<int>inputList;
		std::list<int>aList;
		std::list<int>bList;

		PmergeMe();									//Default Constructor
		PmergeMe(const PmergeMe &copy);				//Copy Constructor
		PmergeMe &operator=(const PmergeMe &copy);	//Copy Operator

	public:
		PmergeMe(std::vector<int> _aux);			//Constructor
		~PmergeMe();								//Destructor

		//Member Functions
		//List
		void						makePairList(void);
		bool						isAListSorted(void);
		void						sortPairList(void);
		std::list<int>::iterator	getPositionList(int nbr);
		void						insertBList(void);
		void						sortList(void);
		bool						isSortedList(void);

		//Vector
		void						makePairVector(void);
		bool						isAVectorSorted(void);
		void						sortPairVector(void);
		std::vector<int>::iterator	getPositionVector(int nbr);
		void						insertBVector(void);
		void						sortVector(void);
		bool						isSortedVector(void);
};
