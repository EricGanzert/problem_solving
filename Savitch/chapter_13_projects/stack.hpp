#ifndef STACK_H
#define STACK_H

namespace eric_stack
{
	struct StackFrame
	{
		char data;
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
		
		void push(char the_symbol);
		//adds the symbol to the top of the stack
		
		char pop();
		//removes and returns the top symbol of the stack
		
		bool empty() const;
		//returns true if the stack is empty
	private:
		StackFramePtr top;
	};
}//eric_stack

#endif //STACK_H
