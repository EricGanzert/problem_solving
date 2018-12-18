#ifndef QUEUE_STRING_H
#define QUEUE_STRING_H
#include <string>

namespace eric_queue_string
{
	struct QueueNode
	{
		std::string data;
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
		
		void add(std::string item);
		//adds the item to the back of the queue
		
		std::string remove();
		//precondition: the queue is not empty
		//removes and returns the item at the front
		
		bool empty() const;
		//returns true if the queue is empty
		
		friend std::ostream& operator <<(std::ostream& outs, const Queue& right);
	private:
		QueueNodePtr front;
		QueueNodePtr back;
	};
}

#endif //QUEUE_H
