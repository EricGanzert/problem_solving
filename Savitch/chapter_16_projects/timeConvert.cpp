#include <timeConvert.hpp>
#include <iostream>

using namespace std;
namespace time_convert_eric
{
	void convert()
	{
		while (1)
		{
			TwelveHourTime time;
			cout << "Enter time in 24-hour notation: ";
			try 
			{
				time.input();
			} 
			catch (TimeFormatMistake e)
			{
				cout << e.get_message() << "\n";
				continue;
			}
			time.output();
			cout << "\n";
		}
	}
	
	TimeFormatMistake::TimeFormatMistake(std::string the_message) : message(the_message)
	{
		//empty
	}
	
	std::string TimeFormatMistake::get_message()
	{
		return message;
	}
	
	TwelveHourTime::TwelveHourTime() : 	hour(0), minute(0)
	{
		//empty
	}
	
	void TwelveHourTime::input()
	{
		string raw_input;
		getline(cin, raw_input);
		
		string hour_str = "";
		string minute_str = "";
		uint32_t index = 0;
		for (; index < raw_input.length(); index++)
		{
			char c = raw_input[index];
			//cout << c << "\n";
			
			if (c == ':')
			{
				if (hour_str.length() == 0 || hour_str.length() > 2)
				{
					throw(TimeFormatMistake("ERROR: Wrong number of digits in hour"));
				}
				hour = stoi(hour_str);
				if (hour > 23)
				{
					throw(TimeFormatMistake("ERROR: hour too large"));
				}
				hour = hour % 12;
				//cout << "the hour is " << hour << "\n";
				index++;
				break;
				
			}
			else if (c == ' ')
			{
				continue;
			}
			else if (!isdigit(c))
			{
				throw(TimeFormatMistake("ERROR: expecting digit"));
			}
			hour_str += c;
		}
		
		for (; index < raw_input.length(); index++)
		{
			char c = raw_input[index];
			//cout << c << "\n";
			
			if (index == raw_input.length()-1)
			{
				if (isdigit(c))
				{
					minute_str += c;
				}
				else if (c != ' ')
				{
					throw(TimeFormatMistake("ERROR: expecting digit"));
				}
				if (minute_str.length() == 0 || minute_str.length() > 2)
				{
					throw(TimeFormatMistake("ERROR: Wrong number of digits in hour"));
				}
				minute = stoi(minute_str);
				if (minute > 59)
				{
					throw(TimeFormatMistake("ERROR: minute too large"));
				}
				//cout << "the minute is " << minute << "\n";
				break;
				
			}
			else if (c == ' ')
			{
				continue;
			}
			else if (!isdigit(c))
			{
				throw(TimeFormatMistake("ERROR: expecting digit"));
			}
			minute_str += c;
		}
	}
	
	void TwelveHourTime::output()
	{
		cout << hour << ":" << minute;
	}
		
}
