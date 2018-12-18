#include <reversePolishNotation.hpp>
#include <cctype>

namespace
{
	int char_to_int(char c)
	{
		return c - 48; 
	}
}	

namespace eric_rpn
{
	using namespace std;
	
	RPNcalculator::RPNcalculator()
	{
		//empty
	}
	
	RPNcalculator::RPNcalculator(const RPNcalculator& copy) : stack(copy.stack)
	{
		//empty
	}
	
	RPNcalculator::~RPNcalculator()
	{
		stack.~Stack();
	}
	
	istream& operator >>(istream& ins, RPNcalculator& right)
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
						right.add_number(total);
					}
					continue;
				}
				s.push(char_to_int(c));
			}
			else
			{
				right.add_operator(c);
			}
			
		} while (i<10000);
		
		cout << "the result is " << right.stack.pop() << "\n";
		return ins;
	}
	
	void RPNcalculator::add_number(int the_number)
	{
		stack.push(the_number);
	}
	
	void RPNcalculator::add_operator(char the_operator)
	{
		if (the_operator == '+')
		{
			int a, b;
			a = stack.pop();
			b = stack.pop();
			stack.push(a + b);
		}
		else if (the_operator == '-')
		{
			int a, b;
			a = stack.pop();
			b = stack.pop();
			stack.push(b - a);				
		}
		else if (the_operator == '*')
		{
			int a, b;
			a = stack.pop();
			b = stack.pop();
			stack.push(a * b);
		}
		else if (the_operator == '/')
		{
			int a, b;
			a = stack.pop();
			b = stack.pop();
			stack.push(b / a);		
		}
		else
		{
			cout << "did not recognize operator\n";
		}
	}
}
