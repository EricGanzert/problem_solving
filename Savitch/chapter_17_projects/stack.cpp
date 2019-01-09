#include <stack.h>
#include <iostream>
#include <cstddef>
using namespace std;

namespace eric_stack
{
	template<class T>
	Stack<T>::Stack() : capacity(100), size(0), top(NULL)
	{
		//empty
	}
	
	template<class T>
	Stack<T>::Stack(int the_size) : capacity(the_size), size(0), top(NULL)
	{
		//empty
	}
	
	template<class T>
	Stack<T>::Stack(const Stack<T>& copy) : capacity(copy.capacity), size(copy.size)
	{
		if (copy.empty())
		{
			this->top = NULL;
			return;
		}
		else
		{
			//for going through the stack to copy, top to bottom
			StackFramePtr<T> iter = copy.top;
			//for building the new stack 
			StackFramePtr<T> tmp = new StackFrame<T>;
			tmp->data = iter->data;
			tmp->link = NULL;
			this->top = tmp;
			iter = iter->link;
			
			while (iter != NULL)
			{
				tmp->link = new StackFrame<T>;
				tmp = tmp->link;
				//make tmp a copy of iter
				tmp->data = iter->data;
				tmp->link = NULL; //this will get overwritten next loop
				//advance iter
				iter = iter->link;
			}
		}
	}
	
	template<class T>
	Stack<T>::~Stack()
	{
		while (!empty())
		{
			pop();
		} 
	}
	
	template<class T>
	bool Stack<T>::empty() const
	{
		return (top == NULL);
	}
	
	template<class T>
	void Stack<T>::push(T the_symbol) throw(StackOverflowException)
	{
		if (size >= capacity)
		{
			throw StackOverflowException();
		}
		StackFramePtr<T> temp = new StackFrame<T>;
		temp->data = the_symbol;
		temp->link = top;
		top = temp;
		size++;
	}
	
	template<class T>
	T Stack<T>::pop()  throw(StackEmptyException)
	{
		if (empty())
		{
			throw StackEmptyException();
		}
		else
		{
			T result = top->data;
			StackFramePtr<T> temp = top;
			top = top->link;
			delete temp;
			return result;
		}
	}
} //eric_stack
