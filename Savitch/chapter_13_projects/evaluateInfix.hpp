#ifndef EVALUATE_INFIX_H
#define EVALUATE_INFIX_H
#include <stackString.hpp>
#include <queueString.hpp>
#include <reversePolishNotation.hpp>
#include <iostream>

namespace eric_infix_eval
{
	class SolveInfix {
	public:
		SolveInfix();
		SolveInfix(const SolveInfix& copy);
		~SolveInfix();
		
		friend std::istream& operator >>(std::istream& ins, SolveInfix& right);
	
	private:
		eric_stack_string::Stack stack;
		eric_queue_string::Queue queue;
		eric_rpn::RPNcalculator postfix_calc;
	};
}

#endif //EVALUATE_INFIX_H
