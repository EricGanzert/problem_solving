#include <predatorPrey.hpp>
#include <iostream>
#include <stdlib.h>
using namespace std;

namespace predator_prey
{
	void swap(GameBoard* a, GameBoard* b)
	{
		Organism*** temp = a->array;
		a->array = b->array;
		b->array = temp;
	}
	
	Organism::Organism() : x(0), y(0), time_alive(0)
	{
		//empty
	}
	
	Organism::Organism(GameBoard* the_board, int the_x, int the_y) : board(the_board), x(the_x), y(the_y), time_alive(0)
	{
		//empty
	}
	
	Organism::Organism(const Organism& copy) : board(copy.board), x(copy.x), y(copy.y),
		time_alive(copy.time_alive)
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
		std::cout << "Error: Organism base class move\n";
		exit(1);
	}
	
	void Organism::breed()
	{
		std::cout << "Error: Organism base class breed\n";
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
		int i, j;
		if (board->find_empty_adjacent(this,i,j))
		{
			board->array[i][j] = this;
			board->array[x][y] = NULL; 
			x = i;
			y = j;
		}		 
	}
	
	void Ant::breed()
	{
		int i, j;
		if (board->find_empty_adjacent(this,i,j))
		{
			board->array[i][j] = new DoodleBug(board, i, j);
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
		int i, j;
		if (board->find_adjacent_ant(this,i,j))
		{
			delete board->array[i][j]; 
			board->array[i][j] = this;
			board->array[x][y] = NULL;
			x = i;
			y = j;
			time_since_eating = 0;
		}
		else
		{
			time_since_eating++;
		}
	}
	
	void DoodleBug::breed()
	{
		int i, j;
		if (board->find_empty_adjacent(this,i,j))
		{
			board->array[i][j] = new DoodleBug(board, i, j);
		}		
	}
	
	GameBoard::GameBoard()
	{
		array = new Organism**[MAX_Y];
		for (int y = 0; y < MAX_Y; y++)
		{
			array[y] = new Organism*[MAX_X];
			for (int x = 0; x < MAX_X; x++)
			{
				array[y][x] = NULL;
			}
		}
		
		srand(time(NULL));	
		int x;
		int y;	
		while (ants.size() < 100)
		{		
			do
			{
				x = rand() % 20;
				y = rand() % 20;
			} while (array[x][y] != NULL);
			
			array[x][y] = new Ant(this, x, y);
			ants.push_back(*dynamic_cast<Ant*>(array[x][y]));
		}
		
		while (doodle_bugs.size() < 5)
		{			
			do
			{
				x = rand() % 20;
				y = rand() % 20;
			} while (array[x][y] != NULL);
			
			array[x][y] = new DoodleBug(this, x, y);
			doodle_bugs.push_back(*dynamic_cast<DoodleBug*>(array[x][y]));
		}
	}
	
	GameBoard::~GameBoard()
	{
		for (int y = 0; y < MAX_Y; y++)
		{
			for (int x = 0; x < MAX_X; x++)
			{
				if (array[y][x] != NULL)
				{
					delete array[y][x];
				}
			}
		}		
	}
	
	GameBoard::GameBoard(const GameBoard& copy)
	{
		array = new Organism**[MAX_Y];
		for (int y = 0; y < MAX_Y; y++)
		{
			array[y] = new Organism*[MAX_X];
			for (int x = 0; x < MAX_X; x++)
			{
				array[y][x] = NULL;
			}
		}
		
		for (vector<Ant>::const_iterator it = copy.ants.begin(); it != copy.ants.end(); it++)
		{
			array[it->x][it->y] = new Ant(*it);
		}
		
		for (vector<DoodleBug>::const_iterator it = copy.doodle_bugs.begin(); it !=copy.doodle_bugs.end(); it++)
		{
			array[it->x][it->y] = new DoodleBug(*it);
		}	
	}
	
	GameBoard& GameBoard::operator =(const GameBoard& right)
	{
		GameBoard build(right);
		swap(this, &build);
		return *this;
	}
	
	void GameBoard::time_step()
	{
		cout << "doodle_bugs size is " << doodle_bugs.size() << "\n";
		for (vector<DoodleBug>::iterator it = doodle_bugs.begin(); it != doodle_bugs.end(); it++)
		{
			cout << "a\n";
			it->move();
			cout << "b\n";
			it->time_alive++;
			if (it->time_since_eating > 2)
			{
				int temp_x = it->x;
				int temp_y = it->y;
				delete array[it->x][it->y];
				array[temp_x][temp_y] = NULL;
				
			}
			else if(it->time_alive % 8 == 0)
			{
				it->breed();
			}
		}
		cout << "here\n";
		for (vector<Ant>::iterator it = ants.begin(); it != ants.end(); it++)
		{
			cout << "c\n";
			it->move();
			cout << "d\n";
			it->time_alive++;
			if(it->time_alive % 3 == 0)
			{
				it->breed();
			}
		}
	}
	
	void GameBoard::display()
	{
		for(int y=0; y<MAX_Y; y++)
		{
			for(int x=0; x<MAX_X; x++)
			{
				if (is_ant(x,y))
				{
					cout << "o";
				}
				else if (is_doodle_bug(x,y))
				{
					cout << "X";
				}
				else
				{
					cout << " ";
				}
			}
			cout << "\n";			
		}
	}
	
	bool GameBoard::is_ant(int x, int y)
	{
		for (vector<Ant>::iterator it = ants.begin(); it != ants.end(); it++)
		{
			if (it->x == x && it->y == y)
			{
				return true;
			}
		}
		return false;
	}

	bool GameBoard::is_doodle_bug(int x, int y)
	{
		for (vector<DoodleBug>::iterator it = doodle_bugs.begin(); it != doodle_bugs.end(); it++)
		{
			if (it->x == x && it->y == y)
			{
				return true;
			}
		}
		return false;
	}
	
	bool GameBoard::find_empty_adjacent(Organism* ref, int& x, int& y)
	{
		bool empty_space = false;
		
		for (int i = ref->x-2; i<ref->x+2; i++)
		{
			for (int j = ref->y-2; j<ref->y+2; j++)
			{
				if (i > 0 && i < MAX_X && j > 0 && j < MAX_Y)
				{
					if (array[i][j])
					{
						empty_space = true;
						break;
					}
				}
			}
		}
		if (!empty_space)
		{
			return false;
		}
		
		srand(time(NULL));	
		while (array[x][y])
		{
			x = ref->x + rand()%5 - 2;
			y = ref->y + rand()%5 - 2;
		}
		return true;
	}
	
	bool GameBoard::find_adjacent_ant(Organism* ref, int& x, int& y)
	{
		bool ant_adjacent = false;
		
		for (int i = ref->x-2; i<ref->x+2; i++)
		{
			for (int j = ref->y-2; j<ref->y+2; j++)
			{
				if (i > 0 && i < MAX_X && j > 0 && j < MAX_Y)
				{
					if (is_ant(i, j))
					{
						ant_adjacent = true;
					}
				}
			}
		}
		
		if (!ant_adjacent)
		{
			return false;
		}
		
		srand(time(NULL));	
		do
		{
			x = ref->x + rand()%5 - 2;
			y = ref->y + rand()%5 - 2;
		} while (!is_ant(x, y));
		return true;	
	}
}
