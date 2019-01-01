#include <guessingGame.hpp>
#include <iostream>
#include <cstdlib>
using namespace std;

namespace guessing_game
{
	int initialized = false;
		
	Player::Player(string the_name) : name(the_name),
		highest_low_guess(0), lowest_high_guess(100), wins(0)
	{
		if (!initialized)
		{
			init();
		}
	}
	
	string Player::get_name()
	{
		return name;
	}
	
	int Player::getGuess()
	{
		return 0;
	}
	
	void Player::win()
	{
		wins++;
	}
	
	int Player::get_wins()
	{
		return wins;
	}
	
	void Player::update_history(int guess, guess_evaluation_t result)
	{
		switch(result)
		{
		case CORRECT:
			cout << "Error game is over\n";
			break;
		case TOO_HIGH:
			if (guess < lowest_high_guess)
			{
				lowest_high_guess = guess;
			}
			break;
		case TOO_LOW:
			if (guess > highest_low_guess)
			{
				highest_low_guess = guess;
			}
			break;
		default:
			cout << "Error game in update history\n";
			exit(1);
		}
	}
	
	void Player::reset()
	{
		highest_low_guess = 0;
		lowest_high_guess = 100;	
	}
	
	HumanPlayer::HumanPlayer(string the_name) : Player(the_name)
	{
		//empty
	}
	
	int HumanPlayer::getGuess()
	{
		int the_guess;
		cout << "enter your guess(0-99): ";
		cin >> the_guess;
		return the_guess;
	}

	ComputerPlayer::ComputerPlayer(string the_name) : Player(the_name)
	{
		//empty
	}
	
	int ComputerPlayer::getGuess()
	{
		//~ cout << "Calculating guess.\nhighest_low_guess is " << highest_low_guess
			//~ << "\nlowest_high_guess is " << lowest_high_guess << "\n";
			
		int new_guess = (highest_low_guess + lowest_high_guess) / 2;
		return new_guess;
	}
	
	void init()
	{
		cout << "Initializing random numbers\n";
		srand(time(NULL));
		initialized = true;
	}
	
	bool checkForWin(int guess, int answer, guess_evaluation_t& result)
	{
		cout << "You guessed " << guess << ".";
		if (answer == guess)
		{
			cout << "You're Right! You Win!\n";
			result = CORRECT;
			return true;
		}
		else if (answer < guess)
		{
			cout << "Your guess is too high\n";
			result = TOO_HIGH;
		}
		else
		{
			cout << "Your guess is too low\n";
			result = TOO_LOW;
		}
		return false;
	}
	
	void play(Player &player1, Player &player2)
	{
		player1.reset();
		player2.reset();
		
		int answer = 0, guess = 0;
		answer = rand() % 100;
		bool win = false;
		guess_evaluation_t result;
		while (!win)
		{
			cout << player1.get_name() << "'s turn to guess.\n";
			guess = player1.getGuess();
			win = checkForWin(guess, answer, result);
			if (win)
			{
				player1.win();
				return;
			}
			player1.update_history(guess, result);
			player2.update_history(guess, result);
			
			cout << "\n" << player2.get_name() << "'s turn to guess.\n";
			guess = player2.getGuess();
			win = checkForWin(guess, answer, result);
			if (win)
			{
				player2.win();
				return;
			}
			player1.update_history(guess, result);
			player2.update_history(guess, result);
			
			cout << "**************************************\n";
		}
	}
}
