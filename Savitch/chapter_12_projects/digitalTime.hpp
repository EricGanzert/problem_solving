#ifndef DTIME_H
#define DTIME_H

#include <iostream>

namespace d_time_eric
{
	class DigitalTime
	{
	public:
		friend bool operator ==(const DigitalTime& time1, const DigitalTime& time2);
		//returns true if time1 and time2 represent the same time
		
		DigitalTime(int the_hour, int the_minute);
		//precondition: 0 <= hour <= 23 and 0 < minute < 59
		//initializes the time value to the_hour and the_minute
		
		DigitalTime();
		//initializes the time value to 0 or midnight
		
		void advance(int minutes_added);
		//precondition: the object has a time value
		//postcondition: the time has been changed to minutes_added minutes later
		
		void advance(int hours_added, int minutes_added);
		//precondition: the object has a time value
		//postcondition: the time has been advanced by 
		//hours_added hours and minutes_added minutes
		
		friend std::istream& operator >>(std::istream& ins, DigitalTime& the_object);
		//Overloards the >> operator for output values of type DigitalTime
		//Precondition: if ins is a file input stream, then ins has been already 
		//connected to a file
		
		friend std::ostream& operator <<(std::ostream& outs, const DigitalTime& the_object);
		//overloads the << operator for output values of type DigitalTime
		//precondition: if outs is a file output stream, then outs has 
		//already been connected to a file
		
		void interval_since(const DigitalTime& a_previous_time,
			int& hours_in_interval, int& minutes_in_interval) const;
		//computes the hours and minutes in between the given time
		//and the current time of the class object
		//if the previous_time argument is later than the current time
		//it is assumed that a_previous_time is from the previous day
		
	private:
		int hour;
		int minute;
	};
} //end d_time_eric

#endif //DTIME_H
