#include <graph.hpp>
#include <cstddef>
#include <iostream>

namespace graph_eric
{
	using namespace std;
	
	bool initialized = false;

	GraphNodePtr start = NULL;
	GraphNodePtr finish = NULL;

	void init_graph()
	{
		start = new GraphNode;
		GraphNodePtr temp = start;
		GraphNodePtr back_link;
		
		temp->id = 'A';
		temp->north = NULL;
		temp->west = NULL;
		temp->south = new GraphNode;
		back_link = temp;
		
		temp = temp->south;
		temp->north = back_link;
		temp->id = 'E';
		temp->east = NULL;
		temp->west = NULL;
		temp->south = new GraphNode;
		back_link = temp;
		
		temp = temp->south;
		temp->north = back_link;
		temp->id = 'I';
		temp->west = NULL;
		temp->south = NULL;
		temp->east = new GraphNode;
		back_link = temp;
		
		temp = temp->east;
		temp->west = back_link;
		temp->id = 'J';
		temp->north = NULL;
		temp->east = NULL;
		temp->south = NULL;
		
		temp = start;
		temp->east = new GraphNode;
		back_link = temp;
		
		temp = temp->east;
		temp->west = back_link;
		temp->id = 'B';
		temp->north = NULL;
		temp->east = NULL;
		temp->south = new GraphNode;
		back_link = temp;
		
		temp = temp->south;
		temp->north = back_link;
		temp->id = 'F';
		temp->west = NULL;
		temp->south = NULL;
		temp->east = new GraphNode;
		back_link = temp;
		
		temp = temp->east;
		temp->west = back_link;
		temp->id = 'G';
		temp->north = new GraphNode;
		back_link = temp;
		
		temp = temp->north;
		temp->south = back_link;
		temp->id = 'C';
		temp->west = NULL;
		temp->north = NULL;
		temp->east = new GraphNode;
		back_link = temp;
		
		temp = temp->east;
		temp->west = back_link;
		temp->id = 'D';
		temp->north = NULL;
		temp->east = NULL;
		temp->south = NULL;
		
		temp = temp->west;
		temp = temp->south;
		temp->south = new GraphNode;
		back_link = temp;
		
		temp = temp->south;
		temp->north = back_link;
		temp->id = 'K';
		temp->west = NULL;
		temp->south = NULL;
		temp->east = NULL;
		
		temp = temp->north;
		temp->east = new GraphNode;
		back_link = temp;
		
		temp = temp->east;
		temp->west = back_link;
		temp->id = 'H';
		temp->north = NULL;
		temp->east = NULL;
		temp->south = new GraphNode;
		back_link = temp;
		
		temp = temp->south;
		temp->north = back_link;
		temp->id = 'L';
		temp->west = NULL;
		temp->south = NULL;
		temp->east = NULL;
		finish = temp;
		
		initialized = true;
	}

	void enter_maze()
	{
		if (!initialized)
			init_graph();
			
		GraphNodePtr temp = start;
		
		while(1)
		{
			if (temp == finish)
			{
				cout << "You reached the finish of the maze!\n";
				break;
			}
			bool go_north = false;
			bool go_west = false;
			bool go_east = false;
			bool go_south = false;
			
			cout << "You are in room " << temp->id << " of a maze of twisty little passages, all alike."
				<< "\nYou can go ";
				if (temp->north)
				{
					go_north = true;
					cout << "(N)orth, ";
				}
				if (temp->west)
				{
					go_west = true;
					cout << "(W)est, ";
				}
				if (temp->east)
				{
					go_east = true;
					cout << "(E)ast, ";
				}
				if (temp->south)
				{
					go_south = true;
					cout << "(S)outh, ";
				}
				cout << "or (Q)uit\n";
				
				char c;
				cin >> c;
				cin.ignore(10000, '\n');
				
				if ((c == 'n' || c == 'N') && go_north)
				{
					temp = temp->north;
				}
				else if ((c == 'w' || c == 'W') && go_west)
				{
					temp = temp->west;
				}
				else if ((c == 'e' || c == 'E') && go_east)
				{
					temp = temp->east;
				}
				else if ((c == 's' || c == 'S') && go_south)
				{
					temp = temp->south;
				}
				else if (c == 'q' || c == 'Q')
				{
					break;
				}
		}
	}
}// graph_eric



