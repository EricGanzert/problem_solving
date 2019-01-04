#ifndef NUMERIC_HIST_H
#define NUMERIC_HIST_H
#include <vector>
#include <string>

namespace numeric_value_eric
{
	class Error 
	{
	public:
		Error(std::string the_message);
		std::string get_message();
		 
	private:
		std::string message;
	};
	
	class Value
	{
	public:
		Value();
		Value(int the_key);
		Value(int the_key, int the_count);
		
		Value& operator =(const Value& right);
		
		int get_key();
		void set_key(int new_key);
		
		int get_count();
		void set_count(int new_count);
		void increment_count();
		//adds 1 to count
		
	private:
		int key;
		int count;
	};
	
	class NumericValues
	{
	public:
		NumericValues();
		
		void input() throw (Error);
		//user enters the digits
		
		void add_value(int new_value) throw(Error);
		//increments count for the given key or makes an entry for it
		
		void add_value(Value new_value) throw(Error);
		
		void output_hist();
		//outputs a textual histogram of the digits
		
	private:
		std::vector<Value> values;
	};
}

#endif //NUMERIC_HIST_H
