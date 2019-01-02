#include <convertDate.hpp>
#include <iostream>
using namespace std;

namespace date_convert_eric
{
	void convert()
	{
		while (1)
		{
			DateConverter time;
			cout << "Enter a date in 01/31 notation: ";
			try 
			{
				time.input();
			} 
			catch (MonthError)
			{
				cout << "Error inputing month\n";
				continue;
			}
			catch (DayError)
			{
				cout << "Error inputing day\n";
				continue;
			}
			time.output();
			cout << "\n";
		}		
	}
	
	//~ MonthError::MonthError(std::string the_message) : message(the_message)
	//~ {
		//~ //empty
	//~ }
	
	//~ string MonthError::get_message()
	//~ {
		//~ return message;
	//~ }
	
	//~ DayError::DayError(string the_message) : message(the_message)
	//~ {
		//~ //empty
	//~ }
	
	//~ string DayError::get_message()
	//~ {
		//~ return message;
	//~ }
	
	DateConverter::DateConverter() : month("no month yet"), day(0)
	{
		//empty
	}
	
	void DateConverter::input() throw(MonthError, DayError, std::string)
	{
		string raw_input;
		getline(cin, raw_input);
		
		string month_str = "";
		string day_str = "";
		uint32_t index = 0;
		
		//first get the month in string form 
		for (; index < raw_input.length(); index++)
		{
			char c = raw_input[index];
			//cout << c << "\n";
			if (isdigit(c))
			{
				month_str += c;
			}
			else if (c == ' ')
			{
				continue;
			}
			else if (c == '/')
			{
				//we got the whole month in string form
				
				int the_month = stoi(month_str);
				if (the_month < 1 || the_month > 12)
				{
					throw(MonthError());
				}
				month = get_month_str(the_month);
				//cout << "the month is " << month << "\n";
				index++;
				break;
			}
			else
			{
				throw(MonthError());
			}
		}
		
		//now get the day in string form 
		for (; index < raw_input.length(); index++)
		{
			char c = raw_input[index];
			//cout << c << "\n";
			if (isdigit(c))
			{
				day_str += c;
			}
			else
			{
				throw(DayError());
			}
			if (index == raw_input.length()-1)
			{
				//we got the whole day in string form
				//cout << "the day is " << day_str << "\n";
				day = stoi(day_str);
				if (!check_day(month, day))
				{
					throw(DayError());
				}
				return;
			}
			else if (c == ' ')
			{
				continue;
			}
		}
	}
	
	std::string DateConverter::get_month_str(int the_month)
	{
		if (the_month == 1)
		{
			return "January";
		}
		else if (the_month == 2)
		{
			return "February";
		}
		else if (the_month == 3)
		{
			return "March";
		}		
		else if (the_month == 4)
		{
			return "April";
		}
		else if (the_month == 5)
		{
			return "May";
		}
		else if (the_month == 6)
		{
			return "June";
		}
		else if (the_month == 7)
		{
			return "July";
		}	
		else if (the_month == 8)
		{
			return "August";
		}
		else if (the_month == 9)
		{
			return "September";
		}
		else if (the_month == 10)
		{
			return "October";
		}	
		else if (the_month == 11)
		{
			return "November";
		}
		else if (the_month == 12)
		{
			return "December";
		}

		throw(MonthError());
	}
		
	bool DateConverter::check_day(string the_month, int the_day)
	{
		//cout << "checking day. The month is " << the_month << "\n";
		if (the_month == "January")
		{
			return (the_day <= 31);
		}
		else if (the_month == "February")
		{
			return (the_day <= 29);
		}
		else if (the_month == "March")
		{
			return (the_day <= 31);
		}
		else if (the_month == "April")
		{
			return (the_day <= 30);
		}
		else if (the_month == "May")
		{
			return (the_day <= 31);
		}
		else if (the_month == "June")
		{
			return (the_day <= 30);
		}
		else if (the_month == "June")
		{
			return (the_day <= 30);
		}
		else if (the_month == "July")
		{
			return (the_day <= 31);
		}
		else if (the_month == "August")
		{
			return (the_day <= 31);
		}
		else if (the_month == "September")
		{
			return (the_day <= 30);
		}
		else if (the_month == "October")
		{
			return (the_day <= 31);
		}
		else if (the_month == "November")
		{
			return (the_day <= 30);
		}
		else if (the_month == "December")
		{
			return (the_day <= 31);
		}
		else
		{
			return false;
		}		
	}
	
	void DateConverter::output()
	{
		cout << month << " " << day;
	}
}
