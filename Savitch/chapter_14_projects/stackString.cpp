#include <stackString.hpp>
#include <iostream>
#include <cstddef>
using namespace std;

namespace eric_stack_string
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
	
	void Stack::push(string the_string)
	{
		StackFramePtr temp = new StackFrame;
		temp->data = the_string;
		temp->link = top;
		top = temp;
	}
	
	string Stack::pop()
	{
		if (empty())
		{
			cout << "Error: attempt to pop an empty stack\n";
			exit(1);
		}
		else
		{
			string result = top->data;
			StackFramePtr temp = top;
			top = top->link;
			delete temp;
			return result;
		}
	}
	
	ostream& operator <<(ostream& outs, const Stack& right)
	{
		Stack temp = right;
		while (!temp.empty())
		{
			outs << temp.pop() << "\n";
		}
		return outs;
	}
	
	int Stack::size()
	{
		int result = 0;
		StackFramePtr temp = top;
		
		while(temp != NULL)
		{
			result++;
			temp = temp->link;
		}
		return result;
	}
} //eric_stack_string
