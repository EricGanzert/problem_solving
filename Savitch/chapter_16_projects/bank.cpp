#include <bank.hpp>
using namespace std;

namespace bank_eric
{
	Account::Account() : balance(0)
	{
		//empty
	}
	
	Account::Account(double initial_deposit) : balance(initial_deposit)
	{
		//empty
	}
	
	double Account::getBalance()
	{
		return balance;
	}
	
	double Account::deposit(double amount) throw(InvalidDeposit)
	{
		if (amount > 0)
		{
			balance += amount;
		}
		else
		{
			throw InvalidDeposit();
		}
		return balance;
	}

	double Account::withdraw(double amount) throw(InsufficientFunds)
	{
		if ((amount > balance || amount < 0))
		{
			throw InsufficientFunds();
		}
		else
		{
			balance -= amount;
		}
		return balance;
	}
}
