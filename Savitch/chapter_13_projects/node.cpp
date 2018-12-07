#include <node.hpp>
#include <iostream>
#include <cstddef>

namespace linked_list_of_clases
{
	Node::Node() : data(0), link(NULL)
	{
		//empty
	}
	
	Node::Node(int value, Node *next) : data(value), link(next)
	{
		//empty
	}
	
	//Accessor and Mutator methods follow
	
	int Node::getData() const
	{
		return data;
	}
	
	Node* Node::getLink() const
	{
		return link;
	}
	
	void Node::setData(int value)
	{
		data = value;
	}
	
	void Node::setLink(Node *next)
	{
		link = next;
	}
}//linked_list_of_classes

