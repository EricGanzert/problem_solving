#ifndef PREDATOR_PREY_H
#define PREDATOR_PREY_H
#include <vector>

namespace predator_prey
{
	const int MAX_X = 20;
	const int MAX_Y = 20;
	
	class GameBoard;
	
	class Organism
	{
	public:
		Organism();
		Organism(GameBoard* the_board, int the_x, int the_y);
		Organism(const Organism& copy);
		virtual ~Organism();
		Organism& operator =(const Organism& right);
		
		virtual void move();
		virtual void breed();
		
		friend class GameBoard;
		
	protected:
		GameBoard* board;
		int x;
		int y;
		int time_alive;
	};
	
	class Ant : public Organism
	{
	public:
		Ant();
		Ant(GameBoard* the_board, int the_x, int the_y);
		Ant(const Ant& copy);
		virtual ~Ant();
		Ant& operator =(const Organism& right);
		
		virtual void move();
		virtual void breed();
		friend class GameBoard;
	};
	
	class DoodleBug : public Organism
	{
	public:
		DoodleBug();
		DoodleBug(GameBoard* the_board, int the_x, int the_y);
		DoodleBug(const DoodleBug& copy);
		virtual ~DoodleBug();
		DoodleBug& operator =(const DoodleBug& right);
		
		virtual void move();
		virtual void breed();
		friend class GameBoard;
	private:
		int time_since_eating;
	};
	
	class GameBoard
	{
	public:
		GameBoard();
		GameBoard(const GameBoard& copy);
		GameBoard& operator =(const GameBoard& right);
		virtual ~GameBoard();
		void time_step();
		void display();
		
		friend void swap(GameBoard* a, GameBoard* b);
		friend class Ant;
		friend class DoodleBug;
	private:
		bool is_ant(int x, int y);
		bool is_doodle_bug(int x, int y);
		bool find_empty_adjacent(Organism* ref, int& x, int& y);
		bool find_adjacent_ant(Organism* ref, int& x, int& y);
		
		Organism*** array;
		std::vector<Ant> ants;
		std::vector<DoodleBug> doodle_bugs;
	};
}

#endif //PREDATOR_PREY_H
