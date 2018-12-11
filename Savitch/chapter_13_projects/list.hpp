#ifndef LIST_H
#define LIST_H

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
