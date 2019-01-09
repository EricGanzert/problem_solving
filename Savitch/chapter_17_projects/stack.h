#ifndef STACK_EXCEP_H
#define STACK_EXCEP_H

namespace eric_stack
{
	class StackOverflowException {};
	class StackEmptyException {};
	
	template<typename T>
	struct StackFrame
	{
		T data;
		StackFrame *link;
	};
	
	template<typename T>
	using StackFramePtr = StackFrame<T>*;
	
	template<class T>
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
		
		void push(T the_symbol) throw(StackOverflowException);
		//adds the symbol to the top of the stack
		
		T pop() throw(StackEmptyException);
		//removes and returns the top symbol of the stack
		
		bool empty() const;
		//returns true if the stack is empty
	private:
		int capacity;
		int size;
		StackFramePtr<T> top;
	};
}//eric_stack

#endif //STACK_EXCEP_H
