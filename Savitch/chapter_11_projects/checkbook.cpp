#include <checkbook.hpp>
#include <string>
using namespace std;

Check::Check() : number(0), amount(Money()), cashed(false) 
{
	//empty
}

Check::Check(const Check& copy) : number(copy.number), cashed(copy.cashed)
{
	amount = copy.amount; 
}

Check::Check(int number_arg, Money amount_arg, bool cashed_arg) : number(number_arg), amount(amount_arg), cashed(cashed_arg)
{
	//empty	
}

Check::~Check()
{
	//empty
}

int Check::get_number()
{
	return number;
}
	
Money Check::get_amount()
{
	return amount;
}
	
bool Check::get_cashed()
{
	return cashed;
}

ostream& operator <<(ostream& out_stream, const Check& right)
{
	out_stream << "------------------------------\nCheck info:\nNumber: " << right.number << "\nAmount: " << right.amount << "\nCashed: ";
	if (right.cashed)
	{
		out_stream << "true\n";
	}
	else
	{
		out_stream << "false\n";
	}
	out_stream << "------------------------------\n";
	return out_stream;
}

Check get_check_info_from_user()
{
	Check ret;
	cout << "-------------------------------\n";
	string check_number_input;
	while (1)
	{
		cout << "Enter the number of the check: ";
		cin >> check_number_input;
		if (!is_valid_integer(check_number_input))
		{
			cout << "\nbad input for check number\n";
			cin.clear();
			cin.ignore(10000, '\n');
			continue;
		}
		ret.number = stoi(check_number_input);
		cin.clear();
		cin.ignore(10000, '\n');
		break;
	}
	cout << ret.number << "\n";
	
	while (1)
	{
		cout << "Enter the amount of the check as in $100.00: ";
		try
		{
			cin >> ret.amount;
		}
		catch (money_error_t e)
		{
			cout << "could not input money amount\n";
			cin.clear();
			cin.ignore(10000, '\n');
			continue;
		}
		break;	
	}
	cout << ret.amount << "\n";
	
	char c;
	while (1)
	{
		cout << "Was the check cashed?(y/n): ";
		cin >> c;
		if (c == 'y' || c == 'Y')
		{
			ret.cashed = true;
			cout << "was cashed\n";
			break;
		}
		else if (c == 'n' || c == 'N')
		{
			ret.cashed = false;
			cout << "not cashed\n";
			break;
		}
	}
	cout << "-------------------------------\n";
	return ret;
}

bool is_valid_integer(const string& test_string)
{
	int length = test_string.length();
	for (int i=0; i<length; i++)
	{
		if (!isdigit(test_string[i]))
		{
			return false;
		}
	}
	return true;
}

void resize_check_array(Check* array_ptr, int num_checks, int new_array_size)
{
	Check* temp = new Check[new_array_size];
	int max_index = min(num_checks, new_array_size);
	
	for (int i=0; i<max_index; i++)
	{
		temp[i] = array_ptr[i];
	}
	
	delete [] array_ptr;
	array_ptr = temp;
}

Check& Check::operator =(const Check& copy)
{
	this->number = copy.number;
	this->amount = copy.amount;
	this->cashed = copy.cashed;
}

Money get_deposit_from_user()
{
	Money ret;
	while (1)
	{
		cout << "Enter the amount of the deposit (ex: $100.00): ";
		try
		{
			cin >> ret;
		}
		catch (money_error_t e)
		{
			cout << "could not input deposit amount\n";
			cin.clear();
			cin.ignore(10000, '\n');
			continue;
		}
		break;	
	}
	cout << ret << "\n";
	return ret;
}

void resize_money_array(Money* array_ptr, int num_amounts, int new_array_size)
{
	Money* temp = new Money[new_array_size];
	int max_index = min(num_amounts, new_array_size);
	
	for (int i=0; i<max_index; i++)
	{
		temp[i] = array_ptr[i];
	}
	
	delete [] array_ptr;
	array_ptr = temp;	
}

void balance_checkbook()
{
	// first input the cheques
	int max_written_checks = 5;
	Check* written_checks = new Check[max_written_checks];
	int num_written_checks = 0;
	char c;
	cout << "Have you written checks since the last time balancing your checkbook?(y/n): ";
	cin >> c;
	
	if (c == 'y' || c == 'Y')
	{
		while(1)
		{
			Check temp = get_check_info_from_user();
			written_checks[num_written_checks] = temp;
			num_written_checks++;
			
			if (num_written_checks >= max_written_checks - 1)
			{
				max_written_checks = max_written_checks*2;
				resize_check_array(written_checks, num_written_checks, max_written_checks);
			}
			
			cout << "Input another check?(y/n): ";
			cin >> c;
			if (c == 'y' || c == 'Y')
			{
				continue;
			}
			else
			{
				break;
			}
		}
		cout << "Got all the checks, here they are\n";
		for (int i=0; i<num_written_checks; i++)
		{
			cout << written_checks[i] << "\n";
		}		
	}
	
	int max_deposits = 5;
	Money* deposits = new Money[max_deposits];
	int num_deposits = 0;
	
	cout << "have you made deposits since the last time balancing your checkbook?(y/n): ";
	cin >> c;
	
	if (c == 'y' || c == 'Y')
	{
		while(1)
		{
			Money temp = get_deposit_from_user();
			deposits[num_deposits] = temp;
			num_deposits++;
			
			if (num_deposits >= max_deposits - 1)
			{
				max_deposits = max_deposits*2;
				resize_money_array(deposits, num_deposits, max_deposits);
			}
			
			cout << "Another deposit?(y/n): ";
			cin >> c;
			if (c == 'y' || c == 'Y')
			{
				continue;
			}
			else
			{
				break;
			}
		}
		cout << "Got all the deposits, here they are\n";
		for (int i=0; i<num_deposits; i++)
		{
			cout << deposits[i] << "\n";
		}
	}
	
	Money prev_balance;
	while (1)
	{
		cout << "Enter your account balance when you last balanced your checkbook (ex: $100.00): ";
		try
		{
			cin >> prev_balance;
		}
		catch (money_error_t e)
		{
			cout << "could not input balance\n";
			cin.clear();
			cin.ignore(10000, '\n');
			continue;
		}
		break;	
	}
	
	Money current_balance;
	while (1)
	{
		cout << "What does your bank report as your current balance? (ex: $100.00): ";
		try
		{
			cin >> current_balance;
		}
		catch (money_error_t e)
		{
			cout << "could not input balance\n";
			cin.clear();
			cin.ignore(10000, '\n');
			continue;
		}
		break;	
	}
	
	//add up the checks and the deposits
	Money cashed_check_total;
	Money uncashed_check_total;
	Money deposits_total;
	
	for (int i=0; i<num_written_checks; i++)
	{
		if (written_checks[i].get_cashed())
		{
			cashed_check_total = cashed_check_total + written_checks[i].get_amount();
		}
		else
		{
			uncashed_check_total = uncashed_check_total + written_checks[i].get_amount();
		}
	}
	for (int i=0; i<num_deposits; i++)
	{
		deposits_total = deposits_total + deposits[i];
	}
	
	cout << "Previous balance: " << prev_balance << "\n";
	cout << "Total of cashed checks: " << cashed_check_total << "\n";
	cout << "Total of un-cashed checks: " << uncashed_check_total << "\n";
	cout << "Deposits to your account: " << deposits_total << "\n";
	Money calculated_balance;
	calculated_balance = prev_balance + deposits_total - cashed_check_total;
	cout << "Your new balance should be " << calculated_balance << "\n";
	cout << "According to the bank your balance is " <<  current_balance << "\n";
}
