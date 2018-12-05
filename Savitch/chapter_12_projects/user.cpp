#include <iostream>
#include <cctype>

namespace
{
	std::string username = "none";
	
	bool isValid()
	{
		if (username.length() != 8)
		{
			return false;
		}
		else
		{
			for (int i=0; i < username.length(); i++)
			{
				if (!isalpha(username[i]))
				{
					return false;
				}
			}
			return true;			
		}

	}
}

namespace Authenticate
{
	void inputUserName()
	{
		do
		{
			std::cout << "Enter your username (8 letters only)" << std::endl;
			std::cin >> username;
		} while (!isValid());
	}
	
	std::string getUserName()
	{
		return username;
	}
}
