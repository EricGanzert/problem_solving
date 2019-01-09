#ifndef QUEUE_STRING_H
#define QUEUE_STRING_H
#include <iostream>

namespace eric_priority_queue
{
	template<typename T>
	struct QueueNode
	{
		T data;
		int priority;
		QueueNode* link;
	};
	
	template<typename T>
	using QueueNodePtr = QueueNode<T>*;
	
	template<class T>
	class Queue
	{
	public:
		Queue();
		//Initializes object to an empty queue
		Queue(const Queue& copy);
		//copy contructor
		~Queue();
		
		void add(T item, int prio);
		//adds the item to the back of the queue
		
		T remove();
		//precondition: the queue is not empty
		//removes and returns the item at the front
		
		bool empty() const;
		//returns true if the queue is empty
		
		template<class U>
		friend std::ostream& operator <<(std::ostream& outs, const Queue<U>& right);
	private:
		T remove_internal(QueueNodePtr<T> highest_priority);
		
		QueueNodePtr<T> front;
		QueueNodePtr<T> back;
	};
}

#endif //QUEUE_H
