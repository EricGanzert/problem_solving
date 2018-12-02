#include <digitalTime.hpp>
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
	
}//unnamed namespace

namespace d_time_eric
{
	bool operator ==(const DigitalTime& time1, const DigitalTime& time2)
	{
		return (time1.hour == time2.hour && time1.minute == time2.minute);
	}
	
	//uses iostream and cstdlib
	DigitalTime::DigitalTime(int the_hour, int the_minute)
	{
		if (the_hour < 0 || the_hour > 23 || the_minute < 0 || the_hour > 59)
		{
			cout << "Illegal argument to DigitalTime constructor\n";
			exit(1);
		}
		else
		{
			hour = the_hour;
			minute = the_minute;
		}
	}
	
	DigitalTime::DigitalTime() : hour(0), minute(0)
	{
		//empty
	}
	
	void DigitalTime::advance(int minutes_added)
	{
		int gross_minutes = minute + minutes_added;
		minute = gross_minutes % 60;
		
		int hour_adjustment = gross_minutes / 60;
		hour = hour_adjustment % 24;
	}
	
	void DigitalTime::advance(int hours_added, int minutes_added)
	{
		hour = hours_added % 24;
		advance(minutes_added);
	}
	
	ostream& operator <<(ostream& outs, const DigitalTime& the_object)
	{
		outs << the_object.hour << ":";
		if (the_object.minute < 10)
		{
			outs << "0";
		}
		outs << the_object.minute;
		return outs;
	}
	
	istream& operator >>(istream& ins, DigitalTime& the_object)
	{
		read_hour(ins, the_object.hour);
		read_minute(ins, the_object.minute);
		return ins;
	}
	
	void DigitalTime::interval_since(const DigitalTime& a_previous_time,
		int& hours_in_interval, int& minutes_in_interval) const
	{
		int hour_diff = this->hour - a_previous_time.hour;
		int minute_diff = this->minute - a_previous_time.minute;
		
		if (hour_diff >= 0) //same day
		{
			hours_in_interval = hour_diff;
		}
		else //previous day
		{
			hours_in_interval = 24 + hour_diff;
		}
		
		if (minute_diff >= 0)
		{
			minutes_in_interval = minute_diff;
		}
		else
		{
			minutes_in_interval = 60 + minute_diff;
		}
	}
	
}//d_time_eric

