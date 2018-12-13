#ifndef LIST_H
#define LIST_H

#include <iostream>

namespace eric_single_linked_list
{
	struct Node
	{
		int data;
		Node* link;
	};

	typedef Node* NodePtr;

	void head_insert(NodePtr& head, int the_number);

	NodePtr search(NodePtr head, int target);

	void insert(NodePtr after_me, int the_number);

	void remove(NodePtr remove_next);	
	
	void reverse_list(NodePtr& head);
	//precondition: head points to the head of a linked list of nodes
	//postcondition: head points to the head of the list reversed
	
	NodePtr merge_lists(NodePtr& first, NodePtr& second);
	//precondition: both pointers are to linked lists sorted
	//in order from smallest to largest
	//postcondition: returns a pointer to the head of a list 
	//that has all the elements from the 2 arg lists sorted from
	//smallest to largest
	
	const int MAX_LIST_SIZE = 50;
	struct ListNode
	{
		double data;
		ListNode* link;
	};
	typedef ListNode* ListNodePtr;
	
	class List
	{
	public:
		List();
		void add_item(double new_item);
		//adds this item to the back of the list
		//if the list is full thats an error
		
		bool full() const;
		//returns true if the size of the list is at the maximum
		//specified by MAX_LIST_SIZE
		
		int get_size() const;
		//returns the number of items in the list
		
		double get_item(int index) const;
		//returns an item of the list by index
		//index starts at 0 for the front of the list
		//and goes to current size - 1
		
		double get_last() const;
		//returns the last item in the list
		//if the list is empty thats an error
		
		void delete_last();
		//deletes the last item of the list
		//if the list is empty this function does nothing
		
		double get_front() const;
		//returns the front item of the list
		//if the list is empty thats an error
		
		double get_current() const;
		//returns the data of the current pointer
		
		void advance();
		//increments the current pointer
		
		void reset();
		//sets the current pointer to the front of the list
		
		void insert(double after_me, double insert_me);
		//inserts a new member into the list after the value specified
		//if the value is not in the list or the list is full thats an error
		
		friend std::ostream& operator <<(std::ostream& outs,
			const List& the_object);
		//outputs the list one item per line

	private:
		ListNodePtr front;
		ListNodePtr current;
		ListNodePtr last;
		int size;
	};
}

namespace eric_double_linked_list
{
	struct Node
	{
		int data;
		Node *next;
		Node *prev;
	};
	typedef Node* NodePtr;
}

namespace eric_tree
{
	struct Node
	{
		int data;
		Node *left;
		Node *right;
	};
	typedef Node* NodePtr;
}

#endif //LIST_H
