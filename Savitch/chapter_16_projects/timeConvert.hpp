#ifndef TIME_CONVERT_H
#define TIME_CONVERT_H
#include <string>

namespace time_convert_eric
{
	void convert();
	
	class TimeFormatMistake
	{
	public:
		TimeFormatMistake(std::string the_message);
		std::string get_message();
	private:
		std::string message;
	};
	
	class TwelveHourTime
	{
	public:
		TwelveHourTime();
		void input() throw(TimeFormatMistake);
		void output();
	private:
		int hour;
		int minute;	
	};
}

#endif //TIME_CONVERT_H
