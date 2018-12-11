#include <list.hpp>
#include <cstddef>

namespace
{
	void select_lowest(eric_single_linked_list::NodePtr& ref,
		eric_single_linked_list::NodePtr& first,
		eric_single_linked_list::NodePtr& second)
	{
		if (first != NULL && second != NULL) //they both have nodes remaining
		{
			if (first->data < second->data)
			{
				ref = first;
				first = first->link;
			}
			else
			{
				ref = second;
				second = second->link;
			}
		}
		else if (first != NULL && second == NULL) //only first has nodes remaining
		{
			ref = first;
			first = first->link;
		}
		else if (first == NULL && second != NULL) //only second has nodes remaining
		{
			ref = second;
			second = second->link;
		}
		else
		{
			ref = NULL;
		}
	}
}

namespace eric_single_linked_list
{
	void head_insert(NodePtr& head, int the_number)
	{
		NodePtr temp = new Node;
		temp->data = the_number;
		temp->link = head;
		head = temp;
	}

	NodePtr search(NodePtr head, int target)
	{
		NodePtr here = head;
		
		if (here == NULL)
		{
			return NULL;
		}
		
		while (here->link != NULL && here->data != target)
		{
			here = here->link;
		}
		if (here->data == target)
		{
			return here;
		}
		else
		{
			return NULL;
		}
	}

	void insert(NodePtr after_me, int the_number)
	{
		NodePtr temp = new Node;
		temp->data = the_number;
		temp->link = after_me->link;
		after_me->link = temp;
	}

	void remove(NodePtr remove_next)
	{
		NodePtr temp = remove_next->link;
		remove_next->link = temp->link;
		delete temp;
	}
	
	void reverse_list(NodePtr& head)
	{
		if (head == NULL || head->link == NULL)
		{
			return;
		}
		
		NodePtr a = head;
		NodePtr b = a->link;
		NodePtr c = b;
		a->link = NULL;
		
		while (c->link != NULL)
		{
			c = c->link;
			b->link = a;
			a = b;
			b = c;
		}
		head = c;
		c->link = a;
	}
	
	NodePtr merge_lists(NodePtr& first, NodePtr& second)
	{	
		NodePtr result;
		select_lowest(result, first, second);
		
		NodePtr iter = result;
		
		while (first != NULL || second != NULL)
		{
			select_lowest(iter->link, first, second);
			iter = iter->link;
		}
		
		iter = NULL;
		first = NULL;
		second = NULL;
		return result;
	}
}
