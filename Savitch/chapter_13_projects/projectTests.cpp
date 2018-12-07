#include <projectTests.hpp>
#include <iostream>

using namespace std;
using namespace linked_list_of_clases;
using namespace eric_stack;
using namespace eric_queue;

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

