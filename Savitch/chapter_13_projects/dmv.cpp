#include <dmv.hpp>
#include <iostream>
#include <cstddef>
using namespace std;

namespace dmv
{
	DMVQueue::DMVQueue() : front(NULL), back(NULL), max_ticket(1)
	{
		//empty
	}
	
	DMVQueue::DMVQueue(const DMVQueue& copy)
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
			tmp->ticket = iter->ticket;
			tmp->timestamp = iter->timestamp;
			tmp->link = NULL;
			this->front = tmp;
			iter = iter->link;
			
			while (iter != NULL)
			{
				tmp->link = new QueueNode;
				tmp = tmp->link;
				//make tmp a copy of iter
				tmp->ticket = iter->ticket;
				tmp->timestamp = iter->timestamp;
				tmp->link = NULL; //this will get overwritten next loop
				//advance iter
				iter = iter->link;
			}
			this->back = tmp;
		}
	}
	
	DMVQueue::~DMVQueue()
	{
		while (!empty())
		{
			remove();
		}
	}
	
	bool DMVQueue::empty() const
	{
		return (front == NULL);
	}
	
	int DMVQueue::get_ticket()
	{
		int current_ticket = max_ticket;
		max_ticket++;
		return current_ticket;
	}
	
	int DMVQueue::add()
	{
		int ticket_num;
		if (empty())
		{
			front = new QueueNode;
			ticket_num = get_ticket();
			front->ticket = ticket_num;
			front->timestamp = get_timestamp();
			front->link = NULL;
			back = front;
			return ticket_num;
		}
		else
		{
			//make the new node
			QueueNodePtr temp;
			temp = new QueueNode;
			ticket_num = get_ticket();
			temp->ticket = ticket_num; 
			temp->timestamp = get_timestamp();
			temp->link = NULL;
			
			//make the current back point to it
			back->link = temp;
			
			//move back pointer
			back = temp;
			return ticket_num;
		}
	}
	
	int DMVQueue::check_wait()
	{
		if (wait.empty())
		{
			return 0;
		}
		else
		{
			int avg = 0;
			for (vector<int>::iterator it = wait.begin(); it != wait.end(); ++it)
			{
				avg += *it;
			}
			avg = avg/wait.size();
			return avg;			
		}
		
	}
	
	int DMVQueue::remove()
	{
		int result;
		if (empty())
		{
			cout << "Error, tyring to remove from an empty queue\n";
			exit(1);
		}
		result = front->ticket;
		
		QueueNodePtr discard = front;
		front = front->link;
		
		if (front == NULL) //deleted the last node
		{
			back = NULL;
		}
		
		//add to the wait times
		long elapsed = static_cast<int>(get_timestamp() - discard->timestamp);
		
		wait.push_back(elapsed);
		
		if (wait.size() > 3)
		{
			wait.erase(wait.begin());
		}
		
		return result;
	}
	
	long get_timestamp()
	{
		return static_cast<long>(time(NULL));
	}
	
}//dmv
