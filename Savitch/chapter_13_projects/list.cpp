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
	
	List::List() : front(NULL), current(NULL), last(NULL), size(0)
	{
		//empty
	}
	
	void List::add_item(double new_item)
	{
		if (full())
		{
			std::cout << "Error: trying to add to a full list\n";
			exit(1);
		}
		else if (front == NULL) // the list is empty
		{
			front = new ListNode;
			front->data = new_item;
			front->link = NULL;
			current = front;
			last = front;
			last->link = NULL;
			size++;
		}
		else
		{
			//get a pointer to the current last item
			last->link = new ListNode;
			last = last->link;
			last->data = new_item;
			last->link = NULL;
			size++;
		}
	}
	
	bool List::full() const
	{
		return (size >= MAX_LIST_SIZE);
	}
	
	int List::get_size() const
	{
		return size;
	}
	
	double List::get_item(int index) const
	{
		if (index >= size || index < 0)
		{
			std::cout << "Error: invalid index\n";
			exit(1);
		}
		ListNodePtr iter = front;
		for (int i = 0; i < index; i++)
		{
			iter = iter->link;
		}
		return iter->data;
	}
	
	double List::get_last() const
	{
		if (front == NULL)
		{
			std::cout << "Error: get last on empty list\n";
			exit(1);
		}
		
		return last->data;
	}
	
	void List::delete_last()
	{
		if (size == 0)
		{
			return;
		}
		else if (size == 1)
		{
			delete front;
			front = NULL;
			last = NULL;
			current = NULL;
			size--;
		}
		else
		{
			ListNodePtr iter = front;
			while (iter->link != last)
			{
				iter = iter->link;
			}
			
			delete last;
			last = iter;
			last->link = NULL;
			size--;				
		}
	}
	
	std::ostream& operator <<(std::ostream& outs,
		const List& the_object)
	{
		ListNodePtr iter = the_object.front;
		while (iter != NULL)
		{
			outs << iter->data << "\n";
			iter = iter->link;
		}
		return outs;
	}
	
	double List::get_front() const
	{
		if (front == NULL)
		{
			std::cout << "Error get_front called on an empty list\n";
			exit(1);
		}
		else
		{
			return front->data;
		}
	}
	
	double List::get_current() const
	{
		if (front == NULL)
		{
			std::cout << "Error, get_current called on empty list\n";
			exit(1);
		}
		else
		{
			return current->data;
		}
	}
	
	void List::advance()
	{
		if (front == NULL)
		{
			std::cout << "Error, can't advance on empty list\n";
			exit(1);			
		}
		else if (current == last)
		{
			return;
		}
		else
		{
			current = current->link;
		}
	}
	
	void List::reset()
	{
		current = front;
	}
	
	void List::insert(double after_me, double insert_me)
	{
		if (front == NULL)
		{
			std::cout << "Error: insert after a value called on an empty list\n";
			exit(1);
		}
		else if (full())
		{
			std::cout << "Error: insert called on a full list\n";
			exit(1);			
		}
		else
		{
			ListNodePtr iter = front;
			while (iter != NULL)
			{
				if (iter->data == after_me)
				{
					break;
				}
				iter = iter->link;
			}
			
			if (iter == NULL)
			{
				std::cout << "Error: could not find item in list to insert after\n";
				exit(1);
			}
			else
			{
				ListNodePtr after = iter->link;
				iter->link = new ListNode;
				iter = iter->link;
				iter->data = insert_me;
				iter->link = after;
				size++;
			}
		}
	}
}
