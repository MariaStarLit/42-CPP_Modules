#include "BitcoinExchange.hpp"

//Constructores
BitcoinExchange::BitcoinExchange()
{
	prev_date = "";
	extractDatabase();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
	*this = copy;
}

//Destructor
BitcoinExchange::~BitcoinExchange()
{}

//Operator
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy)
{
	if ( this != &copy )
	{
		this->my_data = copy.my_data;
	}
	return *this;
}

//Member functions
void	BitcoinExchange::extractDatabase(void)
{
	std::string line, header, check_header;
	check_header = "";
	bool error_parcing = false;
	std::ifstream file("data.csv");
	if (!file.is_open() )
	{
		std::cout << RED << "Error: could not open file 'data.csv'." << RESET << std::endl;
		throw ParcingException();
	}

	std::getline(file, line);
	std::istringstream aux(line);
	header = line;
	if (header != "date,exchange_rate")
	{
		std::cout << RED << "Error: bad database header => " << header << RESET << std::endl;
		throw ParcingException();
	}
	while(std::getline(file, line))
	{
		Data valid = parcingDatabaseLine(line, error_parcing);
		if (!error_parcing)
			my_data[valid.date] = valid.value;
		else
			throw ParcingException();
	}
	file.close();
	if (my_data.size() == 0)
	{
		std::cout << RED << "Error: file can not be empty." << RESET << std::endl;
		throw ParcingException();
	}
}

void	BitcoinExchange::extractFile(const std::string &file_name)
{
	float res;
	std::string line, header;
	bool error_parcing = false;
	std::ifstream file(file_name.c_str());
	if (!file.is_open())
	{
		std::cout << RED << "Error: could not open file." << RESET << std::endl;
		throw ParcingException();
	}
	std::getline(file, line);
	std::istringstream aux(line);
	header = line;
	if (header != "date | value")
		std::cout << RED << "Error: bad header => " << header << RESET << std::endl;
	while(std::getline(file, line))
	{
		Data valid = parcingFileLine(line, error_parcing);
		if (!error_parcing)
		{
			res = exchangeRate(valid.date, valid.value);
			std::cout << valid.date << " => "  << valid.value << " = " << res << std::endl;
			//<< std::fixed << std::setprecision(2)
		}
	}
	file.close();
}

float	BitcoinExchange::exchangeRate(const std::string &date, float value) const
{
	std::map<std::string, float>::const_iterator it = my_data.begin();
	std::map<std::string, float>::const_iterator ite = my_data.end();

	float pre_v = 0;
	while (it != ite)
	{
		if (date <= it->first)
		{
			if (date == it->first)
				pre_v = it->second;
			break ;
		}
		pre_v = it->second;
		it++;
	}
	float resolt = pre_v * value;
	return (resolt);
}

bool BitcoinExchange::validDate(std::string &date)
{
	if (date.length() != 10)
		return (false);
	for(int i = 0; date[i]; i++)
	{
		if (i == 4 || i == 7)
		{
			if (date[i] != '-')
				return (false);
		}
		else if (!std::isdigit(date[i]))
			return (false);
	}

	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());
	int days_of_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	//std::cout << CYAN << year << "-" << month << "-" << day << RESET << std::endl;

	if (year < 2009 || year > 2024 || month < 1 || month > 12)
		return (false);
	if (year == 2024 && (month > 10 || (month == 10 && day > 29)))
		return (false);
	if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
		days_of_month[1] = 29;
	if (day < 1 || day > days_of_month[month - 1])
		return (false);
	return (true);
}

float BitcoinExchange::validValue(const std::string &val, char sep)
{
	int i = 0;
	bool flag = false;
	if (val.empty() || val == "-" || val == "+")
	{
		std::cout << RED << "Error: missing a number." << RESET << std::endl;
		return (-1);
	}
	if (val[i] == '-' || val[i] == '+')
		i++;
	while(val[i])
	{
		if (val[i] == '.' && i > 0 && flag == false)
		{
			flag = true;
			i++;
		}
		if (!std::isdigit(val[i]))
		{
			std::cout << RED << "Error: not a number." << RESET << std::endl;
			return (-1);
		}
		i++;
	}
	float value = std::atof(val.c_str());
	if (value < 0.0)
	{
		std::cout << RED << "Error: not a positive number." << RESET << std::endl;
		return (-1);
	}
	if (value > 1000.0 && sep == '|')
	{
		std::cout << RED << "Error: too large a number." << RESET << std::endl;
		return (-1);
	}
	//std::cout << value << std::endl;
	return (value);
}


//Struct functions
BitcoinExchange::Data::Data(const std::string &d, float v) : date(d), value(v)
{}

BitcoinExchange::Data	BitcoinExchange::parcingFileLine(const std::string &raw_line, bool &error)
{
	error = false;
	std::string date, line, aux_v, sep;
	size_t len = raw_line.size();
	float value = -1;

	//std::cout << CYAN << raw_line << RESET << std::endl;
	//std::cout << YELLOW << "date: " << date << RESET << std::endl;
	date = raw_line.substr(0, 10);
	if (!validDate(date))
	{
		std::cout << RED << "Error: bad input => " << date << RESET << std::endl;
		error = true;
		return (Data("", 0));
	}
	sep = raw_line.substr(10, 3);
	//std::cout << YELLOW << "sep : [" << sep << "]" << RESET << std::endl;
	if (sep != " | ")
	{
		std::cout << RED << "Error: bad line format." << RESET << std::endl;
		error = true;
		return (Data("", 0));
	}
	aux_v = raw_line.substr(13, len);
	value = validValue(aux_v, '|');
	//std::cout << YELLOW << "value: " << value << RESET << std::endl;
	if (value == -1) 
	{
		error = true;
		return (Data("", 0));
	}

	return (Data(date, value));
}

BitcoinExchange::Data	BitcoinExchange::parcingDatabaseLine(const std::string &raw_line, bool &error)
{
	error = false;
	std::string date, line, aux_v;
	size_t len = raw_line.size();
	float value = -1;

	date = raw_line.substr(0, 10).c_str();
	if (!validDate(date))
	{
		std::cout << RED << "Error: bad input => " << date << RESET << std::endl;
		error = true;
		return (Data("", 0));
	}
	if (strcmp(date.c_str(), this->prev_date.c_str()) < 0)
	{
		std::cout << RED << "Error: invalid date order => " << date << RESET << std::endl;
		error = true;
		return (Data("", 0));
	}
	this->prev_date = date;

	if (raw_line[10] != ',')
	{
		std::cout << RED << "Error: bad line format." << RESET << std::endl;
		error = true;
		return (Data("", 0));
	}
	aux_v = raw_line.substr(11, len);
	value = validValue(aux_v, ',');
	if (value == -1) 
	{
		error = true;
		return (Data("", 0));
	}
	return (Data(date, value));
}

//Exception
const char *BitcoinExchange::ParcingException::what() const throw()
{
	return ("");
}
