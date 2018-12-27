#include <bankAccount.hpp>
#include <iostream>
using namespace std;

namespace bank_eric
{
	BankAccount::BankAccount() : name("no name yet"), balance(0)
	{
		//empty
	}
	
	BankAccount::BankAccount(std::string the_name, double the_balance)
		: name(the_name), balance(the_balance)
	{
		//empty
	}
	
	BankAccount::BankAccount(const BankAccount& copy) : name(copy.name), balance(copy.balance)
	{
		//empty
	}
	
	BankAccount& BankAccount::operator =(const BankAccount& right)
	{
		name = right.name;
		balance = right.balance;
		return *this;
	}
	
	void BankAccount::deposit(double amount)
	{
		balance += amount;
	}
	
	double BankAccount::withdraw(double amount)
	{
		if (amount < 0)
		{
			cout << "Error: withdraw negative amount\n";
		}
		else if (amount > balance)
		{
			cout << "Warning: account overdrawn\n";
		}
		
		balance -= amount;
		return amount;
	}
	
	std::string BankAccount::get_name()
	{
		return name;
	}
	
	double BankAccount::get_balance()
	{
		return balance;
	}
	
	void transfer(double amount, BankAccount& from, BankAccount& to)
	{
		to.deposit(from.withdraw(amount));
	}
	
	MoneyMarketAccount::MoneyMarketAccount() : BankAccount(), num_withdrawals(0)
	{
		//empty
	}
	
	MoneyMarketAccount::MoneyMarketAccount(std::string the_name, double the_balance)
		: BankAccount(the_name, the_balance), num_withdrawals(0)
	{
		//empty
	}
	
	MoneyMarketAccount::MoneyMarketAccount(const MoneyMarketAccount& copy)
		: BankAccount(copy), num_withdrawals(copy.num_withdrawals)
	{
		//empty
	}
	
	MoneyMarketAccount& MoneyMarketAccount::operator =(const MoneyMarketAccount& right)
	{
		BankAccount::operator =(right);
		num_withdrawals = right.num_withdrawals;
		return *this;
	}
		
	double MoneyMarketAccount::withdraw(double amount)
	{
		if (amount < 0)
		{
			cout << "Error: withdraw negative amount\n";
		}
		
		num_withdrawals++;
		if (num_withdrawals > 2)
		{
			double total = amount + 1.50;
			if (total > balance)
			{
				cout << "Warning: Account overdrawn\n";
			}
			balance -= total;
		}
		else
		{
			balance -= amount;
		}
		return amount;
	}
	
	int MoneyMarketAccount::get_num_withdrawals()
	{
		return num_withdrawals;
	}
	
	CDAccount::CDAccount() : BankAccount(), interest_rate(0.1)
	{
		//empty
	}
	
	CDAccount::CDAccount(std::string the_name, double the_balance, double the_interest_rate)
		: BankAccount(the_name, the_balance), interest_rate(the_interest_rate)
	{
		//empty
	}
	
	CDAccount::CDAccount(const CDAccount& copy)
		: BankAccount(copy), interest_rate(copy.interest_rate)
	{
		//empty
	}
	
	CDAccount& CDAccount::operator =(const CDAccount& right)
	{
		BankAccount::operator =(right);
		interest_rate = right.interest_rate;
		return *this;
	}
		
	double CDAccount::withdraw(double amount)
	{
		double penalty = amount*interest_rate*0.25;
		double total = amount + penalty;
		if (amount < 0)
		{
			cout << "Error: withdraw negative amount\n";
		}
		else if (total > balance)
		{
			cout << "Warning: account overdrawn\n";
		}
		
		balance -= (amount + penalty);
		return amount;
	}
	
	double CDAccount::get_interest_rate()
	{
		return interest_rate;
	}
	
	void CDAccount::set_interest_rate(double new_interest_rate)
	{
		interest_rate = new_interest_rate;
	}
}
