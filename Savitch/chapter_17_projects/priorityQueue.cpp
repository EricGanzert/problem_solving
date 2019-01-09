#ifndef PRIORITY_QUEUE_CPP
#define PRIORITY_QUEUE_CPP

#include <priorityQueue.h>
#include <iostream>
#include <cstddef>
using namespace std;

namespace eric_priority_queue
{
	template<class T>
	Queue<T>::Queue() : front(NULL), back(NULL)
	{
		//empty
	}
	
	template<class T>
	Queue<T>::Queue(const Queue& copy)
	{
		if (copy.empty())
		{
			this->front = NULL;
			this->back = NULL;
			return;
		}
		else
		{
			//for going through the stack to copy, top to bottom
			QueueNodePtr<T> iter = copy.front;
			//for building the new stack 
			QueueNodePtr<T> tmp = new QueueNode<T>;
			tmp->data = iter->data;
			tmp->priority = iter->priority;
			tmp->link = NULL;
			
			this->front = tmp;
			iter = iter->link;
			
			while (iter != NULL)
			{
				tmp->link = new QueueNode<T>;
				tmp = tmp->link;
				//make tmp a copy of iter
				tmp->data = iter->data;
				tmp->priority = iter->priority;
				tmp->link = NULL; //this will get overwritten next loop
				//advance iter
				iter = iter->link;
			}
			this->back = tmp;
		}
	}
	
	template<class T>
	Queue<T>::~Queue()
	{
		while (!empty())
		{
			remove();
		}
	}
	
	template<class T>
	bool Queue<T>::empty() const
	{
		return (front == NULL);
	}
	
	template<class T>
	void Queue<T>::add(T item, int prio)
	{
		if (empty())
		{
			front = new QueueNode<T>;
			front->data = item;
			front->priority = prio;
			front->link = NULL;
			back = front;
		}
		else
		{
			//make the new node
			QueueNodePtr<T> temp;
			temp = new QueueNode<T>;
			temp->data = item;
			temp->priority = prio;
			temp->link = NULL;
			
			//make the current back point to it
			back->link = temp;
			
			//move back pointer
			back = temp;
		}
	}
	
	template<class T>
	T Queue<T>::remove()
	{
		if (empty())
		{
			cout << "Error, tyring to remove from an empty queue\n";
			exit(1);
		}
		else
		{
			//identify the lowest number in the queue
			QueueNodePtr<T> iter = front;
			QueueNodePtr<T> highest_priority = front;
			
			while (iter != NULL)
			{
				if (iter->priority < highest_priority->priority)
				{
					highest_priority = iter;
				}
				iter = iter->link;
			}
			return remove_internal(highest_priority);
		}
	}
	
	template<class T>
	T Queue<T>::remove_internal(QueueNodePtr<T> highest_priority)
	{
		int result;
		
		QueueNodePtr<T> discard = front;
		if (highest_priority == front)
		{
			result = front->data;
			front = front->link;
			delete discard;
			return result;	
		}
		
		//get a pointer to the node preceeding the target
		QueueNodePtr<T> iter = front;
		while (iter->link != NULL)
		{
			if (iter->link == highest_priority)
			{
				discard = iter->link;
				result = discard->data;
				iter->link = discard->link;
				break;
			}
			iter = iter->link;
		}
		
		if (front == NULL) //deleted the last node
		{
			back = NULL;
		}
			
		delete discard;
		return result;		
	}
	
	template<class T>
	ostream& operator <<(ostream& outs, const Queue<T>& right)
	{
		Queue<T> temp(right);
		while (!temp.empty())
		{
			outs << temp.remove() << "\n";
		}
		return outs;
	}
	
}//eric_priority_queue

#endif //PRIORITY_QUEUE_CPP
