#ifndef STACK_STRING_H
#define STACK_STRING_H
#include <iostream>
#include <string>

namespace eric_stack_string
{
	struct StackFrame
	{
		std::string data;
		StackFrame *link;
	};
	typedef StackFrame* StackFramePtr;
	
	class Stack
	{
	public:
		Stack();
		//Initializes an empty stack
		Stack(const Stack& a_stack);
		//copy constructor
		
		~Stack();
		//Destroys the stack and returns all the memory
		
		void push(std::string the_string);
		//adds the string to the top of the stack
		
		std::string pop();
		//removes and returns the top symbol of the stack
		
		bool empty() const;
		//returns true if the stack is empty
		
		friend std::ostream& operator <<(std::ostream& outs, const Stack& right);
		//outputs the items in the stack one line per item
		
	private:
		StackFramePtr top;
	};
}//eric_stack_string

#endif //STACK_STRING_H
