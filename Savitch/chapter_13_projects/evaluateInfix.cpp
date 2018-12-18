#include <evaluateInfix.hpp>
#include <sstream>
using namespace std;

namespace
{
	int char_to_int(char c)
	{
		return c - 48;
	}
}

namespace eric_infix_eval
{
	SolveInfix::SolveInfix()
	{
		//empty
	}
	
	SolveInfix::SolveInfix(const SolveInfix& copy) : stack(copy.stack),
		queue(copy.queue), postfix_calc(copy.postfix_calc)
	{
		//empty
	}
	
	SolveInfix::~SolveInfix()
	{
		stack.~Stack();
		queue.~Queue();
		postfix_calc.~RPNcalculator();
	}
	
	istream& operator >>(istream& ins, SolveInfix& right)
	{
		int i=0;
		char c;
		eric_stack_int::Stack s;
		do
		{
			i++;
			ins.get(c);
			if (c == 'q' || c == 'Q')
			{
				break;
			}
			else if (isdigit(c) || c == '\n')
			{
				if (c == '\n')
				{
					int order = 1;
					int total = 0;
					while (!s.empty())
					{
						total += order*s.pop();
						order *= 10;
					}
					if (total > 0)
					{
						//cout << "adding " << to_string(total) << " to the queue\n";
						right.queue.add(to_string(total));
					}
					continue;
				}
				s.push(char_to_int(c));
			}
			else if (c == '*' || c == '+' || c == '-' || c == '/')
			{
				string operator_str;
				operator_str.push_back(c);
				//cout << "pushing " << operator_str << " on the stack\n";
				right.stack.push(operator_str);
			}
			else if (c == ')')
			{
				string operator_str = right.stack.pop(); 
				//cout << "adding " << operator_str << " to the queue\n";  
				right.queue.add(operator_str);
			} 
			
		} while (i<10000);
		
		//~ cout << "contents of queue: \n"
			//~ << right.queue << "\n";
		string postfix_input;
		
		while (!right.queue.empty())
		{
			postfix_input += right.queue.remove();
			postfix_input += '\n';
		}
		postfix_input += 'q';
		
		//cout << postfix_input << "\n";
		stringstream ss;
		ss << postfix_input;
		ss >> right.postfix_calc; 
		return ins;
	}
}

