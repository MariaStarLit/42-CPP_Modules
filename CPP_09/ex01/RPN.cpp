#include "RPN.hpp"

std::stack<double> RPN::pile_n;
double RPN::result;

//Constructores
RPN::RPN()
{}

RPN::RPN(const RPN &copy)
{
	*this = copy;
}

//Destructor
RPN::~RPN()
{}

//Opecator
RPN &RPN::operator=(const RPN &copy)
{
	(void)copy;
	return *this;
}

//Member Functions
void	RPN::calculate(std::string exp)
{
	std::stringstream skipspace(exp);
	std::string input, op;
	op = "+-/*";
	if (exp.empty())
	{
		std::cout << RED << "Error! No expression found." << RESET<< std::endl;
		return ;
	}
	while (skipspace >> input)
	{
		//std::cout << "|" << input << "|" << std::endl;
		if (atoi(input.c_str()) < 0 || atoi(input.c_str()) > 9)
		{
			std::cout << RED << "Error! Invalid number needs to be from 0 to 9." << RESET<< std::endl;
			return ;
		}
		if ((input.length() == 1 && std::isdigit(input[0])) && (atoi(input.c_str()) >= 0 && atoi(input.c_str()) <= 9))
		{
			pile_n.push(input[0] - 48);
			result = atoi(input.c_str());
		}
		else if (input.length() == 1 && op.find(input[0]) != std::string::npos)
		{
			if (pile_n.size() < 2)
			{
				std::cout << RED << "Error! Insufficient numbers." << RESET<< std::endl;
				return ;
			}
			try
			{
				executeOperation(input[0]);
			}
			catch (std::exception &e)
			{
				std::cout << RED << e.what() << RESET << std::endl;
				return;
			}
		}
		else
		{
			std::cout << RED << "Error! Invalid input." << RESET<< std::endl;
			return ;
		}
	}
	if (pile_n.size() != 1)
		std::cout << RED << "Error! Insufficient operators." << RESET << std::endl;
	else
		std::cout << result << std::endl;
}


void RPN::executeOperation(char op)
{
	double tmp = pile_n.top();
	pile_n.pop();
	switch (op)
	{
		case '+':
			result = pile_n.top() + tmp;
			break ;
		case '-':
			result = pile_n.top() - tmp;
			break ;
		case '/':
			if (tmp == 0)
				throw std::runtime_error("Error! Cant't divide by zero.");
			result = pile_n.top() / tmp;
			break ;
		case '*':
			result = pile_n.top() * tmp;
			break ;
	}
	pile_n.pop();
	pile_n.push(result);
}