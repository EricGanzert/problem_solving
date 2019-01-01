#ifndef QUEUE_STRING_H
#define QUEUE_STRING_H
#include <iostream>

namespace eric_queue_int
{
	struct QueueNode
	{
		int data;
		QueueNode* link;
	};
	
	typedef QueueNode* QueueNodePtr;
	
	class Queue
	{
	public:
		Queue();
		//Initializes object to an empty queue
		Queue(const Queue& copy);
		//copy contructor
		~Queue();
		
		void add(int item);
		//adds the item to the back of the queue
		
		int remove();
		//precondition: the queue is not empty
		//removes and returns the item at the front
		
		bool empty() const;
		//returns true if the queue is empty
		
		friend std::ostream& operator <<(std::ostream& outs, const Queue& right);
	private:
		int remove_internal(QueueNodePtr highest_priority);
		
		QueueNodePtr front;
		QueueNodePtr back;
	};
}

#endif //QUEUE_H
