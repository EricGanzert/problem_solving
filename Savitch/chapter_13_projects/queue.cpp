#include <queue.hpp>
#include <iostream>
#include <cstddef>
using namespace std;

namespace eric_queue
{
	Queue::Queue() : front(NULL), back(NULL)
	{
		//empty
	}
	
	Queue::Queue(const Queue& copy)
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
			QueueNodePtr iter = copy.front;
			//for building the new stack 
			QueueNodePtr tmp = new QueueNode;
			tmp->data = iter->data;
			tmp->link = NULL;
			this->front = tmp;
			iter = iter->link;
			
			while (iter != NULL)
			{
				tmp->link = new QueueNode;
				tmp = tmp->link;
				//make tmp a copy of iter
				tmp->data = iter->data;
				tmp->link = NULL; //this will get overwritten next loop
				//advance iter
				iter = iter->link;
			}
			this->back = tmp;
		}
	}
	
	Queue::~Queue()
	{
		while (!empty())
		{
			remove();
		}
	}
	
	bool Queue::empty() const
	{
		return (front == NULL);
	}
	
	void Queue::add(char item)
	{
		if (empty())
		{
			front = new QueueNode;
			front->data = item;
			front->link = NULL;
			back = front;
		}
		else
		{
			//make the new node
			QueueNodePtr temp;
			temp = new QueueNode;
			temp->data = item;
			temp->link = NULL;
			
			//make the current back point to it
			back->link = temp;
			
			//move back pointer
			back = temp;
		}
	}
	
	char Queue::remove()
	{
		if (empty())
		{
			cout << "Error, tyring to remove from an empty queue\n";
			exit(1);
		}
		else
		{
			char result = front->data;
			
			QueueNodePtr discard = front;
			front = front->link;
			
			if (front == NULL) //deleted the last node
			{
				back = NULL;
			}
				
			delete discard;
			return result;
		}
	}
	
}//eric_queue
