#include <iostream>
#include <cctype>

namespace
{
	std::string password = "none";
	
	bool isValid()
	{
		if (password.length() < 8)
		{
			return false;
		}
		else
		{
			int number_count = 0;
			for (int i=0; i < password.length(); i++)
			{
				if (isdigit(password[i]))
				{
					number_count++;
				}
			}
			return (number_count > 0);
		}
	}
	
}

namespace Authenticate
{
	void inputPassword()
	{
		do
		{
			std::cout << "Enter your password (8 characters minimum with at least 1 number)" << std::endl;
			std::cin >> password;
		} while (!isValid());
	}
	
	std::string getPassword()
	{
		return password;
	}
}
