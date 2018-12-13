#include <projectTests.hpp>
#include <iostream>

using namespace std;
using namespace linked_list_of_clases;
using namespace eric_stack;
using namespace eric_queue;

namespace
{
	void output_list(eric_single_linked_list::NodePtr head)
	{
		while(head != NULL)
		{
			cout << head->data << " ";
			head = head->link;
		}
		cout << "\n";
	}
}

void head_insert(NodePtr& head, int the_number)
{
	NodePtr temp = new Node(the_number, head);
	head = temp;
}

void node_class_test()
{
	NodePtr head, tmp;
	head = new Node(0, NULL);
	//Create a list of nodes: 4 -> 3 -> 2 -> 1
	for (int i=1; i < 5; i++)
	{
		head_insert(head, i);
	}
	
	//iterate through the list and display each value
	for (tmp = head; tmp != NULL; tmp = tmp->getLink())
	{
		cout << tmp->getData() << "\n";
	} 
	
	//Delete all nodes before exiting the program
	tmp = head;
	while (tmp->getLink() != NULL)
	{
		NodePtr discard = tmp;
		tmp = tmp->getLink();
		delete discard;
	}
}

void stack_test()
{
	Stack s;
	char next;
	
	cout << "Enter a word: ";
	cin.get(next);
	while (next != '\n')
	{
		s.push(next);
		cin.get(next);
	}
	
	Stack copy(s);
		
	cout << "Written backward that is: ";
	while (!s.empty())
	{
		cout << s.pop();
	}
	
	cout << "\nAnd our copy is: ";
	while (!copy.empty())
	{
		cout << copy.pop();
	}
	cout << "\n";
}

void queue_test()
{
	Queue q;
	char next;
	cout << "Enter a word: ";
	cin.get(next);
	while (next != '\n')
	{
		q.add(next);
		cin.get(next);
	}
	
	Queue copy(q);
	
	cout << "You entered: ";
	while (!q.empty())
	{
		cout << q.remove();
	}
	
	cout << "\nAnd our copy is: ";
	while (!copy.empty())
	{
		cout << copy.remove();
	}
	cout << "\n";
}

void list_reverse_test()
{
	eric_single_linked_list::NodePtr head = NULL;

	eric_single_linked_list::NodePtr iter = head;
	
	for (int i=1; i<10; i++)
	{
		eric_single_linked_list::head_insert(head, i);
	}
	
	iter = head;
	while (iter != NULL)
	{
		cout << iter->data << "\n";
		iter = iter->link;
	}
	
	reverse_list(head);
	
	iter = head;
	while (iter != NULL)
	{
		cout << iter->data << "\n";
		iter = iter->link;
	}	
}

void list_merge_test()
{
	eric_single_linked_list::NodePtr head1, head2;
	head1 = NULL;
	head2 = NULL;
	
	
	for (int i=10; i>0; i--) 
	{
		if (i%2)
			eric_single_linked_list::head_insert(head1, i);
		else
			eric_single_linked_list::head_insert(head2, i);
	}
	
	output_list(head1);
	output_list(head2);
	
	eric_single_linked_list::NodePtr merged;
	merged = merge_lists(head1, head2);
	
	output_list(merged);
}

void polynomial_test()
{
	poly_eric::Polynomial p;
	cout << "Enter polynomial...\nNeeds constant term at the end even if 0\n"
		<< "always use ^ to specify power, unless its a constant term\n";
	cin >> p;
	cout << p << " evaluated at x=2 is " << p.evaluate(2) << "\n";
	
	poly_eric::Polynomial poly1(3, 2);
	poly_eric::Polynomial poly2(2, 1);
	poly_eric::Polynomial poly3(1, 0);
	poly_eric::Polynomial poly4(4, 2);
	
	//cout << poly1 << "\n" << poly2 << "\n" << poly3 << "\n";
	
	poly_eric::Polynomial sum = poly1 + poly2;
	poly_eric::Polynomial sum2 = poly3 + poly1 + poly4 + poly2;
	cout << "(" << sum << ") + (" << sum2 << ") = " << sum + sum2 << "\n";
	
	cout << "(" << sum << ") + (5) = " << sum + 5 << "\n";
	
	cout << "(-5) + (" << sum << ") = " << -5 + sum << "\n";
	
	cout << "(" << sum << ") - (" << sum2 << ") = " << sum - sum2 << "\n";
	
	cout << "(" << sum << ") - (5) = " << sum - 5 << "\n";
	
	cout << "(-5) - (" << sum << ") = " << -5 - sum << "\n";
	
	cout << "(" << sum << ") * (" << sum2 << ") = " << sum * sum2 << "\n";
	
	cout << "(" << sum << ") * (5) = " << sum * 5 << "\n";
	
	cout << "(-5) * (" << sum << ") = " << -5 * sum << "\n";
}

void list_class_test()
{
	eric_single_linked_list::List l;
	
	for (int i=0; i<15; i++)
	{
		l.add_item(i + 0.1);
	}
	cout << l;
	cout << "the size of this list is " << l.get_size() << "\n";
	for (int i=0; i<l.get_size(); i++)
	{
		cout << "the " << i << " index item is " << l.get_item(i) << "\n";
	}
	cout << "the last item is: " << l.get_last() << "\n";
	l.delete_last();
	cout << "Just deleted the last item. Now the size is " << l.get_size() << " and the list is as follows:\n"
		<< l;
		
	//~ while (l.get_size() > 0)
	//~ {
		//~ l.delete_last();
	//~ }
	//~ cout << "Deleted all items. The size is " << l.get_size() << " and the list is as follows:\n"
		//~ << l;
		
	eric_single_linked_list::List one_item;
	one_item.add_item(9.001);
	
	eric_single_linked_list::List empty_list;
	
	cout << "Result of get_last on a one-item list: " << one_item.get_last() << "\n";
	
	l.reset();
	for (int i=0; i<l.get_size(); i++)
	{
		cout << "current is " << l.get_current() << "\n";
		l.advance();
	}
	l.reset();
	l.advance();
	l.advance();
	
	l.insert(l.get_front(), 1.0);
	l.insert(l.get_current(), 3.0);
	l.insert(l.get_last(), 2.0);
	cout << "After some insertions the list is\n"
		<< l;
	
}
