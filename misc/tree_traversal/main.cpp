#include <iostream>
#include <stack>
#include <unordered_set>
using namespace std;

struct Node
{
	int data;
	struct Node* left, *right;
	Node(int data)
	{
		this->data = data;
		left = right = NULL;
	}
};

//Given a binary tree, print its nodes according to the bottom-up postorder traversal
//also useful for deleting a tree
void printPostorder(struct Node* node)
{
	if (node == NULL)
	{
		return;
	}
	
	//first recur on the left sub-tree
	printPostorder(node->left);
	
	//next go through the right side
	printPostorder(node->right);
	
	//visit the current node
	cout << node->data << " ";
}

//Given a binary tree, print its nodes in order
void printInorder(struct Node* node)
{
	if (node == NULL)
	{
		return;
	}
	
	//first the left sub-tree
	printInorder(node->left);
	
	//visit the current node
	cout << node->data << " ";
	
	//right side of the tree
	printInorder(node->right);
}

//Given a binary tree print its nodes in preorder
//useful in copying a tree
void printPreorder(struct Node* node)
{
	if (node == NULL)
	{
		return;
	}
	
	//visit the current node
	cout << node->data << " ";
	
	//go left
	printPreorder(node->left);
	
	//go right
	printPreorder(node->right);
}

// In order traversal with iterative code
//keep going left pushing data on the stack;
//when you get to the end go into a loop popping 
//from the stack then going to the right of the one you popped
//once there continue going left until NULL and repeat

void inOrderIter(struct Node* node)
{
	std::stack<Node*> s;
	Node* current = node;
	
	while(current != NULL || !s.empty())
	{
		while(current != NULL)
		{
			s.push(current);
			current = current->left;
		}
		
		current = s.top();
		s.pop();		
		cout << current->data << " ";
		current = current->right;
	}
}

void postOrderIter(struct Node* head)
{
	struct Node* temp = head;
	unordered_set<Node*> visited;
	while (temp && visited.find(temp) == visited.end())
	{
		//visit left subtree
		if (temp->left && visited.find(temp->left) == visited.end())
		{
			temp = temp->left;
		}
		
		else if (temp->right && visited.find(temp->right) == visited.end())
		{
			temp = temp->right;
		}
		
		else
		{
			cout << temp->data << " ";
			visited.insert(temp);
			temp = head;
		}
	}
}

//iterative Preorder traversal
void preOrderIter(struct Node* head)
{
	stack<Node*> s;
	s.push(head);
	while (!s.empty())
	{
		Node* temp = s.top();
		cout << temp->data << " ";
		s.pop();

		if (temp->right)
			s.push(temp->right);		
		if (temp->left)
			s.push(temp->left);
	}
}

int main()
{
	struct Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	
	cout << "\nPreorder traversal of binary tree is \n";
	printPreorder(root);
	
	cout << "\nIterative Preorder traversal of binary tree is \n";
	preOrderIter(root);

	cout << "\nInorder traversal of binary tree is \n";
	printInorder(root);
	
	cout << "\nIterative Inorder traversal of binary tree is \n";
	inOrderIter(root);
	
	cout << "\nPostorder traversal of binary tree is \n";
	printPostorder(root);
	
	cout << "\nIterative Postorder traversal of binary tree is \n";
	postOrderIter(root);
	
	cout << "\n";
	
	return 0;
}
