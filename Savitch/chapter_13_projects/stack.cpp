#include <stack.hpp>
#include <iostream>
#include <cstddef>
using namespace std;

namespace eric_stack
{
	Stack::Stack() : top(NULL)
	{
		//empty
	}
	
	Stack::Stack(const Stack& copy)
	{
		if (copy.empty())
		{
			this->top = NULL;
			return;
		}
		else
		{
			//for going through the stack to copy, top to bottom
			StackFramePtr iter = copy.top;
			//for building the new stack 
			StackFramePtr tmp = new StackFrame;
			tmp->data = iter->data;
			tmp->link = NULL;
			this->top = tmp;
			iter = iter->link;
			
			while (iter != NULL)
			{
				tmp->link = new StackFrame;
				tmp = tmp->link;
				//make tmp a copy of iter
				tmp->data = iter->data;
				tmp->link = NULL; //this will get overwritten next loop
				//advance iter
				iter = iter->link;
			}
		}
	}
	
	Stack::~Stack()
	{
		while (!empty())
		{
			pop();
		} 
	}
	
	bool Stack::empty() const
	{
		return (top == NULL);
	}
	
	void Stack::push(char the_symbol)
	{
		StackFramePtr temp = new StackFrame;
		temp->data = the_symbol;
		temp->link = top;
		top = temp;
	}
	
	char Stack::pop()
	{
		if (empty())
		{
			cout << "Error: attempt to pop an empty stack\n";
			exit(1);
		}
		else
		{
			char result = top->data;
			StackFramePtr temp = top;
			top = top->link;
			delete temp;
			return result;
		}
	}
} //eric_stack
