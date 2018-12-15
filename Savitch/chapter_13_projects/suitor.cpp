#include <suitor.hpp>
#include <iostream>

using namespace eric_single_linked_list;

SuitorSelect::SuitorSelect(int num_suitors) : n(num_suitors)
{
	if (n < 1)
	{
		std::cout << "Error, invalid number of suitors: " << n << "\n";
		exit(1);
	}
	
	int suitor_id = 1;
	head = new Node;
	head->data = suitor_id;
	suitor_id++;
	NodePtr temp = head;
	
	while (suitor_id <= n)
	{
		temp->link = new Node;
		temp = temp->link;
		temp->data = suitor_id;
		suitor_id++;
	}
	temp->link = head;
}

SuitorSelect::SuitorSelect(const SuitorSelect& copy) : n(copy.n)
{
	if (n < 1)
	{
		std::cout << "Error, invalid number of suitors: " << n << "\n";
		exit(1);
	}
	
	head = new Node;
	NodePtr iter = copy.head;
	NodePtr temp = head;
	temp->data = iter->data;
	iter = iter->link;
	
	while (iter != copy.head)
	{
		temp->link = new Node;
		temp = temp->link;
		temp->data = iter->data;
		iter = iter->link;
	}
	temp->link = head;
}

SuitorSelect::~SuitorSelect()
{
	NodePtr temp = head;
	temp = temp->link;
	head->link = NULL;
	while (temp != NULL)
	{
		NodePtr remove = temp;
		temp = temp->link;
		delete remove;
	}
}

int SuitorSelect::select()
{
	NodePtr iter = head;
	while (n > 1)
	{
		iter = iter->link;
		iter = iter->link;
		remove(iter);
	}
	std::cout << "The chosen suitor is " << head->data << "\n";
	return head->data;
}

void SuitorSelect::remove(NodePtr& node)
{
	if (n <= 1)
	{
		std::cout << "Error, removing would make list empty\n";
		exit(1);
	}
	//get a pointer to the node before the one to delete
	NodePtr before = node;
	
	while (before->link != node)
	{
		before = before->link;
	}
	
	//get a pointer to the node after the one to delete
	NodePtr after = node->link;
	if (node == head)
	{
		head = after;
	}
	std::cout << "removing " << node->data << " from list " << *this << "\n";		
	delete node;
	n--;
	before->link = after;
	node = after;
}

std::ostream& operator <<(std::ostream& outs, const SuitorSelect& the_object)
{
	NodePtr iter = the_object.head;
	do 
	{
		outs << iter->data << " ";
		iter = iter->link;
	} while (iter != the_object.head);
	return outs;
}
