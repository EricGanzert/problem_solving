#ifndef STACK_INT_H
#define STACK_INT_H
#include <iostream>

namespace eric_stack_int
{
	struct StackFrame
	{
		int data;
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
		
		void push(int the_number);
		//adds the symbol to the top of the stack
		
		int pop();
		//removes and returns the top symbol of the stack
		
		bool empty() const;
		//returns true if the stack is empty
		
		friend std::ostream& operator <<(std::ostream& outs, const Stack& right);
		//outputs the items in the stack one line per item
		
	private:
		StackFramePtr top;
	};
}//eric_stack_int

#endif //STACK_INT_H
