#ifndef DMV_H
#define DMV_H
#include <vector>
#include <ctime>

namespace dmv
{
	struct QueueNode
	{
		long timestamp;
		int ticket;
		QueueNode* link;
	};
	
	typedef QueueNode* QueueNodePtr;
	
	class DMVQueue
	{
	public:
		DMVQueue();
		//Initializes object to an empty queue
		DMVQueue(const DMVQueue& copy);
		//copy contructor
		~DMVQueue();
		
		int add();
		//adds the item to the back of the queue
		
		int remove();
		//precondition: the queue is not empty
		//removes and returns the item at the front
		
		bool empty() const;
		//returns true if the queue is empty
		
		int check_wait();
		
	private:
		int get_ticket();
		
		QueueNodePtr front;
		QueueNodePtr back;
		int max_ticket;
		std::vector<int> wait;
	};
	
	long get_timestamp();
}

#endif
