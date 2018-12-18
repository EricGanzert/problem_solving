#ifndef REVERSE_POLISH_NOTATION_H
#define REVERSE_POLISH_NOTATION_H
#include <stackInt.hpp>
#include <iostream>

namespace eric_rpn
{
	class RPNcalculator {
	public:
		RPNcalculator();
		RPNcalculator(const RPNcalculator& copy);
		~RPNcalculator();
		
		friend std::istream& operator >>(std::istream& ins, RPNcalculator& right);
		
	private:
		void add_number(int the_number);
		void add_operator(char the_operator);
		eric_stack_int::Stack stack;
	};

}// eric_stack_int

#endif //REVERSE_POLISH_NOTATION_H
