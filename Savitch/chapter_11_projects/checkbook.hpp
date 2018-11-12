#ifndef CHECKBOOK_H
#define CHECKBOOK_H

#include <money.hpp>
#include <string>

bool is_valid_integer(const std::string& test_string);

// Reads in info for checks that you have written.
// Somehow you will know if that check has been cashed or deposited into the account of
// the person you gave it to. Also reads in deposits to your account, 
// your account balance at the last time you balanced your checkbook, and what the bank says your balance is now.

// The following is output at the end of the program:
// total of the checks cashed
// total of deposits
// what new balance should be, compared to what bank says
// lists the checks cashed and not cashed. sorted from lowest amount to highest
void balance_checkbook();

class Check {
public:
	Check();
	Check(const Check& copy);
	Check(int number_arg, Money amount_arg, bool cashed_arg);
	~Check();
	
	Check& operator =(const Check& copy);
	
	friend std::ostream& operator <<(std::ostream& out_stream, const Check& right);
	
	//uses std::cin to ask the user about all the info needed to create a Check object
	friend Check get_check_info_from_user();
	
	friend void resize_check_array(Check* array_ptr, int num_checks, int new_array_size);
	
	int get_number();
	
	Money get_amount();
	
	bool get_cashed();
	
private:
	int number;
	Money amount;
	bool cashed;
};

//uses std::cin to get deposit info from user
Money get_deposit_from_user();

void resize_money_array(Money* array_ptr, int num_amounts, int new_array_size);

#endif //CHECKBOOK_H
