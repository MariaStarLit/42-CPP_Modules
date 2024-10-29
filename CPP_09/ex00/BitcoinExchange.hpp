#pragma once

# define RESET "\033[0m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define PURPLE "\033[0;35m"
# define CYAN "\033[0;36m"

# include <iostream>
# include <string>
# include <map>
# include <cstring>
# include <cstdlib>
# include <fstream>
# include <sstream>
# include <iomanip>

class BitcoinExchange
{
	private:
		std::map<std::string, float>	my_data;
		std::string						prev_date;

		BitcoinExchange(const BitcoinExchange &copy);				//Copy Constructor
		BitcoinExchange &operator=(const BitcoinExchange &copy);	//Copy Assiment Operator

	public:
		BitcoinExchange();											//Default Constructor
		~BitcoinExchange();											//Destructor

		//Member Functions
		void		extractDatabase(void);
		void		extractFile(const std::string &file_name);
		float		exchangeRate(const std::string &date, float value) const;
		bool		validDate(std::string &date);
		float		validValue(const std::string &val, char sep);

		//Struct
		struct Data
		{
			Data(const std::string &d, float v);
			const std::string date;
			float value;
		};

		Data	parcingFileLine(const std::string &raw_line, bool &error);
		Data	parcingDatabaseLine(const std::string &raw_line, bool &error);

		//Exception
		class ParcingException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};
