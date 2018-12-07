#ifndef QUEUE_H
#define QUEUE_H

namespace eric_queue
{
	struct QueueNode
	{
		char data;
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
		
		void add(char item);
		//adds the item to the back of the queue
		
		char remove();
		//precondition: the queue is not empty
		//removes and returns the item at the front
		
		bool empty() const;
		//returns true if the queue is empty
	private:
		QueueNodePtr front;
		QueueNodePtr back;
	};
}

#endif //QUEUE_H
