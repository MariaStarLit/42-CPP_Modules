# pragma once

# define RESET "\033[0m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define PURPLE "\033[0;35m"
# define CYAN "\033[0;36m"

# include <iostream>
# include <stdint.h>

typedef struct s_data
{
	int		nbr;
	char	ch;
}	Data;

class Serializer
{
	private:
		Serializer();									//Default constructor
		Serializer(const Serializer &copy);				//Copy constructor
		Serializer &operator=(const Serializer &copy);	//Copy assignment operator
		~Serializer();									//Destructor
	
	public:
		//Methods
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
};