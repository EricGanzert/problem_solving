#ifndef GUESSING_GAME_H
#define GUESSING_GAME_H
#include <string>

namespace guessing_game
{
	typedef enum
	{
		CORRECT,
		TOO_HIGH,
		TOO_LOW,
	}guess_evaluation_t;
	
	void init();
	
	class Player
	{
	public:
		Player(std::string name);
		virtual int getGuess();
		
		std::string get_name();
		void update_history(int guess, guess_evaluation_t result);
		void reset();
		void win();
		int get_wins();
		
	protected:
		std::string name;
		int highest_low_guess;
		int lowest_high_guess;
		int wins;
	};
	
	class HumanPlayer : public Player
	{
	public:
		HumanPlayer(std::string name);
		virtual int getGuess();
	};

	class ComputerPlayer : public Player
	{
	public:
		ComputerPlayer(std::string name);
		virtual int getGuess();
	};
	
	bool checkForWin(int guess, int answer, guess_evaluation_t& result);
	
	void play(Player &player1, Player &player2);
}

#endif //GUESSING_GAME_H
