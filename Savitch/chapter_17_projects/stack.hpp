#ifndef STACK_EXCEP_H
#define STACK_EXCEP_H

namespace eric_stack
{
	class StackOverflowException {};
	class StackEmptyException {};
	
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
		//Initializes an empty stack default size 100
		
		Stack(int the_capacity);
		
		Stack(const Stack& a_stack);
		//copy constructor
		
		~Stack();
		//Destroys the stack and returns all the memory
		
		void push(char the_symbol) throw(StackOverflowException);
		//adds the symbol to the top of the stack
		
		char pop() throw(StackEmptyException);
		//removes and returns the top symbol of the stack
		
		bool empty() const;
		//returns true if the stack is empty
	private:
		int capacity;
		int size;
		StackFramePtr top;
	};
}//eric_stack

#endif //STACK_EXCEP_H
