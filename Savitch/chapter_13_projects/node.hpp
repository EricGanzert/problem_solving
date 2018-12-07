#ifndef NODE_H
#define NODE_H

namespace linked_list_of_clases
{
	class Node
	{
	public:
		Node();
		Node(int value, Node* next);
		//constructors to initialize a node
		
		int getData() const;
		//retreive the value for this node
		
		Node* getLink() const;
		//retreive next node in the list
		
		void setData(int value);
		//use to modify the value stored in this node
		
		void setLink(Node *next);
		//use to change what node this points to
		
	private:
		int data;
		Node *link;
	};
	typedef Node* NodePtr;
}

#endif //NODE_H
