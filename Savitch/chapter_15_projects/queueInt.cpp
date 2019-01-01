#include <queueInt.hpp>
#include <iostream>
#include <cstddef>
using namespace std;

namespace eric_queue_int
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
	
	void Queue::add(int item)
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
	
	int Queue::remove()
	{
		if (empty())
		{
			cout << "Error, tyring to remove from an empty queue\n";
			exit(1);
		}
		else
		{
			//identify the lowest number in the queue
			QueueNodePtr iter = front;
			QueueNodePtr highest_priority = front;
			
			while (iter != NULL)
			{
				if (iter->data < highest_priority->data)
				{
					highest_priority = iter;
				}
				iter = iter->link;
			}
			return remove_internal(highest_priority);
		}
	}
	
	int Queue::remove_internal(QueueNodePtr highest_priority)
	{
		int result;
		
		QueueNodePtr discard = front;
		if (highest_priority == front)
		{
			result = front->data;
			front = front->link;
			delete discard;
			return result;	
		}
		
		//get a pointer to the node preceeding the target
		QueueNodePtr iter = front;
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
	
	ostream& operator <<(ostream& outs, const Queue& right)
	{
		Queue temp(right);
		while (!temp.empty())
		{
			outs << temp.remove() << "\n";
		}
		return outs;
	}
	
}//eric_queue_int
