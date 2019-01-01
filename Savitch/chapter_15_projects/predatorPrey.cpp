#include <predatorPrey.hpp>
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

namespace
{
	using namespace predator_prey;
	bool x_in_range(int x)
	{
		return (x >=0 && x < MAX_X);
	}
	
	bool y_in_range(int y)
	{
		return (y >=0 && y < MAX_Y);
	}
}

namespace predator_prey
{
	Organism::Organism() : board(NULL), x(0), y(0), time_alive(0)
	{
		cout << "organism default constructor why?\n";
	}
	
	Organism::Organism(GameBoard* the_board, int the_x, int the_y) : board(the_board), x(the_x), y(the_y), time_alive(0)
	{
		//empty
	}
	
	Organism::Organism(const Organism& copy) : board(copy.board), x(copy.x), y(copy.y), time_alive(copy.time_alive)
	{
		//empty
	}
	
	Organism::~Organism()
	{
		//empty
	}
	
	Organism& Organism::operator =(const Organism& right)
	{
		board = right.board;
		x = right.x;
		y = right.y;
		time_alive = right.time_alive;
		return *this;
	}
	
	void Organism::move()
	{
		cout << "Error: base class move called\n";
		exit(1);
	}
	
	void Organism::breed()
	{
		cout << "Error: base class breed called\n";
		exit(1);			
	}
	
	Ant::Ant() : Organism()
	{
		//empty
	}
	
	Ant::Ant(GameBoard* the_board, int x, int y) : Organism(the_board, x, y)
	{
		//empty
	}
	
	Ant::Ant(const Ant& copy) : Organism(copy)
	{
		//empty
	}
	
	Ant::~Ant()
	{
		//empty
	}
	
	Ant& Ant::operator =(const Organism& right)
	{
		Organism::operator =(right);
		return *this;
	}
		
	void Ant::move()
	{
		int new_x = 0, new_y = 0;
		if (board->find_empty_adjacent(this, new_x, new_y))
		{
			//cout << "found empty adjacent at (" << new_x << ", " << new_y << ")\n";
			board->array[new_x][new_y] = this;
			board->array[x][y] = NULL;
			x = new_x;
			y = new_y;
		}
	}
	
	void Ant::breed()
	{
		int new_x = 0, new_y = 0;
		if (board->find_empty_adjacent(this, new_x, new_y))
		{
			//cout << "found empty adjacent at (" << new_x << ", " << new_y << ")\n";
			board->add_ant(new_x, new_y);
		}		
	}
	
	DoodleBug::DoodleBug() : Organism(), time_since_eating(0)
	{
		//empty
	}
	
	DoodleBug::DoodleBug(GameBoard* the_board, int x, int y) : Organism(the_board, x, y), time_since_eating(0)
	{
		//empty
	}
	
	DoodleBug::DoodleBug(const DoodleBug& copy) : Organism(copy), time_since_eating(copy.time_since_eating)
	{
		//empty
	}
	
	DoodleBug::~DoodleBug()
	{
		//empty
	}
	
	DoodleBug& DoodleBug::operator =(const DoodleBug& right)
	{
		Organism::operator =(right);
		time_since_eating = right.time_since_eating;
		return *this;
	}
		
	void DoodleBug::move()
	{
		//cout << "moving doodlebug at (" << x << ", " << y << ")\n";
		int new_x = 0, new_y = 0;
		if (board->find_adjacent_ant(this, new_x, new_y))
		{
			//cout << "found ant adjacent at (" << new_x << ", " << new_y << ")\n";
			board->erase_organism(board->array[new_x][new_y]);
			
			board->array[new_x][new_y] = this;
			time_since_eating = 0;
			
			board->array[x][y] = NULL;
			x = new_x;
			y = new_y;
		}		
	}
	
	void DoodleBug::breed()
	{
		int new_x = 0, new_y = 0;
		if (board->find_empty_adjacent(this, new_x, new_y))
		{
			//cout << "found empty adjacent at (" << new_x << ", " << new_y << ")\n";
			board->add_doodle_bug(new_x, new_y);
		}
	}
	
	GameBoard::GameBoard()
	{
		array = std::vector<std::vector<Organism*> >(MAX_X, std::vector<Organism*>(MAX_Y));
		for (int x=0; x<MAX_X; x++)
		{
			for (int y=0; y<MAX_Y; y++)
			{
				array[x][y] = NULL;
			}
		}
		srand(time(NULL));
		while(ants.size() < 100)
		{
			int x = rand() % MAX_X;
			int y = rand() % MAX_Y;
			if (!is_ant(x,y) && !is_doodle_bug(x,y))
			{
				add_ant(x,y);
			}
			//cout << "Just added an ant at(x,y) (" << array[x][y]->x << ", " << array[x][y]->y << ")\n";
		}
		
		while(doodle_bugs.size() < 5)
		{
			int x = rand() % MAX_X;
			int y = rand() % MAX_Y;
			if (!is_ant(x,y) && !is_doodle_bug(x,y))
			{
				add_doodle_bug(x,y);
			}
			//cout << "Just added an ant at(x,y) (" << array[x][y]->x << ", " << array[x][y]->y << ")\n";
		}		
	}
	
	GameBoard::~GameBoard()
	{
		array.clear();
	}
	
	void GameBoard::display()
	{
		for (int i=0; i<=MAX_X; i++)
		{
			cout << "_";
		}
		cout << "\n";
		
		for (int y = MAX_Y-1; y >=0; y--)
		{
			cout << "|";
			for (int x = 0; x < MAX_X; x++)
			{
				if (array[x][y] == NULL)
				{
					cout << " ";
				}
				else
				{
					if (is_ant(x, y))
					{
						cout << "o";
					}
					else if (is_doodle_bug(x, y))
					{
						cout << "X";
					}
					else
					{
						cout << "\nError: in display, (" << x << ", " << y 
							<< ") is not NULL, but isn't in ants or bugs vector\n";
 					}
				}
			}
			cout << "|\n";
		}
		for (int i=0; i<=MAX_X; i++)
		{
			cout << "~";
		}
		cout << "\n";
	}
	
	void GameBoard::time_step()
	{	
		for (uint32_t i=0; i<ants.size(); i++)
		{
			Ant* ant = ants[i];
			//cout << "About to move ant at (" << ant->x << ", " << ant->y << "\n";
			ant->move();
			ant->time_alive++;
			if (ant->time_alive > 0 && ant->time_alive % 3 == 0)
			{
				ant->breed();
			}
		}
		
		for (uint32_t i=0; i<doodle_bugs.size(); i++)
		{
			DoodleBug* bug = doodle_bugs[i];
			//cout << "About to move doodle bug at (" << bug->x << ", " << bug->y << "\n";
			bug->move();
			bug->time_alive++;
			bug->time_since_eating++;
			
			if (bug->time_since_eating > 2)
			{
				erase_organism(array[bug->x][bug->y]);
			}
			else if (bug->time_alive > 0 && bug->time_alive % 8 == 0)
			{
				bug->breed();
			}
		}		
	}
	
	bool GameBoard::is_ant(int x, int y)
	{
		if (x_in_range(x) && y_in_range(y))
		{
			for (uint32_t i=0; i<ants.size(); i++)
			{
				Ant* ant = ants[i];
				if (ant->x == x && ant->y == y)
				{
					return true;
				}
			}			
		}
		return false;
	}
	
	bool GameBoard::is_doodle_bug(int x, int y)
	{
		if (x_in_range(x) && y_in_range(y))
		{
			for (uint32_t i=0; i<doodle_bugs.size(); i++)
			{
				DoodleBug* bug = doodle_bugs[i];
				if (bug->x == x && bug->y == y)
				{
					return true;
				}
			}			
		}
		return false;		
	}
	
	void GameBoard::erase_organism(Organism* &remove)
	{
		if (array[remove->x][remove->y] == NULL || (!is_ant(remove->x, remove->y) && !is_doodle_bug(remove->x, remove->y)))
		{
			if (!is_ant(remove->x, remove->y) && !is_doodle_bug(remove->x, remove->y))
			{
				cout << "Error: requested to remove organism at (" << remove->x << ", " << remove->y 
					<< ") but there is no organism at that place\n";				
			}
			if (array[remove->x][remove->y] == NULL)
			{
				cout << "Error: requested to remove organism at (" << remove->x << ", " << remove->y 
					<< ") but that pointer is NULL\n";				
			}
			exit(1);
		}
		else
		{
			//cout << "erasing organism at (" << remove->x << ", " << remove->y << ")\n";
			//remove the pointer to that organism from the record
			if (is_ant(remove->x, remove->y))
			{
				//cout << "its an ant\n";
				for (uint32_t i = 0; i < ants.size(); i++)
				{
					if (ants[i]->x == remove->x && ants[i]->y == remove->y)
					{
						ants.erase(ants.begin() + i);
						break;
					}
				}
			}
			else if (is_doodle_bug(remove->x, remove->y))
			{
				//cout << "its a doodle bug\n";
				for (uint32_t i = 0; i < doodle_bugs.size(); i++)
				{
					if (doodle_bugs[i]->x == remove->x && doodle_bugs[i]->y == remove->y)
					{
						doodle_bugs.erase(doodle_bugs.begin() + i);
						break;
					}
				}				
			}
			
			delete remove;
			remove = NULL;
		}
	}
	
	void GameBoard::add_ant(int x, int y)
	{
		if (is_ant(x,y) || is_doodle_bug(x,y))
		{
			cout << "Error: Add Ant at (" << x << ", " << y << ") but there is ";
			if (is_ant(x,y))
			{
				cout << "an ant";
			}
			else if (is_doodle_bug(x,y))
			{
				cout << "a doodle bug";
			}
			cout << " there\n";
			if (array[x][y] == NULL)
			{
				cout << "However that place is NULL?\n";
			}
			exit(1);
		}
		else if (!x_in_range(x) || !y_in_range(y))
		{
			cout << "Error: Add Ant at (" << x << ", " << y << ") but that is out of bounds\n";
		}
		else
		{
			array[x][y] = new Ant(this,x,y);
			ants.push_back(dynamic_cast<Ant*>(array[x][y]));
		}
	}
	
	void GameBoard::add_doodle_bug(int x, int y)
	{
		if (is_ant(x,y) || is_doodle_bug(x,y))
		{
			cout << "Error: Add Doodle Bug at (" << x << ", " << y << ") but there is ";
			if (is_ant(x,y))
			{
				cout << "an ant";
			}
			else if (is_doodle_bug(x,y))
			{
				cout << "a doodle bug";
			}
			cout << " there\n";
			if (array[x][y] == NULL)
			{
				cout << "However that place is NULL?\n";
			}
			exit(1);
		}
		else if (!x_in_range(x) || !y_in_range(y))
		{
			cout << "Error: Add Doodle Bug at (" << x << ", " << y << ") but that is out of bounds\n";
		}
		else
		{
			array[x][y] = new DoodleBug(this,x,y);
			doodle_bugs.push_back(dynamic_cast<DoodleBug*>(array[x][y]));
		}
	}
	
	bool GameBoard::find_empty_adjacent(Organism* ref, int& new_x, int& new_y)
	{
		//is there an empty space aywhere adjacent?
		bool empty_adjacent = false;
		for (int i=(ref->x-1); i<=(ref->x+1); i++)
		{
			for (int j=(ref->y-1); j<=(ref->y+1); j++)
			{
				if (x_in_range(i) && y_in_range(j) && (i != ref->x || j != ref->y))
				{
					if (array[i][j] == NULL)
					{
						empty_adjacent = true;
						break;
					}
				}
			}
		}
		if (!empty_adjacent)
		{
			//cout << "(" << ref->x << ", " << ref->y << ") has no empty adjacent\n";	
			return false;
		}
		else
		{
			//randomly pick adjacent until we get an empty one
			do
			{
				get_random_adjacent(ref, new_x, new_y);
			} while (array[new_x][new_y] != NULL);
			
			return empty_adjacent;
		}
	}
	
	bool GameBoard::find_adjacent_ant(Organism* ref, int& new_x, int& new_y)
	{
		//is there an ant aywhere adjacent?
		bool ant_adjacent = false;
		for (int i=(ref->x-1); i<=(ref->x+1); i++)
		{
			for (int j=(ref->y-1); j<=(ref->y+1); j++)
			{
				if (x_in_range(i) && y_in_range(j) && (i != ref->x || j != ref->y))
				{
					if (is_ant(i,j))
					{
						ant_adjacent = true;
						break;
					}
				}
			}
		}
		if (!ant_adjacent)
		{
			//cout << "(" << ref->x << ", " << ref->y << ") has no ant adjacent\n";	
			return false;
		}
		else
		{
			//randomly pick adjacent until we get an ant
			do
			{
				get_random_adjacent(ref, new_x, new_y);
			} while (!is_ant(new_x, new_y));
			
			return ant_adjacent;
		}		
	}
	
	void GameBoard::get_random_adjacent(Organism* ref, int& x, int& y)
	{
		//srand(time(NULL));
		if (!x_in_range(ref->x) || !y_in_range(ref->y))
		{
			cout << "get_random_adjacent on out of bounds (" << ref->x << ", " << ref->y << ")\n";
			exit(1);
		}
		do
		{
			x = ref->x + ((rand() % 3) - 1);
			y = ref->y + ((rand() % 3) - 1);
		} while (!x_in_range(x) || !y_in_range(y) || (ref->x == x && ref->y == y));
	}
}
	
