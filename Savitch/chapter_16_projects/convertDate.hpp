#ifndef CONVERT_DATE_H
#define CONVERT_DATE_H
#include <string>

namespace date_convert_eric
{
	void convert();
	
	//~ class MonthError
	//~ {
	//~ public:
		//~ MonthError(std::string the_message);
		//~ std::string get_message();
	//~ private:
		//~ std::string message;
	//~ };
	
	class MonthError
	{};
	
	//~ class DayError
	//~ {
	//~ public:
		//~ DayError(std::string the_message);
		//~ std::string get_message();
	//~ private:
		//~ std::string message;
	//~ };
	
	class DayError
	{};
	
	class DateConverter
	{
	public:
		DateConverter();
		void input() throw(MonthError, DayError, std::string);
		void output();
	private:
		std::string get_month_str(int the_month);
		bool check_day(std::string the_month, int the_day);
		
		std::string month;
		int day;	
	};
}

#endif //CONVERT_DATE_H
