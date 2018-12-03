#include <digitalTime2.hpp>
#include <cctype>

using namespace std;

namespace 
{
	int digit_to_int(char c)
	{
		return (static_cast<int>(c) - static_cast<int>('0'));
	}
	
	void read_hour(istream& ins, int& the_hour)
	{
		char c1, c2;
		ins >> c1 >> c2;
		if (!(isdigit(c1) && (isdigit(c2) || c2 == ':')))
		{
			cout << "Error illegal input to read_hour\n";
			exit(1);
		}
		
		if (isdigit(c1) && c2 == ':')
		{
			the_hour = digit_to_int(c1);
		}
		else //isdigit(c1) && isdigit(c2)
		{
			the_hour = digit_to_int(c1)*10 + digit_to_int(c2);
			ins >> c2; // discard ':'
			if (c2 != ':')
			{
				cout << "Error illegal input to read hour\n";
				exit(1);
			}
		}
		if (the_hour < 0 || the_hour > 23)
		{
				cout << "Error illegal input to read hour\n";
				exit(1);			
		}
	}
	
	void read_minute(istream& ins, int& the_minute)
	{
		char c1, c2;
		ins >> c1 >> c2;
		
		if (!(isdigit(c1) && isdigit(c2)))
		{
			cout << "Error illegal input to read_minute\n";
			exit(1);
		}
		
		the_minute = digit_to_int(c1)*10 + digit_to_int(c2);
		
		if (the_minute < 0 || the_minute > 59)
		{
			cout << "Error illegal input to read_minute\n";
			exit(1);			
		}
	}
	
	void hour_and_minute_to_all_minutes(int hour, int minute, int& result_minutes)
	{
		int gross_minutes = hour * 60 + minute;
		result_minutes = gross_minutes % 1440;
	}
	
	void all_minutes_to_hour_and_minute(int minutes, int& result_hour, int& result_minute)
	{
		result_hour = minutes / 60;
		result_minute = minutes % 60;
	}
	
}//unnamed namespace

namespace d_time2_eric
{
	bool operator ==(const DigitalTime& time1, const DigitalTime& time2)
	{
		return (time1.minutes == time2.minutes);
	}
	
	//uses iostream and cstdlib
	DigitalTime::DigitalTime(int the_hour, int the_minute)
	{
		hour_and_minute_to_all_minutes(the_hour, the_minute, this->minutes);
	}
	
	DigitalTime::DigitalTime() : minutes(0)
	{
		//empty
	}
	
	void DigitalTime::advance(int minutes_added)
	{
		int gross_minutes = minutes + minutes_added;
		minutes = gross_minutes % 1440;
	}
	
	void DigitalTime::advance(int hours_added, int minutes_added)
	{
		advance(hours_added*60 + minutes_added);
	}
	
	ostream& operator <<(ostream& outs, const DigitalTime& the_object)
	{
		int hour, minute;
		all_minutes_to_hour_and_minute(the_object.minutes, hour, minute);
		
		outs << hour << ":";
		if (minute < 10)
		{
			outs << "0";
		}
		outs << minute;
		return outs;
	}
	
	istream& operator >>(istream& ins, DigitalTime& the_object)
	{
		int hour, minute;
		read_hour(ins, hour);
		read_minute(ins, minute);
		the_object = DigitalTime(hour, minute);
		return ins;
	}
	
	void DigitalTime::interval_since(const DigitalTime& a_previous_time,
		int& hours_in_interval, int& minutes_in_interval) const
	{
		int minutes_diff = this->minutes - a_previous_time.minutes;
		
		if (minutes_diff < 0) //previous day
		{
			minutes_diff = 1440 + minutes_diff;
		}
		
		all_minutes_to_hour_and_minute(minutes_diff, hours_in_interval, minutes_in_interval);
	}
	
}//d_time2_eric

